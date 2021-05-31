// Fill out your copyright notice in the Description page of Project Settings.


#include "Light_Interacble.h"

ALight_Interacble::ALight_Interacble()
{
	State = true;
	Intensity = 100000.f;
	Light = CreateDefaultSubobject<USpotLightComponent>(TEXT("Light"));
	Light->SetupAttachment(GetRootComponent());
	Light->SetIntensity(Intensity);
}

void ALight_Interacble::Interact()
{
	if(State)
	{
		Light->SetIntensity(0);
	}
	else
	{
		Light->SetIntensity(Intensity);
	}
	State = !State;
}