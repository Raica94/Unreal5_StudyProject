// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class UE5_PracticeTarget : TargetRules
{
	public UE5_PracticeTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "UE5_Practice" } );
	}
}
