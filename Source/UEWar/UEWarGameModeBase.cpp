// Copyright Epic Games, Inc. All Rights Reserved.


#include "UEWarGameModeBase.h"

#include "UWGameInstance.h"

UUWGameInstance* AUEWarGameModeBase::GetGameInstance()
{
	if(IsValid(CurGameInstance) == false)
	{
		CurGameInstance = Cast<UUWGameInstance>(GetWorld()->GetGameInstance());
	}
	return CurGameInstance;
}

const float AUEWarGameModeBase::GetFPS() const
{
	const float fps = 1.0f / GetWorld()->DeltaTimeSeconds;
	return fps;
}
