#include "main.h"

int m = 10;

void downButton() {
  bool currentButtonState = digitalRead(BUTTON_DOWN);
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    selectedItem = (selectedItem + 1) % 3;
    drawMenu();
    delay(200);  // debounce
  }
  lastButtonState = currentButtonState;
}

void upButton(){
  bool currentUpState = digitalRead(BUTTON_UP);
  if(currentUpState == LOW && lastUpState == HIGH){
    if(selectedItem <= 0){
      selectedItem == 2;
    }
    else{
      selectedItem = (selectedItem - 1) % 3;
    }
    drawMenu();
    delay(200);
  }
  lastUpState = currentUpState;
  m+1;
}

void selectButton() {
  bool currentSelectState = digitalRead(BUTTON_SELECT);
  if (currentSelectState == LOW && lastSelectState == HIGH) {
    menuSelect(selectedItem);
    delay(200);  // debounce
  }
  lastSelectState = currentSelectState;
}
//testing parker branch