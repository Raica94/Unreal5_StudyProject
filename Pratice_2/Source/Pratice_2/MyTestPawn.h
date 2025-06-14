// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "Pratice_2.h"
#include "GameFramework/Pawn.h"
#include <EnhancedInputComponent.h>
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/Character.h"
#include "EnhancedInputSubsystems.h"

#include "MyTestPawn.generated.h"


UCLASS()
class PRATICE_2_API AMyTestPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyTestPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PostInitializeComponents() override;
	virtual void PossessedBy (AController* NewController) override;

	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputCompoenent) override;





	// �����̴� ��ü ���̷��� ( ���� �ִ� )
	// ���� ���� = ��Ÿƽ �޽�

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere,Category=Collision)
	UCapsuleComponent* Capsule;

	UPROPERTY(VisibleAnywhere, Category = Visual)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = Movement)
	UFloatingPawnMovement* Movement;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* SpringArm;					// ī�޶� �����̴� �۴��

	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* Camera;


protected:

	UPROPERTY(EditAnywhere,Category="EnhanceInput")
	class UInputMappingContext* MyInputMapping;


	UPROPERTY(EditAnywhere, Category = "EnhanceInput")
	class UInputAction* IA_T_Attack;
	UPROPERTY(EditAnywhere, Category = "EnhanceInput")
	class UInputAction* IA_T_Move;
	UPROPERTY(EditAnywhere, Category = "EnhanceInput")
	class UInputAction* IA_T_Look;

	void TestAttack();

	void TestMove(const FInputActionValue& Value);
	void TestLook(const FInputActionValue& Value);

};
