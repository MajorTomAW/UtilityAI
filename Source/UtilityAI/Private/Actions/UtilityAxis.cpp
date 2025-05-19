// Author: Tom Werner (MajorT), 2025


#include "Actions/UtilityAxis.h"

#include "AIUtilitySystem.h"


FUtilityAxis::FUtilityAxis()
{
	CurveType = UAIUtilitySystem::GetCurveTypeNames().IsValidIndex(0) ?
		UAIUtilitySystem::GetCurveTypeNames()[0] : NAME_None;

	bUseCustomBookendMin = false;
	bUseCustomBookendMax = false;
}
