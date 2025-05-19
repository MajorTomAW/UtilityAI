// Author: Tom Werner (MajorT), 2025

#pragma once

#include "CoreMinimal.h"
#include "AISubsystem.h"

#include "AIUtilitySystem.generated.h"

#define MY_API UTILITYAI_API

/**
 * AI Subsystem managin AI Utility through registered AI Utility Senses between Listeners and Sources
 */
UCLASS(ClassGroup=AI, Config=Game, DefaultConfig, MinimalAPI)
class UAIUtilitySystem : public UAISubsystem
{
	GENERATED_BODY()
	
public:
	MY_API UAIUtilitySystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	//~ Begin FTickableGameObject Interface
	MY_API virtual void Tick(float DeltaTime) override;
	MY_API virtual TStatId GetStatId() const override;
	//~ End FTickableGameObject Interface
};
#undef MY_API