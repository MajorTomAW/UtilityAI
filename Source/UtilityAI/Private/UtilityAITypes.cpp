// Author: Tom Werner (MajorT), 2025


#include "UtilityAITypes.h"


#include "Components/AIUtilityComponent.h"

FAIUtilityListener::FAIUtilityListener()
	: CachedLocation(ForceInit)
	, CachedDirection(ForceInit)
	, ListenerId(FAIUtilityListenerId::InvalidID())
{
}

FAIUtilityListener::FAIUtilityListener(UAIUtilityComponent& InListener)
	: Listener(&InListener)
	, CachedLocation(ForceInit)
	, CachedDirection(ForceInit)
	, ListenerId(FAIUtilityListenerId::InvalidID())
{
}