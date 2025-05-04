// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn/Animation/Notify/SetMovable.h"

void USetMovable::Notify(USkeletalMeshComponent* MeshComp, 
	UAnimSequenceBase* Animation, 
	const FAnimNotifyEventReference& EventReference)
{
	if (MeshComp)
	{
		APawn* Owner = Cast<APawn>(MeshComp->GetOwner());
		if (Owner && Owner->GetController())
			Owner->GetController()->ResetIgnoreMoveInput();
	}
}
