// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TGBasePawn.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBasePawnDelegate);


UCLASS()
class TGPROGRAMMERTASK_API ATGBasePawn : public APawn
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "BasePawn|Events")
	FBasePawnDelegate OnFinishAssigneProcessEvent;

	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "BasePawn|Events")
	FBasePawnDelegate OnFinishUnassigneProcessEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePawn|Variables")
	FVector MoveTarget;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BasePawn|BaseVariables")
	class UStaticMeshComponent* MainMeshComponent;

public:
	// Sets default values for this pawn's properties
	ATGBasePawn();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BasePawn|Functions")
	void PerformFinishAssigneProcess();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BasePawn|Functions")
	void PerformAssigned();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="BasePawn|Functions")
	void PerformUnassigned();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
