// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"

#include "Pratice_2.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "GameFramework/Actor.h"
#include "MyTestActor.generated.h"

UCLASS()
class PRATICE_2_API AMyTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// �𸮾� �������� ������Ʈ�� ������ �ʱ�ȭ�� �� ȣ��Ǵ� �Լ�
	virtual void PostInitProperties() override;

	// ������ ������ �� ȣ��Ǵ� �Լ��� PostEditChangeProperty
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangeEvent) override;




	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent *Body;



	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent *Part;

	UPROPERTY(VisibleAnywhere)
	URotatingMovementComponent* Movement;

	UPROPERTY(EditAnywhere, Category=ID)
	int32 ID;

private:
	UPROPERTY(EditAnywhere,Category=Stat,Meta=(AllowPrivateAccess=true))
	float RotateSpeed;

};

//
//     UPROPERTY 
// �𸮾� �����Ϳ��� ���̸� ��� �۵��� �� �ִ��� ����
