// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/TGAssign.h"
#include "Interfaces/TGUnassign.h"
#include "GameFramework/Actor.h"
#include "TGBaseBuilding.generated.h"


UCLASS(abstract)
class TGPROGRAMMERTASK_API ATGBaseBuilding : public AActor
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Building|BaseVariables")
	class UStaticMeshComponent* MainMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Building|BaseVariables")
	class UArrowComponent* InteractionPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Building|RefVariables")
	class ATGBasePawn* TargetPawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Building|Variables")
	TArray<TSubclassOf<UActorComponent>> AssignmenComponents;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Building|Variables")
	bool bCanUnassign = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Building|Variables")
	bool bTargetIsAssigned = false;

private:

	UPROPERTY()
	TArray<UActorComponent*> CurrentComponents;

	UPROPERTY()
	TArray<TScriptInterface<ITGAssign>> CurrentAssignInterfaces;

	UPROPERTY()
	TArray<TScriptInterface<ITGUnassign>> CurrentUnassignInterfaces;

public:	
	// Sets default values for this actor's properties
	ATGBaseBuilding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category="Building|Functions")
	void CallAssign();

	UFUNCTION(BlueprintCallable, Category = "Building|Functions")
	void CallUnassign();

	UFUNCTION()
	void FinishAssignProcess();

	UFUNCTION()
	void UnassignAndDestroyComponents();
};
