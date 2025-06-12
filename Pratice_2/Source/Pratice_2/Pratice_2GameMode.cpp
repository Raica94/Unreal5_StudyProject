// Copyright Epic Games, Inc. All Rights Reserved.

#include "Pratice_2GameMode.h"
#include "Pratice_2Character.h"
#include "UObject/ConstructorHelpers.h"

APratice_2GameMode::APratice_2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
