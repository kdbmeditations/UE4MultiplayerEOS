// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE4MultiplayerEOS : ModuleRules
{
	public UE4MultiplayerEOS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
