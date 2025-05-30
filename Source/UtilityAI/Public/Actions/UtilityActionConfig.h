// Author: Tom Werner (MajorT), 2025

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UtilityAxis.h"
#include "DataProviders/AIDataProvider.h"

#include "UtilityActionConfig.generated.h"

#define MY_API UTILITYAI_API

class UUtilityActionBase;

/** Configuration struct for a single action. */
USTRUCT(BlueprintType)
struct FUtilityActionConfig
{
	GENERATED_BODY()

public:
	MY_API FUtilityActionConfig();
	MY_API virtual ~FUtilityActionConfig() = default;

	/** The display name of the action. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Config)
	FString DisplayName;

	/** Debug color to use for this action. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Config, AdvancedDisplay)
	FColor DebugColor;

	/** Gameplay tag used to identify this action. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Config, meta=(Categories="Utility.Action"))
	FGameplayTag GameplayTag;

	/** Tier of the additional weight coefficient that gets applied after any axis scoring. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Config, meta=(GetOptions="UtilityAI.AIUtilitySystem.GetPriorityGroupNames"))
	FName PrioritizationTier;

	/** The weight of this action. */
	UPROPERTY(EditAnywhere, Category = Config)
	FAIDataProviderFloatValue WeightValue;

	/** Coefficient applied to the final score for each repetition of this action.
	 * Values less than 1.0 will construct the rate on how strong the utility score of this action will decrease.
	 * Values greater than 1.0 will construct the rate on how strong the utility score of this action will increase. */
	UPROPERTY(EditAnywhere, Category = Config)
	FAIDataProviderFloatValue MarginalValue;

	/** Describes the rate on how fast the marginal value will tear off back to the base value. */
	UPROPERTY(EditAnywhere, Category = Config, meta=(Units=s))
	FAIDataProviderFloatValue MarginalTearOff;

	UPROPERTY(EditAnywhere, Category = Config, meta=(TitleProperty=DisplayName))
	TArray<FUtilityAxis> AxisComponents;

public:
	/** Returns the action implementation. */
	MY_API virtual TSubclassOf<UUtilityActionBase> GetActionImplementation() const;

	/** Returns the name of the action. */
	MY_API FString GetActionName() const;

protected:
	/** Name of the action. */
	mutable FString CachedActionName;
};

#undef MY_API