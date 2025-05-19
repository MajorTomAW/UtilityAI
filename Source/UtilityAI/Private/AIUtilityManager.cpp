// Author: Tom Werner (MajorT), 2025


#include "AIUtilityManager.h"

#include "AIUtilitySystem.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(AIUtilityManager)

UAIUtilityManager::UAIUtilityManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NextUtilityAgingTick = 0.f;
	CurrentTime = 0.f;
}

UAIUtilityManager* UAIUtilityManager::GetCurrent(UObject* WorldContextObject)
{
	UWorld* World = Cast<UWorld>(WorldContextObject);
	if (!IsValid(World) && IsValid(WorldContextObject))
	{
		World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	}

	if (IsValid(World) && World->GetAISystem())
	{
		UAIUtilitySystem* AISystem = CastChecked<UAIUtilitySystem>(World->GetAISystem());
		return AISystem->GetAIUtilityManager();
	}

	return nullptr;
}

UAIUtilityManager* UAIUtilityManager::GetCurrent(UWorld& World)
{
	if (World.GetAISystem())
	{
		UAIUtilitySystem* AISystem = CastChecked<UAIUtilitySystem>(World.GetAISystem());
		return AISystem->GetAIUtilityManager();
	}

	return nullptr;
}
