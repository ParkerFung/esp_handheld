#include "gameList.h"
#include "main.h"
#include "pong.h"

void drawGameList() {
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(3);
  tft.setCursor(20, 10);
  tft.println("Games");

  for (int i = 0; i < gamesCount; i++) {
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
    case 0: { // Pong
      currentScreen = Playing;

      // Optional: Show a brief start message
      tft.fillScreen(TFT_BLACK);
      tft.setTextColor(TFT_WHITE);
      tft.setTextSize(2);
      tft.setCursor(40, 100);
      tft.println("Press any button");
      tft.setCursor(60, 130);
      tft.println("to start Pong");

      delay(1000);  // Short pause before game starts

      // Game will be initialized in loop()
      break;
    }

    case 1:
      // Add setup call for future game
      break;

    case 2:
      // Add setup call for future game
      break;

    default:
      break;
  }
}
