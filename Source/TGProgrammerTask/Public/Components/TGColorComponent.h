// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/TGAssign.h"
#include "Interfaces/TGUnassign.h"
#include "Components/TGBaseComponent.h"
#include "TGColorComponent.generated.h"


class UMaterialInterface;


/**
 * 
 */
UCLASS()
class TGPROGRAMMERTASK_API UTGColorComponent : public UTGBaseComponent, public ITGAssign, public ITGUnassign
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ColorComponent|RefVariables")
	class UStaticMeshComponent* TargetMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ColorComponent|RefVariables")
	class UMaterialInterface* PreviousMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ColorComponent|Variables")
	class UMaterialInterface* NewMaterial;


public:

	void NativePerformAssign() override;

	void NativePerformUnassign() override;

protected:

	void BeginPlay() override;

};
