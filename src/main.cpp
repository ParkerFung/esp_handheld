#include <Arduino.h>
#include "main.h"
#include "game_input.h"

TFT_eSPI tft = TFT_eSPI();

const char* menuItems[] = {"My Games", "Settings", "About!!"};
const int menuItemsCount = sizeof(menuItems) / sizeof(menuItems[0]);

const char* settingsItems[] = {"Brightness", "Volume", "Controls", "Back to Menu"};
const int settingsItemsCount = sizeof(settingsItems) / sizeof(settingsItems[0]);

const char* games[] = {"Pong", "Breakout", "Snake", "Tile"};
const int gamesCount = sizeof(games) / sizeof(games[0]);

// Other globals
int selectedItem = 0;
bool lastDownState = HIGH;
bool lastSelectState = HIGH;
bool lastUpState = HIGH;
currentState currentScreen = Main_Menu;
void setup() {
  tft.init();
  tft.setRotation(3);

  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_SELECT, INPUT_PULLUP);
  pinMode(BUTTON_UP, INPUT_PULLUP);
}

void loop() {

  static int lastDrawnItem = -1;  // Track last selected item for redraw

  while(currentScreen == Playing){
    handleGameInput();
  }
  else{
    inputs();
  }

  int menuSize = getMenuSize(currentScreen);

  // Only redraw if the selected item has changed
  if (selectedItem != lastDrawnItem) {
    drawScreen(currentScreen);  //draw the correct screen based on state
    lastDrawnItem = selectedItem;
  }
}


