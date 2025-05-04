// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter/MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
#pragma region CreateComponent
	BodyComponent = GetMesh();
	HeadComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HeadComponent"));
	HeadComponent->SetupAttachment(BodyComponent);
	ArmComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ArmComponent"));
	ArmComponent->SetupAttachment(BodyComponent);
	LegComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("LegComponent"));
	LegComponent->SetupAttachment(BodyComponent);
	FootComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FootComponent"));
	FootComponent->SetupAttachment(BodyComponent);
	HairComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HairComponent"));
	HairComponent->SetupAttachment(HeadComponent);
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	SpringArm->bUsePawnControlRotation = true;
#pragma endregion
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

