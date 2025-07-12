#include <Arduino.h>
#include "main.h"

// Global variable definitions (not in the header!)
TFT_eSPI tft = TFT_eSPI();
const char* menuItems[] = {"My Games", "Settings", "About!!"};

const char* settingsItems[] = {"Brightness","Volume","Controls","Back to Menu"};



int selectedItem = 0;
bool lastButtonState = HIGH;
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
  static int lastDrawnItem = -1;      // Tracks the last drawn item
  int menuSize = 3;
  inputs(menuSize);                   // May change selectedItem

  if (selectedItem != lastDrawnItem) {
    drawMenu(currentScreen);
    lastDrawnItem = selectedItem;
  }
}

