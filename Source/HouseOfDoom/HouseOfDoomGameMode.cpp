// Copyright Epic Games, Inc. All Rights Reserved.

#include "HouseOfDoomGameMode.h"
#include "HouseOfDoomCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHouseOfDoomGameMode::AHouseOfDoomGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
