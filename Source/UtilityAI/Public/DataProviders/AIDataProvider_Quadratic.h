// Author: Tom Werner (MajorT), 2025

#pragma once

#include "CoreMinimal.h"
#include "AIDataProvider_Exponentln.h"
#include "AIDataProvider_Quadratic.generated.h"

/** Data provider for a quadratic expression. */
UCLASS(EditInlineNew, meta=(DisplayName="Quadratic Curve"))
class UAIDataProvider_Quadratic : public UAIDataProvider_Exponentln
{
	GENERATED_BODY()
};
