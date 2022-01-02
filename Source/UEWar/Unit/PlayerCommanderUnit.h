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
	void OnPressedUpKey(float axisValue);
	void OnPressedDownKey(float axisValue);
	void OnPressedLeftKey(float axisValue);
	void OnPressedRightKey(float axisValue);
	void OnAxisX(float axisValue);
	void OnAxisY(float axisValue);
private:
	UPROPERTY(EditDefaultsOnly, Category="Player_Component")
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	UPROPERTY(EditDefaultsOnly, Category="Player_Property")
	float CameraFOV = 50.0f;
	UPROPERTY(EditDefaultsOnly, Category="Player_Property")
	FVector FollowCamOffset;
	UPROPERTY(EditDefaultsOnly, Category="Player_Property")
	float MoveSpeed = 1.0f;
	UPROPERTY(Transient)
	TObjectPtr<ACameraActor> FollowCamera;
	UPROPERTY(Transient)
	TObjectPtr<AInGamePlayerController> PlayerController = nullptr;
};
