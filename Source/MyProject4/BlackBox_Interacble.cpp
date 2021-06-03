// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackBox_Interacble.h"
#include "Kismet/GameplayStatics.h"
//#include "MyFPCharacter.h"


void ABlackBox_Interacble::Interact()
{
	/*
	if(!AMyFPCharacter::BlackBoxCollected)
	{
		AMyFPCharacter::BlackBoxCollected = true;
		this->Destroy();
	}
	else
	{*/
		UGameplayStatics::OpenLevel(this, LevelName);
	//}
}
