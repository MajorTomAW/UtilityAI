// Author: Tom Werner (MajorT), 2025


#include "Actions/UtilityActionConfig.h"

#include "AIUtilitySystem.h"
#include "Actions/UtilityActionBase.h"

FUtilityActionConfig::FUtilityActionConfig()
{
	PrioritizationTier = UAIUtilitySystem::GetPriorityGroupNames().IsValidIndex(0) ?
		UAIUtilitySystem::GetPriorityGroupNames()[0] : NAME_None;
	DebugColor = FColor::Green;
	
	WeightValue.DefaultValue = 1.f;
	MarginalValue.DefaultValue = 1.f;
	MarginalTearOff.DefaultValue = 2.f;
}

TSubclassOf<UUtilityActionBase> FUtilityActionConfig::GetActionImplementation() const
{
	return UUtilityActionBase::StaticClass();
}

FString FUtilityActionConfig::GetActionName() const
{
	if (CachedActionName.Len() == 0)
	{
		CachedActionName = GetActionImplementation()->GetName();
		CachedActionName.RemoveFromEnd(TEXT("_C"));

		int32 SeparatorIdx = INDEX_NONE;
		const bool bHasSeparator = CachedActionName.FindLastChar(TEXT('_'), SeparatorIdx);

		if (bHasSeparator)
		{
			CachedActionName.MidInline(SeparatorIdx + 1, MAX_int32, EAllowShrinking::No);
		}
	}

	return CachedActionName;
}
