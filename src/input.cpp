#include "main.h"

void downButton() {
  bool currentButtonState = digitalRead(BUTTON_DOWN);
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    selectedItem = (selectedItem + 1) % 3;
    drawMenu();
    delay(200);  // debounce
  }
  lastButtonState = currentButtonState;
}

void selectButton() {
  bool currentSelectState = digitalRead(BUTTON_SELECT);
  if (currentSelectState == LOW && lastSelectState == HIGH) {
    menuSelect(selectedItem);
    delay(200);  // debounce
  }
  lastSelectState = currentSelectState;
}
