#ifndef PONG_H
#define PONG_H

#include <TFT_eSPI.h>

enum PongDifficulty {
  EASY,
  MEDIUM,
  HARD
};

// Setup pong with difficulty and initialize screen
void pongSetup(TFT_eSPI& tft, PongDifficulty difficulty);

// Advance game logic, return false if game should exit
bool pongUpdate(TFT_eSPI& tft);

// Draw updated frame
void pongDraw(TFT_eSPI& tft);

#endif
