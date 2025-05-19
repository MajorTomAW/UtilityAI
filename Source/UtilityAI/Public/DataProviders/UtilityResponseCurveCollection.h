// Author: Tom Werner (MajorT), 2025

#pragma once

#include "CoreMinimal.h"
#include "UtilityResponseCurveConfig.h"
#include "Engine/DataAsset.h"
#include "StructUtils/InstancedStruct.h"

#include "UtilityResponseCurveCollection.generated.h"

/** A collection of response curve used for action utility scoring. */
UCLASS(BlueprintType)
class UUtilityResponseCurveCollection : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UUtilityResponseCurveCollection();

	/** List of predefined equations for utility response scoring. */
	UPROPERTY(EditAnywhere, Category="Utility", NoClear)
	TMap<FName, TInstancedStruct<FAIDataProviderUtilityCurve>> ResponseCurves;
};
