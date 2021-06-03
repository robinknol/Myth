// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFPCharacter.h"
#include "Camera/CameraComponent.h"
#include "Master_Interacble.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyFPCharacter::AMyFPCharacter()
{
	BlackBoxCollected = true;
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;

	cam = CreateAbstractDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	cam->AttachTo(RootComponent);
	cam->SetRelativeLocation(FVector(0, 0, 40));

	jumping = false;

	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));
}

// Called when the game starts or when spawned
void AMyFPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyFPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (jumping)
	{
		Jump();
	}

}

// Called to bind functionality to input
void AMyFPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Hori", this, &AMyFPCharacter::HoriMove);
	InputComponent->BindAxis("Vert", this, &AMyFPCharacter::VertMove);

	InputComponent->BindAxis("HoriRot", this, &AMyFPCharacter::HoriRot);
	InputComponent->BindAxis("VertRot", this, &AMyFPCharacter::VertRot);

	InputComponent->BindAction("Jump", IE_Pressed, this, &AMyFPCharacter::CheckJump);
	InputComponent->BindAction("Jump", IE_Released, this, &AMyFPCharacter::CheckJump);
	
	InputComponent->BindAction("Interact", IE_Pressed, this, &AMyFPCharacter::Interactable);
}

void AMyFPCharacter::Interactable()
{
	UWorld* World = GetWorld();
	if (!IsValid(World)) return;
	
	APlayerCameraManager* PlayerCameraManager= UGameplayStatics::GetPlayerCameraManager(World, 0);
	if (!IsValid(PlayerCameraManager)) return;

	FVector CameraLocation = PlayerCameraManager->GetCameraLocation();
	
	End = CameraLocation + PlayerCameraManager->GetActorForwardVector() * 300;

	if(GetWorld()->LineTraceSingleByChannel(OutHit, CameraLocation, End, ECC_Visibility))
	{
		AMaster_Interacble* Obj = Cast<AMaster_Interacble>(OutHit.Actor);
		if (Obj)
		{
			Obj->Interact();
		}
	}
	
}

void AMyFPCharacter::CheckJump()
{
	if (jumping)
	{
		jumping = false;
	}
	else
	{
		jumping = true;
	}
		
}

void AMyFPCharacter::HoriMove(float value)
{
	if (value)
	{
		AddMovementInput(GetActorRightVector(), value);
	}
}

void AMyFPCharacter::VertMove(float value)
{
	if (value)
	{
		AddMovementInput(GetActorForwardVector(), value);
	}
}

void AMyFPCharacter::HoriRot(float value)
{
	if (value)
	{
		AddActorLocalRotation(FRotator(0, value, 0));
	}
}

void AMyFPCharacter::VertRot(float value)
{
	if (value)
	{
		float temp = cam->GetRelativeRotation().Pitch + value;

		if (temp < 65 && temp > -65)
		{
			cam->AddLocalRotation(FRotator(value, 0, 0));
		}
	}
}
