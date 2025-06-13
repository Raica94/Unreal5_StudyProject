// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestActor.h"

// Sets default values
AMyTestActor::AMyTestActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));

	ConstructorHelpers::FObjectFinder<UStaticMesh>
		SM_BODY(TEXT("/Game/StarterContent/Props/SM_Chair.SM_Chair"));

	if (SM_BODY.Succeeded())
	{
		Body->SetStaticMesh(SM_BODY.Object);
	}

	Part = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PART"));

	ConstructorHelpers::FObjectFinder<UStaticMesh>
		SM_PART(TEXT("/Game/StarterContent/Props/SM_TableRound.SM_TableRound"));

	if (SM_PART.Succeeded())
	{
		Part->SetStaticMesh(SM_PART.Object);
	}

	Part->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));

	Movement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("MOVEMENT"));



	RootComponent = Body;
	Part->SetupAttachment(Body);

	RotateSpeed = 30.0f;
	Movement->RotationRate = FRotator(0.0f, RotateSpeed, 0.0f);


}

// Called when the game starts or when spawned
void AMyTestActor::BeginPlay()
{
	Super::BeginPlay();

	FString TestLog = FString::Printf(TEXT("This is TEST LOG!!"));
	FVector Loc = this->GetActorLocation();
	UE_LOG(LogTemp, Log, TEXT("%s ,Actor Loc.x: %f"), *TestLog,Loc.X);

	UE_LOG(LogPractice_2, Warning, TEXT("This is TEST LOG!!"));
}

// Called every frame
void AMyTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0.0f, RotateSpeed * DeltaTime, 0.0f));
}

