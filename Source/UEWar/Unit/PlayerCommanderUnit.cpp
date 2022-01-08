// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCommanderUnit.h"

#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "UEWar/Controller/InGamePlayerController.h"
#include "Runtime/Engine/Classes/Camera/CameraActor.h"

APlayerCommanderUnit::APlayerCommanderUnit()
{
	//InputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("InputComponent"));
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
}

void APlayerCommanderUnit::BeginPlay()
{
	Super::BeginPlay();

	// camera spawn and setting. ///////////////////////////////////////////////////////
	FollowCamera = Cast<ACameraActor>(GetWorld()->SpawnActor(ACameraActor::StaticClass()));
	FollowCamera->GetCameraComponent()->FieldOfView = CameraFOV;
#if WITH_EDITOR
	FollowCamera->SetActorLabel(FString("PlayerFollowCamera"));
#endif
	// init set offset.
	const FVector initCamLocation = GetActorLocation();
	InitCameraDistance = CalcCameraDistance(initCamLocation);
	FollowCamera->SetActorLocation(initCamLocation + InitCameraDistance);
	//////////////////////////////////////////////////////////////////////////////////

	const FRotator cameraRot = UKismetMathLibrary::FindLookAtRotation(FollowCamera->GetActorLocation(), GetActorLocation());
	FollowCamera->SetActorRotation(cameraRot);

	PlayerController = Cast<AInGamePlayerController>(GetWorld()->GetFirstPlayerController());
	PlayerController->SetViewTarget(Cast<AActor>(FollowCamera));
	
	PossessedBy(PlayerController);
	SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis(("MoveForward"), this, &APlayerCommanderUnit::OnPressedMoveForward);
	InputComponent->BindAxis(("MoveRight"), this, &APlayerCommanderUnit::OnPressedRight);

	InputComponent->BindAxis(("AxisX"), this, &APlayerCommanderUnit::OnChangeAxisX);
	InputComponent->BindAxis(("AxisY"), this, &APlayerCommanderUnit::OnChangeAxisY);
	InputComponent->BindAxis("CameraZoom", this, &APlayerCommanderUnit::OnCameraZoom);
	InputComponent->BindAxis("CameraRotation", this, &APlayerCommanderUnit::OnCameraRotation);
}

void APlayerCommanderUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TValue += DeltaTime * 60.0f;
	if(TValue >= 360.0f) TValue = 0.0f;

	// set player location and rotation.
	const FVector finalDir = ForwardMove + RightMove;
	const FVector newPlayerLoc = GetActorLocation() + finalDir;
	const FRotator newPlayerRot = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), newPlayerLoc);
	SetActorLocation(FMath::Lerp<FVector>(GetActorLocation(), newPlayerLoc, 0.5f));
	if(GetActorRotation() != newPlayerRot)
	{
		SetActorRotation(newPlayerRot);
	}
	// camera follow target.
	const FVector verticalValue = UKismetMathLibrary::RotateAngleAxis(GetActorLocation() / 20.0f, CameraAddOffset.X, GetActorUpVector());
	const FVector addOffset = FVector(0.0f, 0.0f, CameraAddOffset.Y);
	FVector newCamLoc = GetActorLocation() + addOffset + verticalValue;
	newCamLoc += CalcCameraDistance(newCamLoc);
	// set camera location and rotation.
	const FRotator lookRotation = UKismetMathLibrary::FindLookAtRotation(newCamLoc, GetActorLocation());
	FollowCamera->SetActorLocationAndRotation(newCamLoc, lookRotation);
}

APlayerCommanderUnit::~APlayerCommanderUnit()
{
}

