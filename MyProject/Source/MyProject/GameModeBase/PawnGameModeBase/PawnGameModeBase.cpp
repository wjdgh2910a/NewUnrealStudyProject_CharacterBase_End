// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeBase/PawnGameModeBase/PawnGameModeBase.h"
#include "MyPawn/MyPawn.h"
#include "Controller/MyPawnController/MyPawnController.h"

APawnGameModeBase::APawnGameModeBase()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/MyPawn/BP_MyPawn.BP_MyPawn_C"));
	if (PlayerPawnBPClass.Succeeded())
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	PlayerControllerClass = AMyPawnController::StaticClass();

}
