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
	MY_API UAIUtilitySystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	//~ Begin UAISystem Interface
	MY_API virtual void BeginDestroy() override;
	MY_API virtual void PostInitProperties() override;

	MY_API virtual void InitializeActorsForPlay(bool bTimeGotReset) override;
	MY_API virtual void WorldOriginLocationChanged(FIntVector OldOriginLocation, FIntVector NewOriginLocation) override;
	MY_API virtual void CleanupWorld(bool bSessionEnded = true, bool bCleanupResources = true) override;
	MY_API virtual void StartPlay() override;
	//~ End UAISystem Interface

	/** AI utility manager getter */
	FORCEINLINE class UAIUtilityManager* GetAIUtilityManager() { return AIUtilityManager; }
	/** AI utility manager const getter */
	FORCEINLINE const class UAIUtilityManager* GetAIUtilityManager() const { return AIUtilityManager; }

protected:
	/** Class that will be used to spawn the AI utility manager, can be game-specific */
	UPROPERTY(GlobalConfig, EditAnywhere, Category="AISystem", meta=(MetaClass="/Script/UtilityAI.AIUtilityManager", DisplayName="AIUtilityManager Class"))
	FSoftClassPath AIUtilityManagerClassName;

protected:
	/** AI utility manager instance */
	UPROPERTY(Transient)
	TObjectPtr<class UAIUtilityManager> AIUtilityManager;
};


#undef MY_API