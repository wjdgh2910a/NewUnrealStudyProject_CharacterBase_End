// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn/Animation/MyPawnAnimInstance.h"
#include "MyPawn/MyPawn.h"
#include "GameFramework/FloatingPawnMovement.h"

void UMyPawnAnimInstance::NativeInitializeAnimation()
{
	OwnerPawn = Cast<AMyPawn>(TryGetPawnOwner());
	if (OwnerPawn)
	{
		MovementComponent = OwnerPawn->FindComponentByClass<UFloatingPawnMovement>();
	}
}

void UMyPawnAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (OwnerPawn)
	{
		isMove = MovementComponent->Velocity.Size() > 0.0f;
		PawnVelocity = MovementComponent->Velocity;
		PawnVelocity = OwnerPawn->GetActorTransform().InverseTransformVector(PawnVelocity);
	}
}
