// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYPROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> MeshComp;
	UPROPERTY(EditAnywhere)
	float MoveSpeed{ 10.0f };
	UPROPERTY(EditAnywhere, Category = "Scale")
	float Scale{ 1.0f };
	UPROPERTY(EditAnywhere, Category = "Scale")
	float AddScale{ 1.0f };
public:	
	// Sets default values for this actor's properties
	AMyActor();
	void Move();
	void SetNextLocation();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
