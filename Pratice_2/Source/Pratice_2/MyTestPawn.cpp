// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestPawn.h"

// Sets default values
AMyTestPawn::AMyTestPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyTestPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTestPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTestPawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}

void AMyTestPawn::PossessedBy(AController* NewController)
{
	ABLOG_S(Warning);
	Super::PossessedBy(NewController);
}

// Called to bind functionality to input
void AMyTestPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

