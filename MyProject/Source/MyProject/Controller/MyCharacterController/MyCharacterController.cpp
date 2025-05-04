// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/MyCharacterController/MyCharacterController.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "MyCharacter/MyCharacter.h"

AMyCharacterController::AMyCharacterController()
{
	static ConstructorHelpers::FObjectFinder<UInputAction> MoveActionFinder(TEXT(
		"/Script/EnhancedInput.InputAction'/Game/Blueprints/MyCharacter/Input/IA_Move.IA_Move'"));
	if (MoveActionFinder.Succeeded())
	{
		MoveAction = MoveActionFinder.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction> LookActionFinder(TEXT(
		"/Script/EnhancedInput.InputAction'/Game/Blueprints/MyCharacter/Input/IA_Look.IA_Look'"));
	if (LookActionFinder.Succeeded())
	{
		LookAction = LookActionFinder.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> InputMappingContextFinder(TEXT(
		"/Script/EnhancedInput.InputMappingContext'/Game/Blueprints/MyCharacter/Input/IMC_Character.IMC_Character'"));
	if (InputMappingContextFinder.Succeeded())
	{
		MappingContext = InputMappingContextFinder.Object;
	}
}

void AMyCharacterController::BeginPlay()
{
	Super::BeginPlay();
	UEnhancedInputLocalPlayerSubsystem* InputSystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (InputSystem != nullptr)
	{
		InputSystem->AddMappingContext(MappingContext, 0);
	}
	ControlledCharacter = Cast<AMyCharacter>(GetPawn());
}

void AMyCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* input = Cast<UEnhancedInputComponent>(InputComponent);
	if (input != nullptr)
	{
		input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyCharacterController::MoveInput);
		input->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyCharacterController::LookInput);
	}
}

void AMyCharacterController::MoveInput(const FInputActionValue& value)
{
	FVector2D MoveValue = value.Get<FVector2D>();
	ControlledCharacter->AddMovementInput(ControlledCharacter->GetActorForwardVector(), MoveValue.X);
	ControlledCharacter->AddMovementInput(ControlledCharacter->GetActorRightVector(), MoveValue.Y);
}

void AMyCharacterController::LookInput(const FInputActionValue& value)
{
	FVector2D MoveValue = value.Get<FVector2D>();
	AddYawInput(MoveValue.X);
	AddPitchInput(MoveValue.Y);
}
