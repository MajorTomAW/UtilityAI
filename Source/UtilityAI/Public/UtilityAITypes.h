// Author: Tom Werner (MajorT), 2025

#pragma once

#include "AITypes.h"

class UAIUtilityComponent;

#define MY_API UTILITYAI_API

/** Utility counter struct. */
struct FUtilityAICounter : FAIBasicCounter<uint8> {};
typedef FAINamedID<FUtilityAICounter> FAIUtilityId;

/** Listener id counter struct. */
struct FUtilityAIListenerCounter : FAIBasicCounter<uint32> {};
typedef FAIGenericID<FUtilityAIListenerCounter> FAIUtilityListenerId;

/** Contains cached information about the listener. */
struct FAIUtilityListener
{
public:
	MY_API FAIUtilityListener();
	MY_API FAIUtilityListener(UAIUtilityComponent& InListener);
	
	TWeakObjectPtr<UAIUtilityComponent> Listener;
	FVector CachedLocation;
	FVector CachedDirection;

private:
	/** ID of the listener. */
	FAIUtilityListenerId ListenerId;
};

namespace UtilityAI
{
	typedef TMap<FAIUtilityListenerId, FAIUtilityListener> FListenerMap;
}

#undef MY_API