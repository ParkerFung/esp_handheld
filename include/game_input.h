#ifndef GAME_INPUT_H
#define GAME_INPUT_H

// Returns:
// 0 = no action
// 1 = exit game (B button pressed)
int handleGameInput(int* x, int* y);

// Optional: if used to draw player/game state
void drawGameScreen(int x, int y);

#endif
