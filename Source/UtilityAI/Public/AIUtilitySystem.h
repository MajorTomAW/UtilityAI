// Author: Tom Werner (MajorT), 2025

#pragma once

#include "CoreMinimal.h"
#include "AISystem.h"
#include "Actions/UtilityResponseCurveConfig.h"
#include "StructUtils/InstancedStruct.h"

#include "AIUtilitySystem.generated.h"

class UAIUtilityManager;

#define MY_API UTILITYAI_API

/** AI system class that supports implementation of the utility plugin. */
UCLASS(Config=Engine, DefaultConfig, MinimalAPI)
class UAIUtilitySystem : public UAISystem
{
	GENERATED_BODY()

public:
	MY_API UAIUtilitySystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	/** Returns all priority group names. */
	UFUNCTION()
	static MY_API TArray<FName> GetPriorityGroupNames();

	/** Returns all curve type names. */
	UFUNCTION()
	static MY_API TArray<FName> GetCurveTypeNames();

	/** Returns this AI system from the world. */
	FORCEINLINE static UAIUtilitySystem* GetCurrent(UWorld& World)
	{
		return Cast<UAIUtilitySystem>(World.GetAISystem());
	}
	/** Returns this AI system from the world. */
	FORCEINLINE static UAIUtilitySystem* GetCurrentSafe(UWorld* World)
	{
		return IsValid(World) ? Cast<UAIUtilitySystem>(World->GetAISystem()) : nullptr;
	}

	//~ Begin UAISystem Interface
	MY_API virtual void BeginDestroy() override;
	MY_API virtual void PostInitProperties() override;

	MY_API virtual void InitializeActorsForPlay(bool bTimeGotReset) override;
	MY_API virtual void WorldOriginLocationChanged(FIntVector OldOriginLocation, FIntVector NewOriginLocation) override;
	MY_API virtual void CleanupWorld(bool bSessionEnded = true, bool bCleanupResources = true) override;
	MY_API virtual void StartPlay() override;
	//~ End UAISystem Interface

	/** AI utility manager getter */
	FORCEINLINE UAIUtilityManager* GetAIUtilityManager() { return AIUtilityManager; }
	/** AI utility manager const getter */
	FORCEINLINE const UAIUtilityManager* GetAIUtilityManager() const { return AIUtilityManager; }

protected:
	/** Class that will be used to spawn the AI utility manager, can be game-specific */
	UPROPERTY(GlobalConfig, EditAnywhere, Category="AISystem", meta=(MetaClass="/Script/UtilityAI.AIUtilityManager", DisplayName="AIUtilityManager Class"))
	FSoftClassPath AIUtilityManagerClassName;

	/** List of priority group names mapped to their corresponding priority values */
	UPROPERTY(Config, EditAnywhere, Category="Utility")
	TMap<FName, uint32> PriorityGroups;

	/** List of predefined equations for utility response scoring. */
	UPROPERTY(Config, EditAnywhere, Category="Utility", NoClear)
	TMap<FName, TInstancedStruct<FUtilityResponseCurveConfig>> ResponseCurves;

protected:
	/** AI utility manager instance */
	UPROPERTY(Transient)
	TObjectPtr<class UAIUtilityManager> AIUtilityManager;
};


#undef MY_API