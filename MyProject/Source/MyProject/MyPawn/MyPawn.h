#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/CapsuleComponent.h"
#include "MyPawn.generated.h"

UCLASS()
class MYPROJECT_API AMyPawn : public APawn
{
	GENERATED_BODY()
private:
#pragma region Component
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCapsuleComponent> CapsuleComp;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USkeletalMeshComponent> Mesh;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class USpringArmComponent> SpringArm;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UCameraComponent> Camera;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UFloatingPawnMovement> Movement;
#pragma endregion
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAnimMontage> AttackMontage;
public:
	AMyPawn();
protected:
	virtual void BeginPlay() override;
public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void PlayAttackMontage();
};
