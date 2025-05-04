// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter/Animation/MyCharacterAnimInstance.h"
#include "MyCharacter/MyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UMyCharacterAnimInstance::NativeInitializeAnimation()
{
	OwnerCharacter = Cast<AMyCharacter>(TryGetPawnOwner());
	if (OwnerCharacter)
	{
		MovementComponent = OwnerCharacter->FindComponentByClass<UCharacterMovementComponent>();
	}
}

void UMyCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{

}
