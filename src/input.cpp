#include "main.h"

void inputs() {
  int menuSize = getMenuSize(currentScreen);

  // down button
  bool currentDownState = digitalRead(BUTTON_DOWN);
  if (currentDownState == LOW && lastDownState == HIGH) {
    selectedItem = (selectedItem + 1) % menuSize;
    delay(200);
  }
  lastDownState = currentDownState;

  // up button
  bool currentUpState = digitalRead(BUTTON_UP);
  if (currentUpState == LOW && lastUpState == HIGH) {
    selectedItem = (selectedItem - 1 + menuSize) % menuSize;
    delay(200);
  }
  lastUpState = currentUpState;

  // select button
  bool currentSelectState = digitalRead(BUTTON_A);
  if (currentSelectState == LOW && lastSelectState == HIGH) {
    handleSelect();
    delay(200);
  }
  lastSelectState = currentSelectState;
}


int getMenuSize(currentState screen) {
  switch (screen) {
    case Main_Menu:
      return menuItemsCount;
    case Settings:
      return settingsItemsCount;
    case Game_List:
      return gamesCount;
    default:
      return 0;
  }
}
