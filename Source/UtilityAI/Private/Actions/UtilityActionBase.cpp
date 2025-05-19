// Author: Tom Werner (MajorT), 2025


#include "Actions/UtilityActionBase.h"

#include "AIUtilityManager.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(UtilityActionBase)

UUtilityActionBase::UUtilityActionBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	TimeUntilNextUpdate = 0.f;
	UtilityId = FAIUtilityId::InvalidID();

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
