// Author: Tom Werner (MajorT), 2025

#pragma once

#include "UtilityResponseCurveConfig.h"

#include "AIDataProvider_Linear.generated.h"

/** Data provider for a linear expression. */
UCLASS(EditInlineNew, meta=(DisplayName="Linear Curve"))
class UAIDataProvider_Linear : public UAIDataProvider_ResponseCurve
{
	GENERATED_BODY()
};
