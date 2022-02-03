// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameUnitBase.h"
#include "MeleeUnit.generated.h"

class AGameUnitBase;

UCLASS()
class UEWAR_API AMeleeUnit : public AGameUnitBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMeleeUnit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual ~AMeleeUnit() override;
	virtual void PlayAnimation(EGameUnitAnimType animType) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
