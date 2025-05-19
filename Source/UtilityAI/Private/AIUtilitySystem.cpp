// Author: Tom Werner (MajorT), 2025


#include "AIUtilitySystem.h"

#include "AIUtilityManager.h"
#include "UtilityAILogging.h"

UAIUtilitySystem::UAIUtilitySystem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UAIUtilitySystem::BeginDestroy()
{
	Super::BeginDestroy();
}

void UAIUtilitySystem::InitializeActorsForPlay(bool bTimeGotReset)
{
	Super::InitializeActorsForPlay(bTimeGotReset);
}

void UAIUtilitySystem::WorldOriginLocationChanged(FIntVector OldOriginLocation, FIntVector NewOriginLocation)
{
	Super::WorldOriginLocationChanged(OldOriginLocation, NewOriginLocation);
}

void UAIUtilitySystem::CleanupWorld(bool bSessionEnded, bool bCleanupResources)
{
	Super::CleanupWorld(bSessionEnded, bCleanupResources);
}

void UAIUtilitySystem::StartPlay()
{
	Super::StartPlay();
}

void UAIUtilitySystem::PostInitProperties()
{
	Super::PostInitProperties();

	if (HasAnyFlags(RF_ClassDefaultObject) == false)
	{
		UWorld* WorldOuter = GetOuterWorld();

		TSubclassOf<UAIUtilityManager> AIUtilityManagerClass = AIUtilityManagerClassName.IsValid() ? LoadClass<UAIUtilityManager>(NULL, *AIUtilityManagerClassName.ToString(), NULL, LOAD_None, NULL) : UAIUtilityManager::StaticClass();
		if (AIUtilityManagerClass)
		{
			AIUtilityManager = NewObject<UAIUtilityManager>(this, AIUtilityManagerClass, TEXT("AIUtilityManager"));
			UTILITYAI_LOG("Created AIUtilityManager instance of class %s", *GetNameSafe(AIUtilityManager));
		}
		ensure(AIUtilityManager != nullptr);
	}
}
