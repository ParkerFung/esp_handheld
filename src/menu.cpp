#include "main.h"


void drawMenu(currentState state) {
  switch(state){
    case Main_Menu:
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
  drawMenu(currentScreen);  // Return to menu
}


void drawSettingsPage() {  
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(4);
  tft.setCursor(10, 10);
  tft.println("Settings");

  for (int i = 0; i < 4; i++) {
    int y = 20 + i * 30; // Establishing where the cursor will be on the y axis, after a selected item //

    if (i == selectedItem) {
      tft.setCursor(10, y);
      tft.print(">");
    } else {
      tft.setCursor(10, y);
      tft.print(" ");
    }

    tft.setCursor(20, y);
    tft.print(settingsItems[i]);
  }}

// void settingsPage() {
//     tft.fillScreen(TFT_BLACK);
//     tft.setTextColor(TFT_WHITE);
//     tft.setTextSize(4);
//     tft.setCursor(10,10);
//     tft.println("Settings");
//     tft.setTextSize(2);
//     tft.setCursor(10, 50);
//     tft.println("Brightness");
//     tft.setCursor(10, 80);
//     tft.println("Volume");
//     tft.setCursor(10, 110);
//     tft.println("Controls ");
//     tft.setCursor(10, 140);
//     tft.println("Back to Menu");
//     delay(2000); // Display for 2 seconds
//     drawMenu(); // Return to main menu
// }

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
  drawMenu(currentScreen); // Return to main menu
}


void menuSelect(int selectedItem) {
  switch (selectedItem) {
    case 1:
      currentScreen = Settings;
      settingsPage();
      break;
    case 2:
      aboutPage();
      break;
    default:
      return;
  }
}


// void settingsSelect(int selectedItem) {
//   switch (selectedItem) {
//     case 1:

//   }
// }

