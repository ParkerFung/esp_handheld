#include "main.h"

void drawSettingsPage() {  
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("Settings");

  for (int i = 0; i < 4; i++) {
    int y = 40 + i * 30; // Establishing where the cursor will be on the y axis, after a selected item //

    if (i == selectedItem) {
      tft.setCursor(15, y);
      tft.print(">");
    } else {
      tft.setCursor(15, y);
      tft.print(" ");
    }

    tft.setCursor(30, y);
    tft.print(settingsLabels[i]);
  }
}

void settingSelect(int selectedItem) {
    switch (selectedItem) {
        case BRIGHTNESS:
        // Open brightness settings
        break;
        case VOLUME:
        // Open volume settings
        break;
        case CONTROLS:
        // Open controls settings
        break;
        case MAIN_MENU:
          currentScreen = Main_Menu;
          drawMenu();
        // Returns to main menu
        break;

    }
}