void APlayerCommanderUnit::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void APlayerCommanderUnit::OnPressedMoveForward(float axisValue)
{
	const FVector originLoc = GetActorLocation();
	const FRotator originRot = GetActorRotation();
	
	FVector dir = GetActorRotation().UnrotateVector(GetActorForwardVector());
	const FVector camLookDir = FollowCamera->GetActorForwardVector().Rotation().RotateVector(dir);
	dir.X = camLookDir.X;
	dir.Y = camLookDir.Y;
	ForwardMove = dir * axisValue * MoveSpeed;
	
	//TArray<FStringFormatArg> formatArg;
	//formatArg.Add(FString::SanitizeFloat(axisValue));
	//UE_LOG(LogTemp, Log, TEXT("APlayerCommanderUnit::OnPressedMoveForward() axis : %s"), *FString::Format(TEXT("{0}"), formatArg));
	
}
void APlayerCommanderUnit::OnPressedRight(float axisValue)
{
	const FVector originLoc = GetActorLocation();
	const FRotator originRot = GetActorRotation();
	
	FVector dir = GetActorRotation().UnrotateVector(GetActorRightVector());
	const FVector camLookDir = FollowCamera->GetActorForwardVector().Rotation().RotateVector(dir);
	dir.X = camLookDir.X;
	dir.Y = camLookDir.Y;
	RightMove = dir * axisValue * MoveSpeed;
	
	// TArray<FStringFormatArg> formatArg;
	// formatArg.Add(FString::SanitizeFloat(LerpLocation.X));
	// formatArg.Add(FString::SanitizeFloat(LerpLocation.Y));
	// formatArg.Add(FString::SanitizeFloat(LerpLocation.Z));
	// UE_LOG(LogTemp, Log, TEXT("APlayerCommanderUnit::OnPressedRight() LerpLocation : %s"), *FString::Format(TEXT("x : {0}, y : {1}, z : {2}"), formatArg));
	//
}


void APlayerCommanderUnit::OnChangeAxisX(float axisValue)
{
	//if(axisValue == 0.0f) {return;}
	
	InputAxis.X = axisValue;
	
	//TArray<FStringFormatArg> formatArg;
	//formatArg.Add(FString::SanitizeFloat(axisValue));
	//UE_LOG(LogTemp, Log, TEXT("APlayerCommanderUnit::OnMouseAxisX() axis : %s"), *FString::Format(TEXT("{0}"), formatArg));
}

void APlayerCommanderUnit::OnChangeAxisY(float axisValue)
{
	//if(axisValue == 0.0f) {return;}
	
	InputAxis.Y = axisValue;

	//TArray<FStringFormatArg> formatArg;
	//formatArg.Add(FString::SanitizeFloat(axisValue));
	//UE_LOG(LogTemp, Log, TEXT("APlayerCommanderUnit::OnMouseAxisY() axis : %s"), *FString::Format(TEXT("{0}"), formatArg));
}

void APlayerCommanderUnit::OnCameraZoom(float axisValue)
{
	const float delta = 100.0f;
	CameraDistance += (delta * axisValue);
	
	// TArray<FStringFormatArg> formatArg;
	// formatArg.Add(FString::SanitizeFloat(axisValue));
	// formatArg.Add(FString::SanitizeFloat(CameraDistance));
	// UE_LOG(LogTemp, Log, TEXT("APlayerCommanderUnit::OnCameraZoom() [%s]"), *FString::Format(TEXT("axisValue : {0}, cameraDistance : {1}"), formatArg));
}

void APlayerCommanderUnit::OnCameraRotation(float axisValue)
{
	if(axisValue != 1.0f)
	{
		return;
	}

	constexpr float moveDelta = 5.0f;

	CameraAddOffset.X += InputAxis.X * moveDelta * -1.0f;
	if(FMath::Abs(CameraAddOffset.X) >= 360.0f)
	{
		CameraAddOffset.X = 0.0f;
	}
	CameraAddOffset.Y += InputAxis.Y * moveDelta * -1.0f;
	
	//TArray<FStringFormatArg> formatArg;
	//formatArg.Add(FString::SanitizeFloat(CameraAddOffset.X));
	//formatArg.Add(FString::SanitizeFloat(CameraAddOffset.Y));
	//UE_LOG(LogTemp, Log, TEXT("APlayerCommanderUnit::OnMouseRightBtn() CameraAddOffset : %s"), *FString::Format(TEXT("x : {0}, y : {1}"), formatArg));
}

FVector APlayerCommanderUnit::CalcCameraDistance(const FVector& camLocation) const
{
	const FVector dir = GetActorLocation() - camLocation;
	return dir.GetSafeNormal() * CameraDistance * -1.0f;
}

