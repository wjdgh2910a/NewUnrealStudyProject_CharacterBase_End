// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor/MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USceneComponent* MyRootComponent = CreateDefaultSubobject<USceneComponent>(FName(TEXT("RootComponent")));
	SetRootComponent(MyRootComponent);
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("StaticMesh")));
	MeshComp->SetupAttachment(GetRootComponent());
}

void AMyActor::Move()
{
}

void AMyActor::SetNextLocation()
{
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)	
{
	Super::Tick(DeltaTime);
	DrawDebugBox(GetWorld(), GetActorLocation(), FVector(20.f), FColor::Red);
	FVector ForwardVector = GetActorForwardVector();
	DrawDebugDirectionalArrow(GetWorld(), GetActorLocation(), 
		GetActorLocation() + ForwardVector * MoveSpeed, 10.0f, FColor::Blue);
	FRotator rotator(45.0, 0.0, 0.0);
	AddActorWorldRotation(rotator * DeltaTime);

	Scale += AddScale * DeltaTime;
	if (Scale > 2.0 || Scale < 1.0)
	{
		AddScale *= -1.0;
	}
	SetActorScale3D(FVector(Scale));
}

