// Author: Tom Werner (MajorT), 2025

#pragma once

#include "CoreMinimal.h"
#include "UtilityAITypes.h"
#include "UObject/Object.h"

#include "UtilityActionBase.generated.h"

#define MY_API UTILITYAI_API

class UAIUtilityManager;
/** Defines a singular action that can be scored and executed by an agent. */
UCLASS(ClassGroup=AI, Abstract, Config=Engine, MinimalAPI)
class UUtilityActionBase : public UObject
{
	GENERATED_BODY()

public:
	MY_API UUtilityActionBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	//~ Begin UObject Interface
	MY_API virtual UWorld* GetWorld() const override;
	//~ End UObject Interface

private:
	/** Pointer to the utility manager for the current world. */
	UPROPERTY()
	TObjectPtr<UAIUtilityManager> UtilityManager;
	
	/** The id of this utility action. */
	FAIUtilityId UtilityId;

	/** Cached time until this action should be re-evaluated. */
	float TimeUntilNextUpdate;
};
#undef MY_API