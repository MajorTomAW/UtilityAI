// Author: Tom Werner (MajorT), 2025

#pragma once

#include "CoreMinimal.h"
#include "AISubsystem.h"
#include "AIUtilityTypes.h"

/*#include "AIUtilityManager.generated.h"

#define MY_API UTILITYAI_API

/**
 * AI Subsystem managing AI Utility through registered AI Utility Senses between Listeners and Sources
 #1#
UCLASS(ClassGroup=AI, Config=Game, DefaultConfig, MinimalAPI)
class UAIUtilityManager : public UAISubsystem
{
	GENERATED_BODY()
	
public:
	MY_API UAIUtilityManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
	static MY_API UAIUtilityManager* GetCurrent(UObject* WorldContextObject);
	static MY_API UAIUtilityManager* GetCurrent(UWorld& World);

	//~ Begin FTickableGameObject Interface
	MY_API virtual void Tick(float DeltaTime) override;
	MY_API virtual TStatId GetStatId() const override;
	//~ End FTickableGameObject Interface

protected:
	//UtilityAI::FListenerMap ListenerContainer;
	
	/** Timestamp of the next utility aging. #1#
	double NextUtilityAgingTick;

private:
	/** Cached world's timestamp. #1#
	double CurrentTime;
};
#undef MY_API*/