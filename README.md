# ESP32 Handheld Game Console - My First Project!

---

This is my first ESP32 project! I built a handheld game console that can play classic games like Pong. It uses an ESP32-S3 chip with a small TFT display and some buttons.

## What It Is
- A small handheld game device  
- Built with ESP32-S3 WROOM-1 microcontroller  
- Uses a TFT ST7789 display (320x240 pixels)  
- Has 5 buttons for controls  
- Can play Pong (more games coming later)  

## Hardware Needed
- ESP32-S3 development board  
- TFT ST7789 display module  
- 5 push buttons  
- Some jumper wires  
- Breadboard (for testing)  

## Button Connections
| Button    | GPIO Pin |
|-----------|----------|
| Up        | 10       |
| Down      | 21       |
| Left      | 11       |
| Select/A  | 12       |
| B         | 9        |


## TFT Display Pin Connections

The TFT display is connected to the ESP32-S3 with the following pins:

| TFT Pin  | ESP32 GPIO Pin |
| -------- | -------------- |
| TFT_CS   | 5              |
| TFT_DC   | 2              |
| TFT_RST  | 4              |
| TFT_MOSI | 17             |
| TFT_SCLK | 18             |
| TFT_BL   | 15             |

Make sure these pins match the configuration in your `User_Setup.h` file for the TFT_eSPI library.  
Connect buttons between the GPIO pins and ground. The code uses internal pull-up resistors.

---

## What It Can Do
- Navigate through menus with up/down buttons  
- Select games with the A button  
- Play Pong against a computer opponent  
- Keep score during games  
- Exit games with the B button  

## Menu System
When you turn it on, you get a main menu with:  
- Game List (currently just Pong)  
- Settings (doesn't work yet)  
- About page  

## Current Games

### Pong
- Classic paddle game  
- You control the left paddle  
- Computer controls the right paddle  
- Try to hit the ball past the computer!  
- Three difficulty levels (but they're not fully working yet)  

**How to play Pong:**  
- Up/Down buttons: Move your paddle  
- B button: Go back to menu  

---

## Project Files
- `main.h` — Main header file with all the settings and global declarations  
- `main.cpp` — Main program that runs the menus and game loop  
- `input.cpp` — Handles button presses in menus  
- `game_input.cpp` — Handles button presses during gameplay  
- `pong.h` / `pong.cpp` — Pong game logic and drawing functions  
- `menu.h` / `menu.cpp` — Menu system drawing and selection handling  
- `gameList.h` / `gameList.cpp` — Game list display and game launching  
- `platformio.ini` — Build settings for PlatformIO  

---

## How to Build It
1. Install PlatformIO (I used the VS Code extension)  
2. Open this project folder  
3. Connect your ESP32 board  
4. Click "Upload" in PlatformIO  
5. The TFT_eSPI library gets installed automatically  

---

## What I Learned
- How to use ESP32 GPIO pins  
- How to control a TFT display  
- How to handle button inputs without bouncing  
- How to structure a menu system  
- How to make simple games  

---

## Things That Work
- Menu navigation with buttons  
- Pong game plays smoothly  
- Score tracking  
- Display graphics and text  

---

## Things Still Learning/Fixing
- Settings menu (brightness, volume, etc.)  
- Difficulty levels in Pong  
- Adding sound effects  
- Making the AI paddle smarter  
- Adding more games  

---

## Problems I Solved
- Button bouncing: Used delays and edge detection  
- Menu wrapping: Used modulo math to loop around  
- Game input: Made separate input system for games vs menus  
- Display flickering: Clear old graphics before drawing new ones  

---

## How the Code Works

### Main Loop
- Reads button inputs  
- Updates the current screen (menu or game)  
- Draws everything to the display  
- Repeats forever  

### Menu System
- Uses arrays to store menu items  
- Tracks which item is selected  
- Moves selection up/down with buttons  
- Calls different functions when items are selected  

### Game System
Each game has three functions:  
- Setup: Start the game  
- Update: Handle input and game logic  
- Draw: Show graphics on screen  

### Input Handling
- Menu inputs use edge detection (press once = one action)  
- Game inputs allow holding buttons for smooth movement  
- Both systems prevent button bouncing  

**Explanation:**  
The project uses two different input methods to handle button presses in menus versus gameplay.  
- **Menu Input (Edge Detection):** Buttons respond only once per press to prevent repeated scrolling or selecting when held down.  
- **Gameplay Input (Hold Detection):** Holding buttons causes continuous movement for smoother control in games like Pong.  

This separation ensures intuitive control behavior depending on context.

---

## What I Would Do Differently

- Organize the project directory more efficiently from the start to make navigation and maintenance easier  
- Plan the game and menu architecture with clearer separation between UI and game logic  
- Use more modular code to simplify adding new games and features  
- Spend more time on input handling abstraction for cleaner, reusable code  

---

## How to Add a New Game

To add a new game to the console:  
1. Create new source files (e.g., `newgame.h` and `newgame.cpp`).  
2. Implement three main functions:  
   - **Setup:** Initialize game variables and graphics.  
   - **Update:** Handle inputs and game logic each frame.  
   - **Draw:** Render the current game state to the display.  
3. Add the game's name to the game list array in `gameList.cpp`.  
4. Register the game’s function pointers (setup, update, draw) so the main loop and menu can call them.  
5. Update the menu system if needed to include the new game.  

---

## Development Environment

- Built using **PlatformIO** with the **Arduino framework** for ESP32.  
- Open in Visual Studio Code with the PlatformIO extension.  
- Uses **TFT_eSPI** library for display control.  
- Alternatively, can be adapted for **ESP-IDF**, though some code changes are needed.  

---

## TFT Display Configuration Reminder

Make sure your GPIO pin assignments in the `User_Setup.h` file of the TFT_eSPI library exactly match your hardware wiring. Incorrect pin configs will cause the display not to work.

---

## Possible Improvements and Future Refactoring Ideas

- **Input Handling:** Refactor menu and game inputs into a cleaner, reusable input abstraction to reduce duplicate code and improve maintainability.  
- **Graphics Rendering:** Currently erasing and redrawing graphics every frame reduces flicker, but implementing double buffering or partial screen updates would produce smoother animations.  
- **Settings Menu:** Add actual control over brightness (using PWM), volume (e.g., DAC), and button remapping instead of placeholder options.  
- **Game Architecture:** Introduce a game manager class or struct holding function pointers and game states for better scalability and cleaner main loop/menu code.  

---

## Future Plans
- Add Tetris game  
- Add Snake game  
- Get the settings menu working  
- Add sound effects  
- Maybe add a battery and charge meter  

---

## Tips for Beginners
- Start simple and add features slowly  
- Use lots of comments to remember what code does  
- Test on hardware frequently  

---

## Common Problems
- Display not working: Check your wiring and TFT_eSPI config  
- Buttons not responding: Make sure they're wired to the right pins  
- Code won't compile: Check that all files are in the right place  
- Games running slow: The ESP32 is pretty fast, probably a code issue  

---

## Libraries Used
- TFT_eSPI: For controlling the display  
- Arduino Framework: For basic ESP32 functions  

---

This project taught me a lot about embedded programming and game development. It's not perfect, but it works and was fun to build!

---

**Created by Parker Fung & Weston Fung**  
My First ESP32 Project
