#ifndef MAIN_H
#define MAIN_H

#include <TFT_eSPI.h>

// External global declarations
extern TFT_eSPI tft;
extern const char* menuItems[];

extern const char* settingsItems[];

extern const char* games[];

enum currentState {Main_Menu, Settings, About};

extern int selectedItem;
extern bool lastButtonState;
extern bool lastSelectState;
extern bool lastUpState;
extern currentState currentScreen;

// Button pins
#define BUTTON_DOWN 21
#define BUTTON_SELECT 15
#define BUTTON_UP 10

// Function declarations


void drawSettingsPage();
void drawScreen(currentState);
void drawMenu();

void aboutPage();
void inputs(int menuSize);
void menuSelect(int selectedItem);
void settingsPage();
void launchEmulator(const char* romPath);

#endif
