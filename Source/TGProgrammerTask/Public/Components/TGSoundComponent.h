// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/TGAssign.h"
#include "Interfaces/TGUnassign.h"
#include "Components/TGBaseComponent.h"
#include "TGSoundComponent.generated.h"

/**
 * 
 */
UCLASS()
class TGPROGRAMMERTASK_API UTGSoundComponent : public UTGBaseComponent, public ITGAssign, public ITGUnassign
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "TGSoundComponent|RefVariables")
	class UAudioComponent* AudioComponentRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TGSoundComponent|Variables")
	class USoundBase* SoundToPlay;

public:

	void NativePerformAssign() override;

	void NativePerformUnassign() override;

protected:

	void BeginPlay() override;

};
