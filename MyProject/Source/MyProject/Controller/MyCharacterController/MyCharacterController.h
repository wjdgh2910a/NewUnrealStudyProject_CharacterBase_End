// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyCharacterController.generated.h"

/**
 * 
 */
struct FInputActionValue;
UCLASS()
class MYPROJECT_API AMyCharacterController : public APlayerController
{
	GENERATED_BODY()
private:
#pragma region Input
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UInputAction> MoveAction;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UInputAction> LookAction;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UInputMappingContext> MappingContext;
#pragma endregion
	TObjectPtr<class AMyCharacter> ControlledCharacter;
public:
	AMyCharacterController();
	void BeginPlay() override;
	void SetupInputComponent() override;
	void MoveInput(const FInputActionValue& value);
	void LookInput(const FInputActionValue& value);
};
