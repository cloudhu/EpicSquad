// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EpicSquad : ModuleRules
{
	public EpicSquad(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"NavigationSystem",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"Niagara",
			"UMG",
			"GameplayMessageRuntime",
			"NinjaGAS",
			"NinjaInput",
			// Ninja Combat
			"CommonUI",
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks",
			"ModelViewViewModel",
			"NinjaCombat",
			"NinjaCombatCamera",
			"NinjaCombatCore",
			"NinjaCombatActorPool",
			"NinjaCombatUI",
			"NinjaCombatInventory",
			"StructUtils",
			"NinjaCombatFactions",
			// Ninja Inventory
			"NinjaInventory",
			"NinjaInventoryCore",
			"NinjaInventoryEquipment",
			"CommonInput",
			"NinjaFactions",
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"EpicSquad",
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
