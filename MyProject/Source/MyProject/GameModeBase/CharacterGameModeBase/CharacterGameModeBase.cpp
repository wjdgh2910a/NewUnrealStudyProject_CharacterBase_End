// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeBase/CharacterGameModeBase/CharacterGameModeBase.h"
#include "Controller/MyCharacterController/MyCharacterController.h"
#include "MyCharacter/MyCharacter.h"

ACharacterGameModeBase::ACharacterGameModeBase()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(
		TEXT("/Game/Blueprints/MyCharacter/BP_MyCharacter.BP_MyCharacter_C"));
	if (PlayerPawnBPClass.Succeeded())
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	PlayerControllerClass = AMyCharacterController::StaticClass();
}
