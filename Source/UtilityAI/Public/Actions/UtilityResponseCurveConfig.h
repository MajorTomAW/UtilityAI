// Author: Tom Werner (MajorT), 2025

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"

#include "UtilityResponseCurveConfig.generated.h"

USTRUCT(BlueprintType)
struct FUtilityResponseCurveConfig
{
	GENERATED_BODY()

public:
	FUtilityResponseCurveConfig();

	/** Slope "m" of the curve. */
	UPROPERTY(EditDefaultsOnly, Category=Default)
	FAIDataProviderFloatValue Slope;

	/** Exponent "k". */
	UPROPERTY(EditDefaultsOnly, Category=Default)
	FAIDataProviderFloatValue Exponent;

	/** Y-Intercept / Y-Shift "b" of the curve. */
	UPROPERTY(EditDefaultsOnly, Category=Default, DisplayName="Y-Intercept")
	FAIDataProviderFloatValue YIntercept;

	/** X-Intercept / X-Shift "c" of the curve. */
	UPROPERTY(EditDefaultsOnly, Category=Default, DisplayName="X-Intercept")
	FAIDataProviderFloatValue XIntercept;

private:
	mutable UFunction* CachedCallFunction;
};
