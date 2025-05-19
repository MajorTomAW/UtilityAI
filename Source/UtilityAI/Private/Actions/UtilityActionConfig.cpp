// Author: Tom Werner (MajorT), 2025


#include "Actions/UtilityActionConfig.h"

#include "AIUtilitySystem.h"

FUtilityActionConfig::FUtilityActionConfig()
{
	PrioritizationTier = UAIUtilitySystem::GetPriorityGroupNames().IsValidIndex(0) ?
		UAIUtilitySystem::GetPriorityGroupNames()[0] : NAME_None;
	DebugColor = FColor::Green;
	
	WeightValue.DefaultValue = 1.f;
	MarginalValue.DefaultValue = 1.f;
	MarginalTearOff.DefaultValue = 2.f;
}
