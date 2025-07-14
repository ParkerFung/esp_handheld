#include <Arduino.h>
#include "main.h"
#include "game_input.h"

int x = 100;
int y = 100;

int* xPtr = &x;
int* yPtr = &y;

void sampleGame(){
  tft.fillScreen(TFT_BLACK);
  tft.fillCircle(x,y, 50, TFT_GREEN);
    // down button
  bool currentDownState = digitalRead(BUTTON_DOWN);
  if (currentDownState == LOW && lastDownState == HIGH) {
    handleGameInput(xPtr,yPtr);
    drawGameScreen(x,y);
    // delay(200);
  }
  lastDownState = currentDownState;

}

void drawGameScreen(int x, int y){


    tft.fillScreen(TFT_BLACK);
    tft.fillCircle(x,y, 50, TFT_GREEN);



}