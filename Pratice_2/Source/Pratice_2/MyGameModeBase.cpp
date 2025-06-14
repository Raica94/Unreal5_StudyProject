// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyTestPawn.h"
#include "MyPlayerController_N.h"
#include "Pratice_2.h"
AMyGameModeBase::AMyGameModeBase()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/_My/MyTestPawn_BP.MyTestPawn_BP_C"));
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/_My/MyTestPawn_BP.MyTestPawn_BP_C"));

	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	else
	{
		DefaultPawnClass = AMyTestPawn::StaticClass();
	}
	//
	PlayerControllerClass = AMyPlayerController_N::StaticClass();
}

void AMyGameModeBase::PostLogin(APlayerController* newPlayer)
{
	ABLOG(Warning, TEXT("PostLogin Begin"));
	Super::PostLogin(newPlayer);
	ABLOG(Warning, TEXT("PostLogin End"));
}
