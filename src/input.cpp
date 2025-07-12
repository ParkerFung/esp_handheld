#include "main.h"

void inputs(int menuSize){
  //down button
  bool currentButtonState = digitalRead(BUTTON_DOWN);
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    selectedItem = (selectedItem + 1) % menuSize;
    // drawMenu();
    delay(200);  // debounce
  }
  lastButtonState = currentButtonState;


  //up button
  bool currentUpState = digitalRead(BUTTON_UP);
  if(currentUpState == LOW && lastUpState == HIGH){
    if(selectedItem <= 0){
      selectedItem = menuSize - 1;
    }
    else{
      selectedItem = (selectedItem - 1) % menuSize;
    }
    // drawMenu();
    delay(200);
  }
  lastUpState = currentUpState;

  //select button 
  bool currentSelectState = digitalRead(BUTTON_SELECT);
  if (currentSelectState == LOW && lastSelectState == HIGH) {
    menuSelect(selectedItem);
    delay(200);  // debounce
  }
  lastSelectState = currentSelectState;

}

// void downButton(int menuSize) {
//   bool currentButtonState = digitalRead(BUTTON_DOWN);
//   if (currentButtonState == LOW && lastButtonState == HIGH) {
//     selectedItem = (selectedItem + 1) % menuSize;
//     drawMenu();
//     delay(200);  // debounce
//   }
//   lastButtonState = currentButtonState;
// }





// void upButton(int menuSize){
//   bool currentUpState = digitalRead(BUTTON_UP);
//   if(currentUpState == LOW && lastUpState == HIGH){
//     if(selectedItem <= 0){
//       selectedItem = menuSize - 1;
//     }
//     else{
//       selectedItem = (selectedItem - 1) % menuSize;
//     }
//     drawMenu();
//     delay(200);
//   }
//   lastUpState = currentUpState;
// }

//select button

// void selectButton() {
//   bool currentSelectState = digitalRead(BUTTON_SELECT);
//   if (currentSelectState == LOW && lastSelectState == HIGH) {
//     menuSelect(selectedItem);
//     delay(200);  // debounce
//   }
//   lastSelectState = currentSelectState;
// }
//testing parker branch