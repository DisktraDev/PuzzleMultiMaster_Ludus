// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "PuzzleMultiMaster_V1GameMode.h"
#include "PuzzleMultiMaster_V1Character.h"
#include "UObject/ConstructorHelpers.h"

APuzzleMultiMaster_V1GameMode::APuzzleMultiMaster_V1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
