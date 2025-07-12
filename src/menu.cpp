#include "main.h"

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
  tft.setTextColor(TFT_YELLOW);
  tft.setTextSize(2);
  tft.println("About this device");
  tft.setTextSize(1);
  tft.println("Made with ESP32 + TFT!");
  delay(2000);
  drawMenu();  // Return to menu
}

void menuSelect(int selectedItem) {
  switch (selectedItem) {
    case 2:
      aboutPage();
      break;
    default:
      return;
  }
}
