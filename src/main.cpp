#include <TFT_eSPI.h>  // Include the graphics library
#include <SPI.h>
#include "main.h"

TFT_eSPI tft = TFT_eSPI();  // Create TFT instance
void setup() {
  tft.init();               // Initialize the display
  tft.setRotation(3);       // Rotate display: 0-3 depending on orientation

  drawMenu();
}

void loop() {
  // Nothing here for now
}


void drawMenu(){

  tft.fillScreen(TFT_SKYBLUE);
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(3);
  tft.setTextFont(1);
  tft.println("Main Menu\n\n");

  tft.setTextSize(1);

  tft.println("My Games\n");
  tft.println("Settings\n");
  tft.println("About");

}