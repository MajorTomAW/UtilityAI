// Copyright Epic Games, Inc. All Rights Reserved.

#include "UtilityAIModule.h"

#define LOCTEXT_NAMESPACE "FUtilityAIModule"

class FUtilityAIModule final : public IUtilityAIModule
{
public:
	//~ Begin IModuleInterface
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	//~ End IModuleInterface
};
IMPLEMENT_MODULE(FUtilityAIModule, UtilityAI)


void FUtilityAIModule::StartupModule()
{
}

void FUtilityAIModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE