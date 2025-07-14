#include "main.h"



void drawGameList() {
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(3);
  tft.setCursor(20, 10);
  tft.println("Games");
  
  for (int i = 0; i < 4; i++) {
    int y = 50 + i * 30;


    if (i == selectedItem) {
      tft.setCursor(10, y);
      tft.setTextColor(TFT_GREEN);
      tft.print(">");
    } else {
      tft.setCursor(10, y);
      tft.setTextColor(TFT_WHITE);
      tft.print(" ");
    }

    tft.setCursor(30, y);
    tft.print(games[i]);
  }
}

void gameSelect(int selectedItem) {
  switch (selectedItem) {
    case 0: 
        currentScreen = Playing;
        sampleGame();
      break;
    case 1:
      break;
    case 2:
      break;
    default:
      return;
  }
}