using UnrealBuildTool;

public class UtilityAIEditor : ModuleRules
{
    public UtilityAIEditor(ReadOnlyTargetRules target) : base(target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new []
        { 
            "Core",
        });

        PrivateDependencyModuleNames.AddRange(new []
        { 
            "CoreUObject", 
            "Engine", 
            "Slate", 
            "SlateCore"
        });
    }
}