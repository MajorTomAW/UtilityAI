// Author: Tom Werner (MajorT), 2025

#pragma once

#include "CoreMinimal.h"
#include "AISubsystem.h"
#include "UtilityAITypes.h"

#include "AIUtilityManager.generated.h"

#define MY_API UTILITYAI_API

/** Utility manager that handles registered AI Utility actions between listeners and sources. */
UCLASS(ClassGroup=AI, Config=Game, Defaultconfig, MinimalAPI)
class UAIUtilityManager : public UAISubsystem
{
	GENERATED_BODY()

public:
	MY_API UAIUtilityManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	static MY_API UAIUtilityManager* GetCurrent(UObject* WorldContextObject);
	static MY_API UAIUtilityManager* GetCurrent(UWorld& World);

	/** Returns the listener container. */
	FORCEINLINE AIUtility::FListenerMap& GetListeners() { return ListenerContainer; }
	
protected:
	/** List of all registered listeners. */
	AIUtility::FListenerMap ListenerContainer;
	
	/** Timestamp of the next utility aging. */
	double NextUtilityAgingTick;
	
private:
	/** Cached world's timestamp. */
	double CurrentTime;
};
#undef MY_API