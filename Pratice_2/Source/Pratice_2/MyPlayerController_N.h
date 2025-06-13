// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
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
};
