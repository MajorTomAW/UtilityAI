// Author: Tom Werner (MajorT), 2025


#include "DataProviders/UtilityResponseCurveConfig.h"


FAIDataProviderUtilityCurve::FAIDataProviderUtilityCurve()
{
}

UAIDataProvider_ResponseCurve::UAIDataProvider_ResponseCurve()
{
	Slope.DefaultValue = 1.f;
	YIntercept.DefaultValue = 0.f;
	XIntercept.DefaultValue = 0.f;
}

void UAIDataProvider_ResponseCurve::BindData(const UObject& Owner, int32 RequestId)
{
	Super::BindData(Owner, RequestId);
}

FString UAIDataProvider_ResponseCurve::ToString(FName PropName) const
{
	return Super::ToString(PropName);
}
