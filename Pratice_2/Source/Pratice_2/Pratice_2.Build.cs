// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Pratice_2 : ModuleRules
{
	public Pratice_2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
