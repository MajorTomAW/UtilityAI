// Author: Tom Werner (MajorT), 2025


#include "Actions/UtilityResponseCurveConfig.h"

FUtilityResponseCurveConfig::FUtilityResponseCurveConfig()
{
	CachedCallFunction = nullptr;
	
	Slope.DefaultValue = 1.f;
	Exponent.DefaultValue = 1.f;
	YIntercept.DefaultValue = 0.f;
	XIntercept.DefaultValue = 0.f;
}
