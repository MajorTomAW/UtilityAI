// Author: Tom Werner (MajorT), 2025

#pragma once
#include "DataProviders/AIDataProvider.h"
#include "StructUtils/InstancedStruct.h"

#include "UtilityAxis.generated.h"

struct FAIDataProviderValue;
struct FAIDataProviderTypedValue;

/** Parameter overrides to use for a response curve. */
USTRUCT(BlueprintType)
struct FUtilityAxisCurveDefinition
{
	GENERATED_BODY()

public:
	FUtilityAxisCurveDefinition();
	
	/** Slope "m" of the curve. */
	UPROPERTY(EditDefaultsOnly, Category=Default, meta=(EditCondition=bUseCustomSlope))
	FAIDataProviderFloatValue Slope;
	UPROPERTY(EditAnywhere, meta=(InlineEditConditionToggle))
	bool bUseCustomSlope = false;

	/** Exponent "k". */
	UPROPERTY(EditDefaultsOnly, Category=Default, meta=(EditCondition=bUseCustomExponent))
	FAIDataProviderFloatValue Exponent;
	UPROPERTY(EditAnywhere, meta=(InlineEditConditionToggle))
	bool bUseCustomExponent = false;

	/** Y-Intercept / Y-Shift "b" of the curve. */
	UPROPERTY(EditDefaultsOnly, Category=Default, DisplayName="Y-Intercept", meta=(EditCondition=bUseCustomYIntercept))
	FAIDataProviderFloatValue YIntercept;
	UPROPERTY(EditAnywhere, meta=(InlineEditConditionToggle))
	bool bUseCustomYIntercept = false;

	/** X-Intercept / X-Shift "c" of the curve. */
	UPROPERTY(EditDefaultsOnly, Category=Default, DisplayName="X-Intercept", meta=(EditCondition=bUseCustomXIntercept))
	FAIDataProviderFloatValue XIntercept;
	UPROPERTY(EditAnywhere, meta=(InlineEditConditionToggle))
	bool bUseCustomXIntercept = false;
};

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
	UPROPERTY(EditAnywhere, meta=(ExcludeBaseStruct, EditCondition=bUseCustomBookendMin), Category=Axis)
	TInstancedStruct<FAIDataProviderTypedValue> BookendMin;

	/** Whether we want to use a custom bookend max value. Without this, it will be assumed to be 1. */
	UPROPERTY(EditAnywhere, meta=(InlineEditConditionToggle), Category=Axis)
	bool bUseCustomBookendMax;
	
	/** Maximum value of interest. Will be used for normalizing input value. */
	UPROPERTY(EditAnywhere, meta=(ExcludeBaseStruct, EditCondition=bUseCustomBookendMax), Category=Axis)
	TInstancedStruct<FAIDataProviderTypedValue> BookendMax;

	/** Curve type to choose for the axis scoring. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Curve, meta=(GetOptions="UtilityAI.AIUtilitySystem.GetCurveTypeNames"))
	FName CurveType;

	/** Overrides for the curve parameters. */
	UPROPERTY(EditAnywhere, Category=Curve)
	FUtilityAxisCurveDefinition CurveOverrides;
};
