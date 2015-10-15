namespace UnrealBuildTool.Rules
{
	public class OSC : ModuleRules
	{
		public OSC(TargetInfo Target)
		{
			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Networking",
				}
			); 

			PrivateDependencyModuleNames.AddRange(
				new string[] {
					"Core",
					"CoreUObject",
                    "Engine",
					"Sockets",
                    "InputCore",
                    "Slate",
                    "SlateCore",
				}
			);

			PrivateIncludePathModuleNames.AddRange(
				new string[] {
					"Settings",
				}
			);

			PublicIncludePaths.AddRange(
				new string[] {
					"OSC/Public"
				}
			);

			PrivateIncludePaths.AddRange(
				new string[] {
					"OSC/Private"
				}
			);

            bEnableExceptions = true;

            if (Target.Type.HasValue && TargetRules.IsEditorType(Target.Type.Value))
            {
                Definitions.Add("OSC_EDITOR_BUILD=1");

                PrivateDependencyModuleNames.Add("UnrealEd");
            }
            else
            {
                Definitions.Add("OSC_EDITOR_BUILD=0");
            }
        }
	}
}
