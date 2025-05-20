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
	friend class UAIUtilityManager;

public:
	MY_API UUtilityActionBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	static MY_API const float SuspendNextUpdate;

	//~ Begin UObject Interface
	MY_API virtual UWorld* GetWorld() const override;
	virtual void PostInitProperties() override;
	//~ End UObject Interface

protected:
	/** Returns the owning utility manager of this action. */
	FORCEINLINE UAIUtilityManager* GetUtilityManager() { return UtilityManager; }

	/** Will result in updating as soon as possible. */
	FORCEINLINE void RequestImmediateUpdate() { TimeUntilNextUpdate = 0.f; }

	/** Returns the list of listeners to this action. */
	MY_API AIUtility::FListenerMap* GetListeners() const;

private:
	/** Pointer to the utility manager for the current world. */
	UPROPERTY()
	TObjectPtr<UAIUtilityManager> UtilityManager;
	
	/** The id of this utility action. */
	FAIUtilityActionId UtilityActionId;

	/** Cached time until this action should be re-evaluated. */
	float TimeUntilNextUpdate;
};
#undef MY_API

typedef TSharedPtr<UUtilityActionBase, ESPMode::ThreadSafe> FTUtilityActionPtr;