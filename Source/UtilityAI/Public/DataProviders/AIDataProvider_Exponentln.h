// Author: Tom Werner (MajorT), 2025

#pragma once

#include "CoreMinimal.h"
#include "UtilityResponseCurveConfig.h"
#include "AIDataProvider_Exponentln.generated.h"

UCLASS(Abstract)
class UAIDataProvider_Exponentln : public UAIDataProvider_ResponseCurve
{
	GENERATED_BODY()

public:
	UAIDataProvider_Exponentln();
	
	/** Exponent "k". */
	UPROPERTY(EditDefaultsOnly, Category=Default)
	FAIDataProviderFloatValue Exponent;
};
