#ifndef MAIN_H
#define MAIN_H

#include <TFT_eSPI.h>

// External global declarations
extern TFT_eSPI tft;
extern const char* menuItems[];
extern int selectedItem;
extern bool lastButtonState;
extern bool lastSelectState;
extern bool lastUpState; 

// Button pins
#define BUTTON_DOWN 21
#define BUTTON_SELECT 15
#define BUTTON_UP 10

// Function declarations
void drawMenu();
void aboutPage();
void menuSelect(int selectedItem);
void downButton();
void upButton();
void selectButton();
void settingsPage();

#endif
