// Author: Tom Werner (MajorT), 2025


#include "AIUtilityTypes.h"

#include "UtilityComponent.h"

FAIUtilityListener::FAIUtilityListener()
	: CachedLocation(ForceInit)
	, CachedDirection(ForceInit)
	, ListenerId(FAIUtilityListenerId::InvalidID())
{
}

FAIUtilityListener::FAIUtilityListener(UUtilityComponent& InListener)
	: Listener(&InListener)
	, CachedLocation(ForceInit)
	, CachedDirection(ForceInit)
	, ListenerId(FAIUtilityListenerId::InvalidID())
{
}
