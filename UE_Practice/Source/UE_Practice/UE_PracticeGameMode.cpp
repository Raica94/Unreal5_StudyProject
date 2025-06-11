// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE_PracticeGameMode.h"
#include "UE_PracticeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE_PracticeGameMode::AUE_PracticeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
