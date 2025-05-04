// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMyCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class AMyCharacter> OwnerCharacter;
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCharacterMovementComponent> MovementComponent;
public:
	void NativeInitializeAnimation() override;
	void NativeUpdateAnimation(float DeltaSeconds) override;
};
