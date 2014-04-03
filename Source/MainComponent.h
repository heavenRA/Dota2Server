/*
==============================================================================

This file was auto-generated!

==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/*
This component lives inside our window, and this is where you should put all
your controls and content.
*/
class MainContentComponent   : public Component, public ButtonListener, public ComboBoxListener
{
public:
  MainContentComponent();
  ~MainContentComponent();

  void paint (Graphics&);
  void resized();

  void buttonClicked(Button*) override;
  void comboBoxChanged(ComboBox*) override; 

  String getSrcdsParam();

private:
  // Enumerations
  enum class ModeSelect : int
  {
    AllPick = 1,
    CaptainsMode = 2,
    RandomDraft = 3,
    SingleDraft = 4,
    AllRandom = 5,
    Diretide = 7,
    ReverseCaptainsMode = 8,
    TheGreeviling = 9,
    OnlyMid = 11,
    LeastPlayedHeroes = 12,
    NewPlayerPool = 13,
    CaptainsDraft = 16,
    BalancedTeam = 17,
    AbilityDraft = 18
  };

  enum class MapSelect : int
  {
    Default = 1,
    Autumn,
    Winter,
    Diretide
  };

  enum class BotDifficulty : int
  {
    Easy = 1,
    Medium,
    Hard,
    Unfair
  };

  // Files and params
  String srcdsParam_;

  String dotaPath_;

  File serverFiles_;
  File backupFiles_;

  // GUI Components
  TextButton* dotaSearchButton_;

  ComboBox* modeSelectCombo_;
  ComboBox* mapSelectCombo_;

  ToggleButton* waitPlayersToggle_;
  TextEditor* waitPlayersCountBox_,
    * waitPlayersTimeBox_;

  TextButton* launchServer_;

  // Bots
  ToggleButton* botEnabledToggle_;
  ComboBox* botDifficultyCombo_;

  // Number restriction for TextEditors
  TextEditor::LengthAndCharacterRestriction* playerCountFilter_,
    * waitTimeFilter_;

  // Lines
  const int LINE_INIT;
  const int LINE_SPACING;
  int getLine(int);

  LookAndFeel_V3 lookAndFeel_;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
