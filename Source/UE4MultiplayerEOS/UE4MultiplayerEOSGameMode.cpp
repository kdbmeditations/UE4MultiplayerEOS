// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE4MultiplayerEOSGameMode.h"
#include "UE4MultiplayerEOSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE4MultiplayerEOSGameMode::AUE4MultiplayerEOSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
