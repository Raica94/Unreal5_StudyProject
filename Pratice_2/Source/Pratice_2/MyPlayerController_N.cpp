// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController_N.h"
#include "Pratice_2.h"


void AMyPlayerController_N::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ABLOG_S(Warning);

	IA_Move = nullptr;
	IA_Look = nullptr;
	IMC_Default = nullptr;
}

void AMyPlayerController_N::OnPossess(APawn* aPawn)
{
	ABLOG_S(Warning);
	Super::OnPossess(aPawn);

}

void AMyPlayerController_N::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystme = ULocalPlayer::GetSubsystem< UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (IMC_Default)
		{
			Subsystme->AddMappingContext(IMC_Default, 0);
		}
	}
}

void AMyPlayerController_N::SetupInputComponent()
{
	//Super::SetupInputComponent();
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{

	}
}

void AMyPlayerController_N::Move(const FInputActionValue& Value)
{
}

void AMyPlayerController_N::Look(const FInputActionValue& Value)
{
}
