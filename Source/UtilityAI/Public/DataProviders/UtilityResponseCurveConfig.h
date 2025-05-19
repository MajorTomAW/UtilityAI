// Author: Tom Werner (MajorT), 2025

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"

#include "UtilityResponseCurveConfig.generated.h"

USTRUCT(BlueprintType)
struct FAIDataProviderUtilityCurve : public FAIDataProviderTypedValue
{
	GENERATED_BODY()

public:
	FAIDataProviderUtilityCurve();
};

UCLASS(EditInlineNew, Abstract)
class UAIDataProvider_ResponseCurve : public UAIDataProvider
{
	GENERATED_BODY()

public:
	UAIDataProvider_ResponseCurve();

	//~ Begin UAIDataProvider Interface
	virtual void BindData(const UObject& Owner, int32 RequestId) override;
	virtual FString ToString(FName PropName) const override;
	//~ End UAIDataProvider Interface

protected:
	/** Slope "m" of the curve. */
	UPROPERTY(EditDefaultsOnly, Category=Default)
	FAIDataProviderFloatValue Slope;

	/** Y-Intercept / Y-Shift "b" of the curve. */
	UPROPERTY(EditDefaultsOnly, Category=Default, DisplayName="Y-Intercept")
	FAIDataProviderFloatValue YIntercept;

	/** X-Intercept / X-Shift "c" of the curve. */
	UPROPERTY(EditDefaultsOnly, Category=Default, DisplayName="X-Intercept")
	FAIDataProviderFloatValue XIntercept;
};