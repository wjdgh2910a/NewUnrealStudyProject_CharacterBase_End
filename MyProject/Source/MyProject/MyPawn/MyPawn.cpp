// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn/MyPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h" 

AMyPawn::AMyPawn()
{
 	PrimaryActorTick.bCanEverTick = true;
#pragma region Component
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RootComponent"));
	SetRootComponent(CapsuleComp);
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("PawnMovement"));
#pragma endregion

	static ConstructorHelpers::FObjectFinder<UAnimMontage> AttackMontageFinder(TEXT(
		"/Script/Engine.AnimMontage'/Game/Blueprints/MyPawn/Animation/AM_Attack.AM_Attack'"));
	if (AttackMontageFinder.Succeeded())
	{
		AttackMontage = AttackMontageFinder.Object;
	}
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyPawn::PlayAttackMontage()
{
	if (nullptr != AttackMontage &&
		Mesh->GetAnimInstance()->Montage_IsPlaying(AttackMontage) == false)
	{
		Controller->SetIgnoreMoveInput(true);
		Mesh->GetAnimInstance()->Montage_Play(AttackMontage);
	}
}

