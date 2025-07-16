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
    case Game_List:
      drawGameList();
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
      settingsPage();
      break;
    case 2:  // About
      currentScreen = About;
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



// void drawSettingsPage() {  
//   tft.fillScreen(TFT_BLACK);
//   tft.setTextColor(TFT_WHITE);
//   tft.setTextSize(4);
//   tft.setCursor(10, 10);
//   tft.println("Settings");

//   for (int i = 0; i < 4; i++) {
//     int y = 20 + i * 30; // Establishing where the cursor will be on the y axis, after a selected item

//     if (i == selectedItem) {
//       tft.setCursor(10, y);
//       tft.print(">");
//     } else {
//       tft.setCursor(10, y);
//       tft.print(" ");
//     }

//     tft.setCursor(20, y);
//     tft.print(settingsItems[i]);
//   }}
void settingsPage() {
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(4);
  tft.setCursor(10,10);
  tft.println("Settings");
  tft.setTextSize(2);
  tft.setCursor(10, 50);
  tft.println("Brightness");
  tft.setCursor(10, 80);
  tft.println("Volume");
  tft.setCursor(10, 110);
  tft.println("Controls ");
  delay(2000); // Display for 2 seconds
  currentScreen = Main_Menu;
  drawMenu(); // Return to main menu
}


void handleSelect() {
  switch (currentScreen) {
    case Main_Menu:
      menuSelect(selectedItem);
      break;
    case Game_List:
      gameSelect(selectedItem);}}

// void menuSelect(int selectedItem) {
//   switch (selectedItem) {
//     case 0:  // My Games
//       break;
//     case 1:  // Settings
//       currentScreen = Settings;
//       drawSettingsPage();

//       break;
//     case Settings:
//       // implement settings selection logic here
//       break;
//     default:
//       break;
//   }
// }




