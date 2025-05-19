// Author: Tom Werner (MajorT), 2025


#include "AIUtilityManager.h"
/*
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
		UAISystem* AISystem = CastChecked<UAISystem>(World->GetAISystem());
	}

	return nullptr;
}

UAIUtilityManager* UAIUtilityManager::GetCurrent(UWorld& World)
{
	if (World.GetAISystem())
	{
		
	}

	return nullptr;
}

void UAIUtilityManager::Tick(float DeltaTime)
{
	const UWorld* World = GEngine->GetWorldFromContextObjectChecked(GetOuter());
	check(World);

	if (World->bPlayersOnly)
	{
		return;
	}

	CurrentTime = World->GetTimeSeconds();
}

TStatId UAIUtilityManager::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UAIUtilityManager, STATGROUP_Tickables);
}
*/
