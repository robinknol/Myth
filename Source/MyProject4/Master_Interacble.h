// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Builders/CurvedStairBuilder.h"
#include "Components/SceneComponent.h"
#include "Master_Interacble.generated.h"

UCLASS()
class MYPROJECT4_API AMaster_Interacble : public AActor
{
	GENERATED_BODY()
	
public:	
	AMaster_Interacble();
	/*
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	*/

public:	
	virtual void Interact() PURE_VIRTUAL(AMaster_Interacble::Interact, );
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		USceneComponent* _RootComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* Mesh;
};
