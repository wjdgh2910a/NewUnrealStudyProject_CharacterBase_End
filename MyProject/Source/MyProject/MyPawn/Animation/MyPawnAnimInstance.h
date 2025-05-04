// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyPawnAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMyPawnAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class AMyPawn> OwnerPawn;
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UFloatingPawnMovement> MovementComponent;
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool isMove;
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FVector PawnVelocity;
public:
	void NativeInitializeAnimation() override;
	void NativeUpdateAnimation(float DeltaSeconds) override;
};
