// Fill out your copyright notice in the Description page of Project Settings.


#include "Master_Interacble.h"

// Sets default values
AMaster_Interacble::AMaster_Interacble()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = _RootComponent;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}


// Called when the game starts or when spawned
void AMaster_Interacble::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMaster_Interacble::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}