#ifndef MAIN_H
#define MAIN_H

#include <TFT_eSPI.h>

// External global declarations
extern TFT_eSPI tft;

extern const char* menuItems[];
extern const int menuItemsCount;

extern const char* settingsItems[];
extern const int settingsItemsCount;

extern const char* games[];
extern const int gamesCount;

enum currentState {Main_Menu, Game_List, Settings, About, Playing};

extern int selectedItem;
extern bool lastDownState;
extern bool lastSelectState;
extern bool lastUpState;
extern bool lastLeftState;
extern currentState currentScreen;

// Button pins
#define BUTTON_DOWN 21
#define BUTTON_SELECT 7
#define BUTTON_UP 10
#define BUTTON_LEFT 11
#define BUTTON_A 15
#define BUTTON_B 16

// Function declarations
void drawSettingsPage();
void drawScreen(currentState);
void drawMenu();
void drawGameList();
void aboutPage();
void inputs();
void menuSelect(int selectedItem);
void settingsPage();
void launchEmulator(const char* romPath);
void gameSelect(int selectedItem);
void handleSelect();
int getMenuSize(currentState screen);
void sampleGame();

#endif
