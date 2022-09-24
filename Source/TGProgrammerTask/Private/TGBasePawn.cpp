// Fill out your copyright notice in the Description page of Project Settings.


#include "TGBasePawn.h"

// Sets default values
ATGBasePawn::ATGBasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	MainMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("MainMesh")));
	SetRootComponent(MainMeshComponent);
}

void ATGBasePawn::PerformFinishAssigneProcess_Implementation()
{
	OnFinishAssigneProcessEvent.Broadcast();
}

void ATGBasePawn::PerformAssigned_Implementation()
{
	
}

void ATGBasePawn::PerformUnassigned_Implementation()
{
	OnFinishUnassigneProcessEvent.Broadcast();
	OnFinishAssigneProcessEvent.Clear();
	OnFinishUnassigneProcessEvent.Clear();
}

// Called when the game starts or when spawned
void ATGBasePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATGBasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

