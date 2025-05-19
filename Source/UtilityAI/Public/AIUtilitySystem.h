// Author: Tom Werner (MajorT), 2025

#pragma once

#include "CoreMinimal.h"
#include "AISystem.h"
#include "AIUtilitySystem.generated.h"


#define MY_API UTILITYAI_API

/** AI system class that supports implementation of the utility plugin. */
UCLASS(Config=Engine, DefaultConfig, MinimalAPI)
class UAIUtilitySystem : public UAISystem
{
	GENERATED_BODY()

public:
	/*MY_API UAIUtilitySystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	//~ Begin UAISystem Interface
	MY_API virtual void PostInitProperties() override;
	MY_API virtual void CleanupWorld(bool bSessionEnded = true, bool bCleanupResources = true) override;
	//~ End UAISystem Interface

	/*
	/** Utility manager getter. #2#
	MY_API UAIUtilityManager* GetUtilityManager() { return UtilityManager; }
	/** Utility manager const getter. #2#
	MY_API const UAIUtilityManager* GetUtilityManager() const { return UtilityManager; }

protected:
	/** Class that will be used to spawn the utility system, can be game-specific #2#
	UPROPERTY(GlobalConfig, EditAnywhere, Category = "AISystem", meta=(MetaClass="/Script/UtilityAI.AIUtilityManager", DisplayName="Utility System Class"))
	FSoftClassPath UtilityManagerClassName;

protected:
	/** AI Utility manager used by game. #2#
	UPROPERTY(Transient)
	TObjectPtr<UAIUtilityManager> UtilityManager;#1#*/
};


#undef MY_API