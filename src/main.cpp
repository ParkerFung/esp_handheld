#include <TFT_eSPI.h>  // Include the graphics library
#include <SPI.h>
#include "main.h"

const char* menuItems[] = {"My Games", "Settings", "About!!"};
int selectedItem = 0;
bool lastButtonState = HIGH;
bool lastSelectState = HIGH;
#define BUTTON_DOWN 21
#define BUTTON_SELECT 15

TFT_eSPI tft = TFT_eSPI();  // Create TFT instance

void setup() {
  tft.init();
  tft.setRotation(3);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_SELECT, INPUT_PULLUP);  // <== Add this
  drawMenu();
}


void loop() {
  downButton();
  selectButton();  // <== handle SELECT press
}


void drawMenu() {
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(3);
  tft.setCursor(20, 10);
  tft.println("Main Menu");

  // Draw menu items at fixed Y positions
  for (int i = 0; i < 3; i++) {
    int y = 50 + i * 30;
    
    // Highlight or draw arrow
    if (i == selectedItem) {
      tft.setCursor(10, y);
      tft.print(">");
    } else {
      tft.setCursor(10, y);
      tft.print(" ");  // Erase any previous arrow
    }

    // Draw menu label
    tft.setCursor(30, y);
    tft.print(menuItems[i]);
  }
}

void aboutPage(){
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(10, 30);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.println("This device was created");
  tft.println(" with an ESP32");
  tft.println("by Parker and Weston Fung!!");

  delay(5000);

  drawMenu();
}

void menuSelect(int selectedItem){
  switch(selectedItem){
    case 2:
      aboutPage();
      break;
    default: return;

  }
}

void downButton(){
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
    // Button SELECT just pressed
    menuSelect(selectedItem);
    delay(200);  // debounce
  }
  lastSelectState = currentSelectState;
}