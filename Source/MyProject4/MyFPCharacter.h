// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "MyFPCharacter.generated.h"

UCLASS()
class MYPROJECT4_API AMyFPCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* Mesh1P;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY()
		FVector Start;

	UPROPERTY()
		FVector End;

	UPROPERTY()
		FHitResult OutHit;
public:
	// Sets default values for this character's properties
	AMyFPCharacter();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }

	bool BlackBoxCollected;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Interactable();
private:
	void HoriMove(float value);
	void VertMove(float value);

	void HoriRot(float value);
	void VertRot(float value);

	void CheckJump();

	UPROPERTY()
		bool jumping;

	UPROPERTY(EditAnywhere, Category = "Camera")
		UCameraComponent* cam;

};
