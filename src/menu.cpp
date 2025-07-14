#include "main.h"

void drawScreen(currentState state){
  switch(state){
    case Main_Menu:
      drawMenu();
      break;
    case Settings:
      drawSettingsPage();
      break;
    case About:
      aboutPage();
      break;
    default: return;
  }
}


void drawMenu() {
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(3);
  tft.setCursor(20, 10);
  tft.println("Main Menu");
  
  for (int i = 0; i < 3; i++) {
    int y = 50 + i * 30;


    if (i == selectedItem) {
      tft.setCursor(10, y);
      tft.print(">");
    } else {
      tft.setCursor(10, y);
      tft.print(" ");
    }

    tft.setCursor(30, y);
    tft.print(menuItems[i]);
  }
}

void aboutPage() {
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(10, 30);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.println("About this device");
  tft.setTextSize(1);
  tft.println("Made with ESP32 + TFT!");
  delay(2000);
  currentScreen = Main_Menu;
  drawMenu();  // Return to menu
}

void menuSelect(int selectedItem) {
  switch (selectedItem) {
    case 0:  // My Games
      break;
    case 1:  // Settings
      currentScreen = Settings;
      drawSettingsPage();
      break;
    case 2:  // About
      currentScreen = About;
      aboutPage();
      break;
    default:
      return;
  }
}



