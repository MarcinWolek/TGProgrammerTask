// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/TGAssign.h"
#include "Components/TGBaseComponent.h"
#include "Components/TimelineComponent.h"
#include "TGJumpComponent.generated.h"

class UCurveFloat;



/**
 * 
 */
UCLASS()
class TGPROGRAMMERTASK_API UTGJumpComponent : public UTGBaseComponent, public ITGAssign
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="JumpComponent|RefVariables")
	class UStaticMeshComponent* TargetMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JumpComponent|Variables")
	UCurveFloat* JumpCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JumpComponent|Variables")
	float JumpStrength = 20.f;

	UPROPERTY()
	FTimeline JumpTimeline;

private:

	UPROPERTY()
	FVector StartingPosition;

public:

	UFUNCTION(BlueprintCallable, Category = "JumpComponent|Functions")
	void InvokeJump();

	void NativePerformAssign() override;

	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void OnComponentDestroyed(bool bDestroyingHierarchy) override;

protected:

	void BeginPlay() override;

	UFUNCTION(Category="JumpComponent|Functions")
	void JumpProcess(float InProgress);

};
