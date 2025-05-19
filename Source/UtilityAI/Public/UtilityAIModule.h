// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "AI/AISystemBase.h"
#include "Modules/ModuleManager.h"

class IUtilityAIModule : public IAISystemModule
{
public:
	/** Returns the module instance. */
	static IUtilityAIModule& Get()
	{
		return FModuleManager::LoadModuleChecked<IUtilityAIModule>("UtilityAI");
	}

	/** Checks to see if this module is loaded and ready. */
	static bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("UtilityAI");
	}
};
