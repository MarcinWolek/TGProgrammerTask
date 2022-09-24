// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TGAssign.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTGAssign : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TGPROGRAMMERTASK_API ITGAssign
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "TGAssign|AssignFunction")
	void PerformAssign();

	UFUNCTION()
	virtual void NativePerformAssign() = 0;
};
