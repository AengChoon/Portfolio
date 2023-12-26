// Copyright Aengchoon

using UnrealBuildTool;
using System.Collections.Generic;

public class PortfolioTarget : TargetRules
{
	public PortfolioTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "Portfolio" } );
	}
}
