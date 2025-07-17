#ifndef MAIN_H
#define MAIN_H

#include <TFT_eSPI.h>
#include "pong.h"

// Enum for screen navigation
enum currentState {
  Main_Menu,
  Settings,
  About,
  Game_List,
  Playing
};

enum settingsOptions {
  BRIGHTNESS,
  VOLUME,
  CONTROLS,
  MAIN_MENU
};

// Global display object
extern TFT_eSPI tft;

// Menu and UI globals
extern const char* menuItems[];
extern const int menuItemsCount;

extern const char* settingsItems[];
extern const int settingsItemsCount;

extern const char* settingsLabels[];

extern const char* games[];
extern const int gamesCount;

// Global state variables
extern int selectedItem;
extern currentState currentScreen;

// Button states (for edge detection)
extern bool lastDownState;
extern bool lastSelectState;
extern bool lastUpState;
extern bool lastLeftState;

// Button pin definitions (adjust as needed)
#define BUTTON_DOWN   21
#define BUTTON_UP     10
#define BUTTON_LEFT   11
#define BUTTON_B       9
#define BUTTON_SELECT 12
#define BUTTON_A BUTTON_SELECT  // Alias

// Function declarations
void drawSettingsPage();
void settingSelect(int selectedItem);
void drawScreen(currentState);
void drawMenu();
void drawGameList();
void aboutPage();
void inputs();
void menuSelect(int selectedItem);
void launchEmulator(const char* romPath);
void gameSelect(int selectedItem);
void handleSelect();
int getMenuSize(currentState screen);

#endif
