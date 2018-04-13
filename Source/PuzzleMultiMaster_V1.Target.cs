// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class PuzzleMultiMaster_V1Target : TargetRules
{
	public PuzzleMultiMaster_V1Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("PuzzleMultiMaster_V1");
	}
}
