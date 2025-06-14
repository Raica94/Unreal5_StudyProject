// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestPawn.h"



// Sets default values
AMyTestPawn::AMyTestPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CAPSULE"));
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MESH"));
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MOVEMENT"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));
	
	RootComponent = Capsule;
	Mesh->SetupAttachment(Capsule);
	SpringArm->SetupAttachment(Capsule);
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = true;

	Capsule->SetCapsuleHalfHeight(80.0f);
	Capsule->SetCapsuleRadius(34.0f);
	Mesh->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f),FRotator(0.0f,-90.0f,0.0f));

	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));


	SpringArm->bUsePawnControlRotation = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	//ACharacter::GetCharacterMovement()->bOrientRotationToMovement = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_TEST(TEXT("/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny"));
	if (SK_TEST.Succeeded())
	{
		Mesh->SetSkeletalMesh(SK_TEST.Object);
	}
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
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem< UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MyInputMapping, 0);
		}
	}

	if (UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(IA_T_Attack, ETriggerEvent::Triggered, this, &AMyTestPawn::TestAttack);
		Input->BindAction(IA_T_Move, ETriggerEvent::Triggered, this, &AMyTestPawn::TestMove);
		Input->BindAction(IA_T_Look, ETriggerEvent::Triggered, this, &AMyTestPawn::TestLook);
	}
}

void AMyTestPawn::TestAttack()
{
	ABLOG_S(Warning);
}

void AMyTestPawn::TestMove(const FInputActionValue& Value)
{
	const FVector2d MovementVector = Value.Get<FVector2d>();
	//const FRotator Rotation = this->GetControlRotation();
	//const FRotator YawRotation(0, Rotation, 0);
	//
	//const FVector FowardDirection = FRotationMatrix(YawRotation).GetUnitAxes(EAxis::X);
	//const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxes(EAxis::Y);

	//this-> CuttentActor

	if (Controller != nullptr)
	{
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
	ABLOG_S(Warning);
}

void AMyTestPawn::TestLook(const FInputActionValue& Value)
{
	FVector2D LookVector = Value.Get<FVector2D>();
	
	if (Controller != nullptr)
	{
		AddControllerYawInput(LookVector.X);
		AddControllerPitchInput(LookVector.Y);
	}

}

