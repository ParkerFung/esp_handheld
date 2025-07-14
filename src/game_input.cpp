#include <Arduino.h>
#include "main.h"
#include "game_input.h"

int handleGameInput(int* x, int* y){

 // down button
  bool currentDownState = digitalRead(BUTTON_DOWN);
  if (currentDownState == LOW && lastDownState == HIGH) {
    y--;
    // delay(200);
  }
  lastDownState = currentDownState;

//   // up button
//   bool currentUpState = digitalRead(BUTTON_UP);
//   if (currentUpState == LOW && lastUpState == HIGH) {

//     // delay(200);
//   }
//   lastUpState = currentUpState;

//   // right button
//   bool currentSelectState = digitalRead(BUTTON_SELECT);
//   if (currentSelectState == LOW && lastSelectState == HIGH) {

//     // delay(200);
//   }
//   lastSelectState = currentSelectState;

//     // left button
//   bool currentLeftState = digitalRead(BUTTON_LEFT);
//   if (currentLeftState == LOW && lastLeftState == HIGH) {

//     // delay(200);
//   }
//   lastUpState = currentUpState;

}
