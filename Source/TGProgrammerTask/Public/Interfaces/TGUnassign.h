// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TGUnassign.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTGUnassign : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TGPROGRAMMERTASK_API ITGUnassign
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "TGUnassign|UnassignFunction")
	void PerformUnassign();

	UFUNCTION()
	virtual void NativePerformUnassign() = 0;
};
