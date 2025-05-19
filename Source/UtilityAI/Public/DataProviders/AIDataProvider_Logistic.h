// Author: Tom Werner (MajorT), 2025

#pragma once

#include "CoreMinimal.h"
#include "AIDataProvider_Exponentln.h"
#include "AIDataProvider_Logistic.generated.h"

/** Data provider for a logistic expression. */
UCLASS(EditInlineNew, meta=(DisplayName="Logistic Curve"))
class UAIDataProvider_Logistic : public UAIDataProvider_Exponentln
{
	GENERATED_BODY()
};
