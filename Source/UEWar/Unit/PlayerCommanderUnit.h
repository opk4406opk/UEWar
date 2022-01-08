// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameUnitBase.h"
#include "PlayerCommanderUnit.generated.h"

class USpringArmComponent;
class UInputComponent;
class ACameraActor;
class AInGamePlayerController;
/**
 * 
 */
UCLASS()
class UEWAR_API APlayerCommanderUnit final : public AGameUnitBase
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() final;
public:
	APlayerCommanderUnit();
	virtual void Tick(float DeltaTime) final;
	virtual ~APlayerCommanderUnit() final;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) final;
private:
	void OnPressedMoveForward(float axisValue);
	void OnPressedRight(float axisValue);
	void OnChangeAxisX(float axisValue);
	void OnChangeAxisY(float axisValue);
	void OnCameraZoom(float axisValue);
	void OnCameraRotation(float axisValue);
private:
	FVector CalcCameraDistance(const FVector& camLocation) const;
private:
	UPROPERTY(EditDefaultsOnly, Category="Player_Component")
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	UPROPERTY(EditDefaultsOnly, Category="PlayerCamera_Property")
	float CameraFOV = 50.0f;
	UPROPERTY(EditDefaultsOnly, Category="PlayerCamera_Property")
	FVector CameraInitOffset;
	UPROPERTY(EditDefaultsOnly, Category="PlayerCamera_Property")
	float CameraDistance = 0.0f;
	UPROPERTY(EditDefaultsOnly, Category="Player_Property")
	float MoveSpeed = 1.0f;
	UPROPERTY(Transient)
	TObjectPtr<ACameraActor> FollowCamera;
	UPROPERTY(Transient)
	TObjectPtr<AInGamePlayerController> PlayerController = nullptr;

	FVector2D InputAxis = FVector2D::ZeroVector;
	FVector InitCameraDistance = FVector::ZeroVector;
	FVector2D CameraAddOffset;

	FVector ForwardMove;
	FVector RightMove;
	///
	///
	float TValue = 0.0f;
};
