/*
==============================================================================

This file was auto-generated!

==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent() : LINE_INIT(10), LINE_SPACING(30)
{
  setSize (400, getLine(12));

  setLookAndFeel(&lookAndFeel_);

  // Read config file
  loadWaitBool_ = true;
  loadWaitPlayerCount_ = "10";
  loadWaitPlayerTime_ = "120";

  String path = File::getSpecialLocation(File::SpecialLocationType::currentApplicationFile).getParentDirectory().getFullPathName() + "\\config.cfg";
  File inputFile (path);
  if (inputFile.existsAsFile())
  {
    FileInputStream input(inputFile);

    String str = input.readString();
    srcds_ = File(str);

    loadWaitBool_ = input.readBool();
    loadWaitPlayerCount_ = input.readString();
    loadWaitPlayerTime_ = input.readString();
  }

  // Default params
  srcdsParam_ = "-console -game dota";

  // Components
  // Search Buttons
  srcdsSearchButton_ = new TextButton("");

  if (srcds_.existsAsFile())
    srcdsSearchButton_->setButtonText(srcds_.getFullPathName());

  // Mode ComboBox
  modeSelectCombo_ = new ComboBox("Mode Select");

  modeSelectCombo_->addItem("All Pick",                 (int) ModeSelect::AllPick);
  modeSelectCombo_->addItem("Captain\'s Mode",          (int) ModeSelect::CaptainsMode);
  modeSelectCombo_->addItem("Random Draft",             (int) ModeSelect::RandomDraft);
  modeSelectCombo_->addItem("Single Draft",             (int) ModeSelect::SingleDraft);
  modeSelectCombo_->addItem("All Random",               (int) ModeSelect::AllRandom);
  modeSelectCombo_->addItem("Diretide",                 (int) ModeSelect::Diretide);
  modeSelectCombo_->addItem("Reverse Captain\'s Mode",  (int) ModeSelect::ReverseCaptainsMode);
  modeSelectCombo_->addItem("The Greeviling",           (int) ModeSelect::TheGreeviling);
  modeSelectCombo_->addItem("Only Mid",                 (int) ModeSelect::OnlyMid);
  modeSelectCombo_->addItem("Least Played Heroes",      (int) ModeSelect::LeastPlayedHeroes);
  modeSelectCombo_->addItem("New Player Pool",          (int) ModeSelect::NewPlayerPool);
  modeSelectCombo_->addItem("Captain\'s Draft",         (int) ModeSelect::CaptainsDraft);
  modeSelectCombo_->addItem("Balanced Team",            (int) ModeSelect::BalancedTeam);
  modeSelectCombo_->addItem("Ability Draft",            (int) ModeSelect::AbilityDraft);

  modeSelectCombo_->setSelectedId((int) ModeSelect::AllPick, NotificationType::dontSendNotification);

  // Map ComboBox
  mapSelectCombo_ = new ComboBox("Map Select");

  mapSelectCombo_->addItem("Default",       (int) MapSelect::Default);
  mapSelectCombo_->addItem("Autumn",        (int) MapSelect::Autumn);
  mapSelectCombo_->addItem("Winter",        (int) MapSelect::Winter);
  mapSelectCombo_->addItem("Diretide",      (int) MapSelect::Diretide);

  mapSelectCombo_->setSelectedId((int) MapSelect::Default, NotificationType::dontSendNotification);

  // Wait for players to load
  waitPlayersToggle_ = new ToggleButton("Wait for players to load");
  waitPlayersToggle_->setToggleState(loadWaitBool_, NotificationType::dontSendNotification);

  playerCountFilter_ = new TextEditor::LengthAndCharacterRestriction(2, "0123456789");

  waitPlayersCountBox_ = new TextEditor("Wait Players Count");
  waitPlayersCountBox_->setInputFilter(playerCountFilter_, false); 
  waitPlayersCountBox_->setText(loadWaitPlayerCount_);

  waitTimeFilter_ = new TextEditor::LengthAndCharacterRestriction(0, "0123456789");

  waitPlayersTimeBox_ = new TextEditor("Wait Players Time");
  waitPlayersTimeBox_->setInputFilter(waitTimeFilter_, false); 
  waitPlayersTimeBox_->setText(loadWaitPlayerTime_);

  // Bots
  botEnabledToggle_ = new ToggleButton("Bot Enabled");
  botEnabledToggle_->setToggleState(false, NotificationType::dontSendNotification);

  botDifficultyCombo_ = new ComboBox("Bot Difficulty");
  botDifficultyCombo_->addItem("Easy",      (int) BotDifficulty::Easy);
  botDifficultyCombo_->addItem("Medium",    (int) BotDifficulty::Medium);
  botDifficultyCombo_->addItem("Hard",      (int) BotDifficulty::Hard);
  botDifficultyCombo_->addItem("Unfair",    (int) BotDifficulty::Unfair);
  botDifficultyCombo_->setSelectedId((int) BotDifficulty::Unfair, NotificationType::dontSendNotification);

  // Launch Button
  launchServer_ = new TextButton("Launch Server");

  // Add components
  addAndMakeVisible(srcdsSearchButton_);

  addAndMakeVisible(modeSelectCombo_);
  addAndMakeVisible(mapSelectCombo_);

  addAndMakeVisible(waitPlayersToggle_);
  addAndMakeVisible(waitPlayersCountBox_);
  addAndMakeVisible(waitPlayersTimeBox_);

  addAndMakeVisible(botEnabledToggle_);
  addAndMakeVisible(botDifficultyCombo_);
  addAndMakeVisible(launchServer_);

  // Bound components
  int x = 150,
    w = 240,
    h = 20;
  srcdsSearchButton_->setBounds     (x, getLine(0), w, h);

  modeSelectCombo_->setBounds       (x, getLine(1), w, h);
  mapSelectCombo_->setBounds        (x, getLine(2), w, h);

  waitPlayersToggle_->setBounds     (x, getLine(4), w, h);
  waitPlayersCountBox_->setBounds   (x, getLine(5), w, h);
  waitPlayersTimeBox_->setBounds    (x, getLine(6), w, h);

  botEnabledToggle_->setBounds      (x, getLine(8), w, h);
  botDifficultyCombo_->setBounds    (x, getLine(9), w, h);

  launchServer_->setBounds          (10, getLine(11), getWidth() - 20, 20);

  // Add listeners
  srcdsSearchButton_->addListener(this);
  modeSelectCombo_->addListener(this);
  mapSelectCombo_->addListener(this);
  launchServer_->addListener(this);
}

MainContentComponent::~MainContentComponent()
{
  // Save config
  if (srcds_.existsAsFile())
  {
    String path = File::getSpecialLocation(File::SpecialLocationType::currentApplicationFile).getParentDirectory().getFullPathName() + "\\config.cfg";
    File outputFile (path);
    FileOutputStream output(outputFile);
    output.writeString(srcds_.getFullPathName());
    output.writeBool(waitPlayersToggle_->getToggleState());
    output.writeString(waitPlayersCountBox_->getText());
    output.writeString(waitPlayersTimeBox_->getText());
  }

  deleteAllChildren();

  delete playerCountFilter_;
  delete waitTimeFilter_;
}

void MainContentComponent::paint (Graphics& g)
{
  g.fillAll (Colour (0xff777777));

  //g.setFont (Font (16.0f));
  g.setColour (Colours::black);
  g.drawText("srcds Path:",         10, getLine(0), 140, 20, Justification::centredLeft, false);
  g.drawText("Game Mode",           10, getLine(1), 140, 20, Justification::centredLeft, false);
  g.drawText("Map",                 10, getLine(2), 140, 20, Justification::centredLeft, false);
  g.drawText("Players Count",       10, getLine(5), 140, 20, Justification::centredLeft, false);
  g.drawText("Wait Time (seconds)", 10, getLine(6), 140, 20, Justification::centredLeft, false);
  g.drawText("Bots Difficulty",     10, getLine(9), 140, 20, Justification::centredLeft, false);
}

void MainContentComponent::resized()
{}

void MainContentComponent::buttonClicked(Button* button)
{
  // Search button
  if (button == srcdsSearchButton_)
  {
    FileChooser srcdsChooser("Select srcds.exe",
      File::nonexistent,
      "srcds.exe");

    if (srcdsChooser.browseForFileToOpen())
    {
      srcds_ = srcdsChooser.getResult();
      srcdsSearchButton_->setButtonText(srcds_.getFullPathName());
    }
  }

  // Launch button
  else if (button == launchServer_)
  {
    srcds_.startAsProcess(getSrcdsParam());
  }
}

void MainContentComponent::comboBoxChanged(ComboBox* combo)
{
  // Mode Select
  if (combo == modeSelectCombo_)
  {
    //If selected Diretide, change map to Diretide
    switch(modeSelectCombo_->getSelectedId())
    {
    case ModeSelect::Diretide:
      mapSelectCombo_->setSelectedId((int) MapSelect::Diretide, NotificationType::dontSendNotification);
      break;
      
    case ModeSelect::TheGreeviling:
      mapSelectCombo_->setSelectedId((int) MapSelect::Winter, NotificationType::dontSendNotification);
      break;

    default:
      // Disable option to play in diretide map without playing diretide mode
      if (mapSelectCombo_->getSelectedId() == (int) MapSelect::Diretide)
        mapSelectCombo_->setSelectedId((int) MapSelect::Default, NotificationType::dontSendNotification);
      break;
    }
  }

  // Map Select
  else if (combo == mapSelectCombo_)
  {
    // Disable option to play diretide map without playing diretide mode
    if (mapSelectCombo_->getSelectedId() == (int) MapSelect::Diretide)
      modeSelectCombo_->setSelectedId((int) ModeSelect::Diretide, NotificationType::dontSendNotification);
    else if (mapSelectCombo_->getSelectedId() != (int) MapSelect::Winter && modeSelectCombo_->getSelectedId() == (int) ModeSelect::TheGreeviling)
      modeSelectCombo_->setSelectedId((int) ModeSelect::AllPick, NotificationType::dontSendNotification);
    else if (mapSelectCombo_->getSelectedId() != (int) MapSelect::Diretide && modeSelectCombo_->getSelectedId() == (int) ModeSelect::Diretide)
      modeSelectCombo_->setSelectedId((int) ModeSelect::AllPick, NotificationType::dontSendNotification);
  }
}

String MainContentComponent::getSrcdsParam()
{
  String param = srcdsParam_;

  // Max Players
  param += " +maxplayers 10 ";

  // Add map param
  param += "+map ";

  switch (mapSelectCombo_->getSelectedId())
  {
  case (int) MapSelect::Autumn:
    param += "dota_autumn";
    break;

  case (int) MapSelect::Diretide:
    param += "dota_diretide_12";
    break;

  case (int) MapSelect::Winter:
    param += "dota_winter";
    break;

  default:
    param += "dota";
    break;
  }


  // Player loading
  if (waitPlayersToggle_->getToggleState())
  {
    param += " +dota_wait_for_players_to_load 1";
    param += " +dota_wait_for_players_to_load_count " + waitPlayersCountBox_->getText();
    param += " +dota_wait_for_players_to_load_timeout " + waitPlayersTimeBox_->getText();
  }

  // Bots
  if (botEnabledToggle_->getToggleState())
  {
    param += "+dota_start_ai_game 1 +dota_bot_disable 0 +dota_bot_difficulty " + String(botDifficultyCombo_->getSelectedId() - 1);
    param += " ";
  }

  // Game mode
  param += "+dota_force_gamemode " + String(modeSelectCombo_->getSelectedId());

  return param;
}

int MainContentComponent::getLine(int line)
{
  return LINE_INIT + line * LINE_SPACING;
}