// Fill out your copyright notice in the Description page of Project Settings.


#include "TGBaseBuilding.h"
#include "TGBasePawn.h"
#include "Components/TGBaseComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"


// Sets default values
ATGBaseBuilding::ATGBaseBuilding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MainMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("MainMesh")));
	SetRootComponent(MainMeshComponent);

	InteractionPoint = CreateDefaultSubobject<UArrowComponent>(FName(TEXT("InteractionPoint")));
	InteractionPoint->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ATGBaseBuilding::BeginPlay()
{
	Super::BeginPlay();
	
	//Checking if Unassign can be invoked:
	for (int i = 0; i < AssignmenComponents.Num(); i++)
	{
		if (AssignmenComponents[i]->ImplementsInterface(UTGUnassign::StaticClass()))
		{
			bCanUnassign = true;
			break;
		}
	}
}

void ATGBaseBuilding::CallAssign()
{
	if (!bTargetIsAssigned)
	{
		TargetPawn->PerformUnassigned();

		CurrentAssignInterfaces.Empty(AssignmenComponents.Num());
		CurrentUnassignInterfaces.Empty(AssignmenComponents.Num());
		CurrentComponents.Empty(AssignmenComponents.Num());

		for (int i = 0; i < AssignmenComponents.Num(); i++)
		{
			UActorComponent* NewComponent = NewObject<UActorComponent>(TargetPawn, AssignmenComponents[i]);
			NewComponent->RegisterComponent();
			NewComponent->CreationMethod = EComponentCreationMethod::Instance;

			CurrentComponents.Emplace(NewComponent);

			TScriptInterface<ITGAssign> AssignInterface = NewComponent;

			if (AssignInterface)
			{
				CurrentAssignInterfaces.Emplace(AssignInterface);
			}

			TScriptInterface<ITGUnassign> UnassignInterface = NewComponent;

			if (UnassignInterface)
			{
				CurrentUnassignInterfaces.Emplace(UnassignInterface);
			}
		}

		TargetPawn->OnFinishAssigneProcessEvent.AddDynamic(this, &ATGBaseBuilding::FinishAssignProcess);
		TargetPawn->OnFinishUnassigneProcessEvent.AddDynamic(this, &ATGBaseBuilding::UnassignAndDestroyComponents);
	}

	TargetPawn->MoveTarget = InteractionPoint->GetComponentLocation();
	TargetPawn->PerformAssigned();

	bTargetIsAssigned = true;
}

void ATGBaseBuilding::FinishAssignProcess()
{
	for (int i = 0; i < CurrentAssignInterfaces.Num(); i++)
	{
		CurrentAssignInterfaces[i]->NativePerformAssign();
	}
}

void ATGBaseBuilding::CallUnassign()
{
	if (!bTargetIsAssigned)
		return;

	TargetPawn->PerformUnassigned();
}

void ATGBaseBuilding::UnassignAndDestroyComponents()
{
	if (!bTargetIsAssigned)
		return;

	if (bCanUnassign)
	{
		for (int i = 0; i < CurrentUnassignInterfaces.Num(); i++)
		{
			CurrentUnassignInterfaces[i]->NativePerformUnassign();
		}
	}

	for (int i = 0; i < CurrentComponents.Num(); i++)
	{
		CurrentComponents[i]->UnregisterComponent();
		CurrentComponents[i]->DestroyComponent();
	}

	//TargetPawn->PerformUnassigned();

	bTargetIsAssigned = false;
}