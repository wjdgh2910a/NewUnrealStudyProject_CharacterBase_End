// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/MyPawnController/MyPawnController.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include  "MyPawn/MyPawn.h"

AMyPawnController::AMyPawnController()
{
#pragma region Input
	static ConstructorHelpers::FObjectFinder<UInputAction> MoveActionFinder(TEXT(
		"/Script/EnhancedInput.InputAction'/Game/Blueprints/MyPawn/Input/IA_Move.IA_Move'"));
	if (MoveActionFinder.Succeeded())
	{
		MoveAction = MoveActionFinder.Object;
	}	
	static ConstructorHelpers::FObjectFinder<UInputAction> RotationActionFinder(TEXT(
		"/Script/EnhancedInput.InputAction'/Game/Blueprints/MyPawn/Input/IA_Rotation.IA_Rotation'"));
	if (RotationActionFinder.Succeeded())
	{
		RotationAction = RotationActionFinder.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction> AttackActionFinder(TEXT(
		"/Script/EnhancedInput.InputAction'/Game/Blueprints/MyPawn/Input/IA_Attack.IA_Attack'"));
	if (AttackActionFinder.Succeeded())
	{
		AttackAction = AttackActionFinder.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> InputMappingContextFinder(TEXT(
		"/Script/EnhancedInput.InputMappingContext'/Game/Blueprints/MyPawn/Input/IMC_Pawn.IMC_Pawn'"));
	if (InputMappingContextFinder.Succeeded())
	{
		MappingContext = InputMappingContextFinder.Object;
	}
#pragma endregion
}

void AMyPawnController::BeginPlay()
{
	Super::BeginPlay();
	UEnhancedInputLocalPlayerSubsystem* InputSystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (InputSystem != nullptr)
	{
		InputSystem->AddMappingContext(MappingContext, 0);
	}
	ControlledPawn = Cast<AMyPawn>(GetPawn());
}

void AMyPawnController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* input = Cast<UEnhancedInputComponent>(InputComponent);
	if (input != nullptr)
	{
		input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyPawnController::MoveInput);
		input->BindAction(RotationAction, ETriggerEvent::Triggered, this, &AMyPawnController::LookInput);
		input->BindAction(AttackAction, ETriggerEvent::Started, this, &AMyPawnController::AttackInput);
	}	
}

void AMyPawnController::MoveInput(const FInputActionValue& value)
{
	FVector2D MoveValue = value.Get<FVector2D>();
	ControlledPawn->AddMovementInput(ControlledPawn->GetActorForwardVector(),MoveValue.X);
	ControlledPawn->AddMovementInput(ControlledPawn->GetActorRightVector(), MoveValue.Y);
}

void AMyPawnController::LookInput(const FInputActionValue& value)
{
	FVector2D MoveValue = value.Get<FVector2D>();
	AddYawInput(MoveValue.X);
	AddPitchInput(MoveValue.Y);
}

void AMyPawnController::AttackInput(const FInputActionValue& value)
{
	ControlledPawn->PlayAttackMontage();
}
