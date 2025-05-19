// Copyright Epic Games, Inc. All Rights Reserved.

#include "UtilityAIModule.h"

#include "AIUtilitySystem.h"
#include "ISettingsModule.h"
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

protected:
	void OnPostEngineInit();
};
IMPLEMENT_MODULE(FUtilityAIModule, UtilityAI)


void FUtilityAIModule::StartupModule()
{
	FCoreDelegates::OnPostEngineInit.AddRaw(this, &FUtilityAIModule::OnPostEngineInit);
}

void FUtilityAIModule::ShutdownModule()
{
	FCoreDelegates::OnPostEngineInit.RemoveAll(this);
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

void FUtilityAIModule::OnPostEngineInit()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (!SettingsModule)
	{
		return;
	}
	
	// Unregister existing AI Settings
	SettingsModule->UnregisterSettings("Project", "Engine", "AISystem");

	// And register our own once instead
	SettingsModule->RegisterSettings("Project", "Engine", "AISystem",
		LOCTEXT("AISystemSettingsName", "AI System"),
		LOCTEXT("AISystemSettingsDescription", "Settings for the (Utility) AI System."),
		GetMutableDefault<UAIUtilitySystem>());
}

#undef LOCTEXT_NAMESPACE
