Dota 2 Server
=============

Dota 2 Server to play offline with friends (since there's no Dedicated Server for Dota 2 already).
Uses Alien Swarm Dedicated Server and Dota2Fixups with SourceMod.

####Requirements for compiling
- Juce Toolkit
- Introjucer (comes with Juce Toolkit)

- Add a post-build/content files to deploy serverfiles folder
  If using Visual Studio, you should add a post-build script as follows:
    xcopy /Y /S "$(SolutionDir)\..\..\serverfiles" "$(TargetDir)\serverfiles\"
