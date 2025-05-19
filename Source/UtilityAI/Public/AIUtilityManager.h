// Author: Tom Werner (MajorT), 2025

#pragma once

#include "CoreMinimal.h"
#include "AISubsystem.h"

#include "AIUtilityManager.generated.h"

#define MY_API UTILITYAI_API

/** Utility manager that handles registered AI Utility actions between listeners and sources. */
UCLASS(ClassGroup=AI, Config=Game, Defaultconfig, MinimalAPI)
class UAIUtilityManager : public UAISubsystem
{
	GENERATED_BODY()

public:
	MY_API UAIUtilityManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
#undef MY_API