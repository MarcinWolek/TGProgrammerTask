// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/TGSoundComponent.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundBase.h"


void UTGSoundComponent::BeginPlay()
{
	Super::BeginPlay();

	AudioComponentRef = NewObject<UAudioComponent>(GetOwner(), UAudioComponent::StaticClass());
	AudioComponentRef->RegisterComponent();
	AudioComponentRef->CreationMethod = EComponentCreationMethod::Instance;
	AudioComponentRef->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);

	AudioComponentRef->SetSound(SoundToPlay);
}

void UTGSoundComponent::NativePerformAssign()
{
	AudioComponentRef->Play();
	Execute_PerformAssign(this);
}

void UTGSoundComponent::NativePerformUnassign()
{
	AudioComponentRef->Stop();

	AudioComponentRef->UnregisterComponent();
	AudioComponentRef->DestroyComponent();

	Execute_PerformUnassign(this);
}
