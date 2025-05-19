// Copyright Epic Games, Inc. All Rights Reserved.

#include "UtilityAIModule.h"

#include "UtilityAILogging.h"

#define LOCTEXT_NAMESPACE "FUtilityAIModule"

class FUtilityAIModule final : public IUtilityAIModule
{
public:
	//~ Begin IModuleInterface
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	//~ End IModuleInterface

	//~ Begin IAISystemModule
	virtual UAISystemBase* CreateAISystemInstance(UWorld* World) override;
	//~ End IAISystemModule
};
IMPLEMENT_MODULE(FUtilityAIModule, UtilityAI)


void FUtilityAIModule::StartupModule()
{
}

void FUtilityAIModule::ShutdownModule()
{
}

UAISystemBase* FUtilityAIModule::CreateAISystemInstance(UWorld* World)
{
	UTILITYAI_LOG("Creating AIUtilitySystem for world %s", *GetNameSafe(World));
	
	FSoftClassPath AISystemClassName = UAISystemBase::GetAISystemClassName();
	if (IsValid(World))
	{
		// World settings might override the default class
		if (const AWorldSettings* WorldSettings = World->GetWorldSettings())
		{
			AISystemClassName = WorldSettings->GetAISystemClassName();
		}
	}

	UAISystemBase* AISystemInstance = nullptr;
	if (AISystemClassName.IsValid())
	{
		TSubclassOf<UAISystemBase> Class =
			LoadClass<UAISystemBase>(nullptr, *AISystemClassName.ToString(), nullptr, LOAD_None, nullptr);;

		AISystemInstance = Class ? NewObject<UAISystemBase>(World, Class) : nullptr;

		if (!IsValid(AISystemInstance))
		{
			UTILITYAI_ERROR("Failed to create AISystem instance of class %s!", *AISystemClassName.ToString());
		}
	}

	return AISystemInstance;
}

#undef LOCTEXT_NAMESPACE
