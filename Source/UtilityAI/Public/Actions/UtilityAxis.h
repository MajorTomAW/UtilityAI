// Author: Tom Werner (MajorT), 2025

#pragma once
#include "StructUtils/InstancedStruct.h"

#include "UtilityAxis.generated.h"

struct FAIDataProviderValue;
struct FAIDataProviderTypedValue;

/** Configuration for a single axis component that can be used to score the utility of an action. */
USTRUCT(BlueprintType)
struct UTILITYAI_API FUtilityAxis
{
	GENERATED_BODY()

public:
	FUtilityAxis();

	/** The display name of the action. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Axis)
	FString DisplayName;

	/** Whether we want to use a custom bookend min value. Without this, it will be assumed to be 0. */
	UPROPERTY(EditAnywhere, meta=(InlineEditConditionToggle))
	bool bUseCustomBookendMin;
	
	/** Minimum value of interest. Will be used for normalizing input value. */
	UPROPERTY(EditAnywhere, meta=(ExcludeBaseStruct, EditCondition=bUseCustomBookendMin), NoClear, Category=Axis)
	TInstancedStruct<FAIDataProviderTypedValue> BookendMin;


	/** Whether we want to use a custom bookend max value. Without this, it will be assumed to be 1. */
	UPROPERTY(EditAnywhere, meta=(InlineEditConditionToggle), Category=Axis)
	bool bUseCustomBookendMax;
	
	/** Maximum value of interest. Will be used for normalizing input value. */
	UPROPERTY(EditAnywhere, meta=(ExcludeBaseStruct, EditCondition=bUseCustomBookendMax), NoClear, Category=Axis)
	TInstancedStruct<FAIDataProviderTypedValue> BookendMax;

	/** Curve type to choose for the axis scoring. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Axis, meta=(GetOptions="UtilityAI.AIUtilitySystem.GetCurveTypeNames"))
	FName CurveType;
};
