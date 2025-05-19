// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class IUtilityAIModule : public IModuleInterface
{
public:
	/** Returns the module instance. */
	static IUtilityAIModule& Get()
	{
		return FModuleManager::LoadModuleChecked<IUtilityAIModule>("UtilityAI");
	}
};
