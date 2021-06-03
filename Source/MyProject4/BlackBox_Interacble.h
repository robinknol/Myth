// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Master_Interacble.h"
#include "BlackBox_Interacble.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT4_API ABlackBox_Interacble : public AMaster_Interacble
{
	GENERATED_BODY()

public:
	virtual void Interact() override;

	UPROPERTY(EditAnywhere)
		FName LevelName;
	/*
	ABlackBox_Interacble();
	~ABlackBox_Interacble();
	*/
};
