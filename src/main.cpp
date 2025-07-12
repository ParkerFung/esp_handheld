#include <Arduino.h>
#include "main.h"

// Global variable definitions (not in the header!)
TFT_eSPI tft = TFT_eSPI();
const char* menuItems[] = {"My Games", "Settings", "About!!"};
int selectedItem = 0;
bool lastButtonState = HIGH;
bool lastSelectState = HIGH;
bool lastUpState = HIGH;

void setup() {
  tft.init();
  tft.setRotation(3);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_SELECT, INPUT_PULLUP);
  pinMode(BUTTON_UP, INPUT_PULLUP);
}

void loop() {
  downButton();
  selectButton();
  upButton();
}
