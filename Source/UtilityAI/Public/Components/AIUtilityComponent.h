// Author: Tom Werner (MajorT), 2025

#pragma once

#include "CoreMinimal.h"
#include "BrainComponent.h"

#include "AIUtilityComponent.generated.h"

class UAIPerceptionComponent;
class UBlackboardComponent;
class UBrainComponent;
class AAIController;

#define MY_API UTILITYAI_API

/** Base class for all UtilityComponents which are used to control and manage decision-making of an agent. */
UCLASS(ClassGroup=AI, meta=(BlueprintSpawnableComponent), HideCategories=(Activation,Collision), Config=Game, MinimalAPI)
class UAIUtilityComponent : public UBrainComponent
{
	GENERATED_BODY()

public:
	MY_API UAIUtilityComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	//~ Begin UBrainComponent Interface
	MY_API virtual void StartLogic() override;
	MY_API virtual void StopLogic(const FString& Reason) override;
	MY_API virtual void RestartLogic() override;
	//~ End UBrainComponent Interface

	//~ Begin UActorComponent Interface
	MY_API virtual void InitializeComponent() override;
	MY_API virtual void UninitializeComponent() override;
	MY_API virtual void RegisterComponentTickFunctions(bool bRegister) override;
	MY_API virtual void SetComponentTickEnabled(bool bEnabled) override;
	MY_API virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	//~ End UActorComponent Interface

	/** Schedule when will be the next tick, 0.f means next frame, FLT_MAX means never */
	MY_API void ScheduleNextTick(float NextDeltaTime);

	/** Caches PerceptionComponent's pointer to be used with this utility component. */
	MY_API void CachePerceptionComponent(UAIPerceptionComponent* InPerceptionComp);

	/** Returns the PerceptionComponent used by the agent. */
	MY_API UAIPerceptionComponent* GetPerceptionComponent();

	/** Returns the PerceptionComponent used by the agent. */
	MY_API const UAIPerceptionComponent* GetPerceptionComponent() const;

protected:
	/** Perception component. */
	UPROPERTY(Transient)
	TObjectPtr<UAIPerceptionComponent> PerceptionComp;

	/** Used to tell the tick manager that we want interval ticking. */
	uint8 bTickedOnce : 1;

	/** Predicted next DeltaTime*/
	float NextTickDeltaTime = 0.f;

	/** Accumulated DeltaTime if ticked more than the predicted next delta time */
	float AccumulatedTickDeltaTime = 0.f;

	/** Current frame DeltaTime */
	float CurrentFrameDeltaTime = 0.f;

	/** GameTime of the last DeltaTime request, used for debugging to output warnings about ticking */
	double LastRequestedDeltaTimeGameTime = 0;
};
#undef MY_API


inline UAIPerceptionComponent* UAIUtilityComponent::GetPerceptionComponent()
{
	return PerceptionComp;
}

inline const UAIPerceptionComponent* UAIUtilityComponent::GetPerceptionComponent() const
{
	return PerceptionComp;
}