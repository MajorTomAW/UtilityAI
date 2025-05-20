// Author: Tom Werner (MajorT), 2025

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "AIPersonalityDefinition.generated.h"

/** Stores personality values that can define the personality of a single or multiple AI's. */
UCLASS(Const, BlueprintType)
class UAIPersonalityDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UAIPersonalityDefinition();
};
