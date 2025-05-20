// Author: Tom Werner (MajorT), 2025


#include "Actions/UtilityActionBase.h"

#include "AIUtilityManager.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(UtilityActionBase)

const float UUtilityActionBase::SuspendNextUpdate = FLT_MAX;

UUtilityActionBase::UUtilityActionBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	TimeUntilNextUpdate = 0.f;
	UtilityActionId = FAIUtilityActionId::InvalidID();

	if (HasAnyFlags(RF_ClassDefaultObject) == false)
	{
		//UtilityId = GetCl
	}
}

UWorld* UUtilityActionBase::GetWorld() const
{
	if (IsValid(UtilityManager))
	{
		return UtilityManager->GetWorld();
	}

	// Fallback to the outer world
	return Cast<UWorld>(GetOuter());
}

void UUtilityActionBase::PostInitProperties()
{
	UObject::PostInitProperties();

	if (HasAnyFlags(RF_ClassDefaultObject) == false)
	{
		UtilityManager = Cast<UAIUtilityManager>(GetOuter());
	}
}

AIUtility::FListenerMap* UUtilityActionBase::GetListeners() const
{
	check(UtilityManager);
	return &UtilityManager->GetListeners();
}
