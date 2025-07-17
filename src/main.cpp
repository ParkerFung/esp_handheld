#include <Arduino.h>
#include "main.h"
#include "game_input.h"
#include "pong.h"
#include "menu.h"
#include "gameList.h"

// Global instance of display
TFT_eSPI tft = TFT_eSPI();

// Menu/game definitions
const char* menuItems[] = {"My Games", "Settings", "About!!"};
const int menuItemsCount = sizeof(menuItems) / sizeof(menuItems[0]);

const char* settingsItems[] = {"Brightness", "Volume", "Controls", "Back to Menu"};
const int settingsItemsCount = sizeof(settingsItems) / sizeof(settingsItems[0]);

const char* settingsLabels[] = {"Brightness", "Volume", "Controls", "Main Menu"};

const char* games[] = {"Pong", "Breakout", "Snake", "Tile"};
const int gamesCount = sizeof(games) / sizeof(games[0]);

// Global state variables
int selectedItem = 0;
currentState currentScreen = Main_Menu;

// Button states
bool lastDownState = HIGH;
bool lastSelectState = HIGH;
bool lastUpState = HIGH;
bool lastLeftState = HIGH;

static bool pongInitialized = false;

void setup() {
  tft.init();
  tft.setRotation(1);

  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_SELECT, INPUT_PULLUP);
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);  // For exiting games

  drawScreen(currentScreen);
}

void loop() {
  static int lastSelectedItem = -1;

  switch (currentScreen) {
    case Main_Menu:
    case Settings:
    case About:
    case Game_List:
      inputs();  // Poll and respond to input

      if (selectedItem != lastSelectedItem) {
        drawScreen(currentScreen);
        lastSelectedItem = selectedItem;
      }
      break;

    case Playing:
      if (!pongInitialized) {
        pongSetup(tft, MEDIUM);  // You can make this dynamic if needed
        pongInitialized = true;
      }

      if (!pongUpdate(tft)) {
        // Exited game
        currentScreen = Main_Menu;
        pongInitialized = false;
        selectedItem = 0;
        drawScreen(currentScreen);
      } else {
        pongDraw(tft);
      }
      break;
  }

  delay(15);  // Simple loop delay for frame timing
}
