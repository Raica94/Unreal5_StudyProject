// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController_N.h"
#include "Pratice_2.h"
void AMyPlayerController_N::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}

void AMyPlayerController_N::OnPossess(APawn* aPawn)
{
	ABLOG_S(Warning);
	Super::OnPossess(aPawn);

}
