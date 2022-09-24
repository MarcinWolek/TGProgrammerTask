// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/TGColorComponent.h"
#include "Materials/MaterialInterface.h"


void UTGColorComponent::BeginPlay()
{
	Super::BeginPlay();

	TargetMeshComponent = Cast<UStaticMeshComponent>(GetOwner()->GetComponentByClass(UStaticMeshComponent::StaticClass()));
	PreviousMaterial = TargetMeshComponent->GetMaterial(0);
}

void UTGColorComponent::NativePerformAssign()
{
	TargetMeshComponent->SetMaterial(0, NewMaterial);
	Execute_PerformAssign(this);
}

void UTGColorComponent::NativePerformUnassign()
{
	TargetMeshComponent->SetMaterial(0, PreviousMaterial);
	Execute_PerformUnassign(this);
}
