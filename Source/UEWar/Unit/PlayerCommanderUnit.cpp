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
	FollowCamera->SetActorLocation(GetActorLocation() + FollowCamOffset);
	//////////////////////////////////////////////////////////////////////////////////

	const FRotator cameraRot = UKismetMathLibrary::FindLookAtRotation(FollowCamera->GetActorLocation(), GetActorLocation());
	FollowCamera->SetActorRotation(cameraRot);

	PlayerController = Cast<AInGamePlayerController>(GetWorld()->GetFirstPlayerController());
	PlayerController->SetViewTarget(Cast<AActor>(FollowCamera));
	
	PossessedBy(PlayerController);
	SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis(("Key_Up"), this, &APlayerCommanderUnit::OnPressedUpKey);
	InputComponent->BindAxis(("Key_Down"), this, &APlayerCommanderUnit::OnPressedDownKey);
	InputComponent->BindAxis(("Key_Left"),this, &APlayerCommanderUnit::OnPressedLeftKey);
	InputComponent->BindAxis(("Key_Right"), this, &APlayerCommanderUnit::OnPressedRightKey);

	InputComponent->BindAxis(("AxisMouseX"), this, &APlayerCommanderUnit::OnAxisX);
	InputComponent->BindAxis(("AxisMouseY"), this, &APlayerCommanderUnit::OnAxisY);
}

void APlayerCommanderUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// camera follow target.
	FollowCamera->SetActorLocation(GetActorLocation() + FollowCamOffset);
}

APlayerCommanderUnit::~APlayerCommanderUnit()
{
}

void APlayerCommanderUnit::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void APlayerCommanderUnit::OnPressedUpKey(float axisValue)
{
	if(axisValue <= 0.0f) {return;}

	const FVector dir = GetActorRotation().UnrotateVector(GetActorForwardVector());
	TArray<FStringFormatArg> formatArg;
	formatArg.Add(FString::SanitizeFloat(dir.X));
	formatArg.Add(FString::SanitizeFloat(dir.Y));
	formatArg.Add(FString::SanitizeFloat(dir.Z));
	UE_LOG(LogTemp, Log, TEXT("OnPressedUpKey:: dir : %s"), *FString::Format(TEXT("x : {0} y : {1} z : {2}"), formatArg));
	const FVector newPos = dir * axisValue * MoveSpeed + GetActorTransform().GetLocation();
	SetActorLocation(newPos);
	PlayAnimation(EGameUnitAnimType::Run);
}

void APlayerCommanderUnit::OnPressedDownKey(float axisValue)
{
	if(axisValue <= 0.0f) {return;}

	const FVector dir = GetActorRotation().UnrotateVector(GetActorForwardVector() * -1.0f);
	const FVector newPos = dir * axisValue * MoveSpeed + GetActorTransform().GetLocation();
	SetActorLocation(newPos);
	PlayAnimation(EGameUnitAnimType::Run);
}

void APlayerCommanderUnit::OnPressedLeftKey(float axisValue)
{
	if(axisValue <= 0.0f) {return;}

	const FVector dir = GetActorRotation().UnrotateVector(GetActorRightVector() * -1.0f);
	const FVector newPos = dir * axisValue * MoveSpeed + GetActorTransform().GetLocation();
	SetActorLocation(newPos);
	PlayAnimation(EGameUnitAnimType::Run);
}

void APlayerCommanderUnit::OnPressedRightKey(float axisValue)
{
	if(axisValue <= 0.0f) {return;}

	const FVector dir = GetActorRotation().UnrotateVector(GetActorRightVector());
	const FVector newPos = dir * axisValue * MoveSpeed + GetActorTransform().GetLocation();
	SetActorLocation(newPos);
	PlayAnimation(EGameUnitAnimType::Run);
}

void APlayerCommanderUnit::OnAxisX(float axisValue)
{
	if(axisValue <= 0.0f) {return;}	
}

void APlayerCommanderUnit::OnAxisY(float axisValue)
{
	if(axisValue <= 0.0f) {return;}
}