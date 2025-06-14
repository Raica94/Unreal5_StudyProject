// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputLibrary.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "MyPlayerController_N.generated.h"


/**
 * 
 */
UCLASS()
class PRATICE_2_API AMyPlayerController_N : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void PostInitializeComponents() override;
	virtual void OnPossess(APawn* aPawn) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

private:
	UPROPERTY(EditAnywhere, Category = "Input");
	UInputAction* IA_Move;

	UPROPERTY(EditAnywhere, Category = "Input");
	UInputAction* IA_Look;

	UPROPERTY(EditAnywhere, Category = "Input");
	UInputMappingContext* IMC_Default;

};
