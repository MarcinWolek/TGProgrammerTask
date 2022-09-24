// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/TGJumpComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Curves/CurveFloat.h"


void UTGJumpComponent::BeginPlay()
{
	Super::BeginPlay();

	TargetMeshComponent = Cast<UStaticMeshComponent>(GetOwner()->GetComponentByClass(UStaticMeshComponent::StaticClass()));

	if (JumpCurve)
	{
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindUFunction(this, FName(TEXT("JumpProcess")));
		JumpTimeline.AddInterpFloat(JumpCurve, TimelineProgress);
	}
}

void UTGJumpComponent::JumpProcess(float InProgress)
{
	if (!TargetMeshComponent)
		return;

	FVector NewVector = InProgress == 0 ?
		StartingPosition :
		FVector(StartingPosition.X, StartingPosition.Y, StartingPosition.Z + InProgress * JumpStrength);

	TargetMeshComponent->SetWorldLocation(NewVector);
	//TargetMeshComponent->SetRelativeLocation(NewVector);
}

void UTGJumpComponent::InvokeJump()
{
	NativePerformAssign();
}

void UTGJumpComponent::NativePerformAssign()
{
	StartingPosition = TargetMeshComponent->GetRelativeLocation();
	JumpTimeline.PlayFromStart();
	Execute_PerformAssign(this);
}

void UTGJumpComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	JumpTimeline.TickTimeline(DeltaTime);
}

void UTGJumpComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	Super::OnComponentDestroyed(bDestroyingHierarchy);
	JumpTimeline.Stop();
	JumpProcess(0.f);
}
