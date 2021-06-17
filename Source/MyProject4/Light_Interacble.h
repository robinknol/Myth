// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Master_Interacble.h"
#include "Components/SpotLightComponent.h"
#include "Light_Interacble.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT4_API ALight_Interacble : public AMaster_Interacble
{
	GENERATED_BODY()

public:
	virtual void Interact() override;
	
	UPROPERTY()
	bool State;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Intensity;

	UPROPERTY(EditAnywhere)
	USpotLightComponent* Light;

	ALight_Interacble();
};
