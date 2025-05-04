#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPawnController.generated.h"

struct FInputActionValue;
UCLASS()
class MYPROJECT_API AMyPawnController : public APlayerController
{
	GENERATED_BODY()
#pragma region Private
private:
#pragma region Input
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UInputAction> MoveAction;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UInputAction> RotationAction;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UInputAction> AttackAction;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UInputMappingContext> MappingContext;
#pragma endregion
	TObjectPtr<class AMyPawn> ControlledPawn;
#pragma endregion
public:
	AMyPawnController();
	void BeginPlay() override;
	void SetupInputComponent() override;
	void MoveInput(const FInputActionValue& value);
	void LookInput(const FInputActionValue& value);
	void AttackInput(const FInputActionValue& value);
};
