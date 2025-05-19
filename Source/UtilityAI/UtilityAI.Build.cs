// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UtilityAI : ModuleRules
{
	public UtilityAI(ReadOnlyTargetRules target) : base(target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(new []
		{ 
			"Core",
			"AIModule",
			"GameplayTags",
			"NavigationSystem",
		});
			
		
		PrivateDependencyModuleNames.AddRange(new []
		{ 
			"CoreUObject", 
			"Engine", 
		});
		
		// Include internal dependencies
		IncludeEditorOnlyDependencies(target, this);
		
		// Expose our module to other relevant modules
		SetupGameplayDebuggerSupport(target);
	}
	
	internal static void IncludeEditorOnlyDependencies(ReadOnlyTargetRules target, ModuleRules module)
	{
		if (!target.bBuildEditor)
		{
			return;
		}
        
		module.PrivateDependencyModuleNames.AddRange([
			"AssetRegistry",
			"EditorFramework",
			"UnrealEd",
			"Slate",
		]);
	}
}
