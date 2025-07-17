#include <Arduino.h>
#include "main.h"
#include "game_input.h"


#include "main.h"
#include "game_input.h"

int handleGameInput(int* x, int* y) {
  int action = 0;  // 0 = no action, 1 = exit

  // Movement
  if (digitalRead(BUTTON_UP) == LOW) {
    (*y) -= 1;
  }
  if (digitalRead(BUTTON_DOWN) == LOW) {
    (*y) += 1;
  }

  // B button (exit game) — edge detected
  static bool lastBState = HIGH;
  bool currentBState = digitalRead(BUTTON_B);

  static bool initialized = false;
  if (!initialized) {
    // Avoid false triggering on first call by syncing lastBState
    lastBState = currentBState;
    initialized = true;
  }

  if (currentBState == LOW && lastBState == HIGH) {
    action = 1;
  }
  lastBState = currentBState;

  return action;
}
