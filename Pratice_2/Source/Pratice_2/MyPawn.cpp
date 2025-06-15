// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	OurVisibleCompoennt = CreateDefaultSubobject<USceneComponent>(TEXT("VisibleComponent"));
	OurVisibleCompoennt->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	{
		float CurrentScale = OurVisibleCompoennt->GetComponentScale().X;
		if (bGrowing)
		{
			CurrentScale += DeltaTime;
		}
		else
		{
			CurrentScale -= (DeltaTime * 0.5f);
		}
		CurrentScale = FMath::Clamp(CurrentScale, 1.0f, 2.0f);
		OurVisibleCompoennt->SetWorldScale3D(FVector(CurrentScale));
	}
	{
		if (!CurrentVelocity.IsZero())
		{
			FVector NewLocation = GetActorLocation() + (-CurrentVelocity * DeltaTime);
			SetActorLocation(NewLocation);
		}
	}


}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &AMyPawn::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyPawn::MoveRight);

	InputComponent->BindAction("Grow", EInputEvent::IE_Pressed, this, &AMyPawn::StartGrwoing);
	InputComponent->BindAction("Grow", EInputEvent::IE_Released, this, &AMyPawn::StopGrwoing);


}

void AMyPawn::MoveForward(float AxisValue)
{
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void AMyPawn::MoveRight(float AxisValue)
{
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void AMyPawn::StartGrwoing()
{
	bGrowing = true;
}

void AMyPawn::StopGrwoing()
{
	bGrowing = false;
}

