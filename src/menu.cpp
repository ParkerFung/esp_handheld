#include "menu.h"

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
    case Game_List:
      drawGameList();
      break;
    default:
      return;
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
      tft.setTextColor(TFT_GREEN);
      tft.setCursor(10, y);
      tft.print(">");
    } else {
      tft.setTextColor(TFT_WHITE);
      tft.setCursor(10, y);
      tft.print(" ");
    }

    tft.setCursor(30, y);
    tft.print(menuItems[i]);
  }
}

void menuSelect(int selectedItem) {
  switch (selectedItem) {
    case 0:
      currentScreen = Game_List;
      drawGameList();  // My Games
      break;
    case 1:  // Settings
      currentScreen = Settings;
      selectedItem = 0;
      drawSettingsPage();
      break;
    case 2:  // About
      currentScreen = About;
      selectedItem = 0;
      aboutPage();
      break;
    default:
      return;
  }
}


void aboutPage() {
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(10, 30);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(3);
  tft.println("This device was  ");
  tft.println("created with an ");
  tft.println("ESP32 by Parker ");
  tft.println("and Weston Fung");
  delay(5000);
  currentScreen = Main_Menu;
  drawMenu();  // Return to menu
}

void handleSelect() {
  currentState previousScreen = currentScreen;

  switch (currentScreen) {
    case Main_Menu:
      menuSelect(selectedItem);
      break;
    case Game_List:
      gameSelect(selectedItem);
      break;
    case Settings:
      settingSelect(selectedItem);
      break;
  }

  // Only reset if screen hasn't switched to gameplay
  if (currentScreen != Playing) {
    selectedItem = 0;
  }
}





