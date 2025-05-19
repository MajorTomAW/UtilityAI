// Author: Tom Werner (MajorT), 2025


#include "AIUtilitySystem.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(AIUtilitySystem)

UAIUtilitySystem::UAIUtilitySystem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UAIUtilitySystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

TStatId UAIUtilitySystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UAIUtilitySystem, STATGROUP_Tickables);
}
