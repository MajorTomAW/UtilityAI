// Author: Tom Werner (MajorT), 2025


#include "Actions/UtilityAxis.h"

#include "AIUtilitySystem.h"


FUtilityAxisCurveDefinition::FUtilityAxisCurveDefinition()
{
	Slope.DefaultValue = 1.f;
	Exponent.DefaultValue = 1.f;
	XIntercept.DefaultValue = 0.f;
	YIntercept.DefaultValue = 0.f;
}

FUtilityAxis::FUtilityAxis()
{
	CurveType = UAIUtilitySystem::GetCurveTypeNames().IsValidIndex(0) ?
		UAIUtilitySystem::GetCurveTypeNames()[0] : NAME_None;

	bUseCustomBookendMin = false;
	bUseCustomBookendMax = false;
}
