// #include "pong.h"
// #include "main.h"
// #include "game_input.h"

// // Constants
// static constexpr int WIDTH = 320;
// static constexpr int HEIGHT = 240;
// static constexpr int PWIDTH = 10;
// static constexpr int BSIZE = 6;
// static constexpr int PSPEED = 5;

// // Game state variables
// static int p1Y, p2Y;
// static int ballX, ballY;
// static int vx, vy;
// static int p2X;
// static int pHeight;
// static int ballSpeed;
// static int scoreP, scoreAI;

// // Previous positions for clearing
// static int prevP1Y, prevP2Y, prevBallX, prevBallY;

// static unsigned long startTime;
// static constexpr unsigned long gracePeriod = 1000; // 1 second grace period

// static PongDifficulty currentDifficulty;

// // Keep track of last score drawn to update UI only when needed
// static int lastScoreP = -1;
// static int lastScoreAI = -1;

// void drawScoreboard(TFT_eSPI& tft) {
//   // Draw score with background to make it always visible
//   tft.setTextColor(TFT_WHITE, TFT_BLACK);
//   tft.setTextSize(2);
  
//   // Calculate text position
//   int textX = WIDTH / 2 - 50;
//   int textY = 5;
  
//   // Draw background rectangle for score
//   tft.fillRect(textX - 5, textY - 2, 100, 20, TFT_BLACK);
  
//   // Draw the score text
//   tft.setCursor(textX, textY);
//   tft.printf("P:%d  AI:%d", scoreP, scoreAI);
  
//   lastScoreP = scoreP;
//   lastScoreAI = scoreAI;
// }

// void pongSetup(TFT_eSPI& tft, PongDifficulty difficulty) {
//   currentDifficulty = HARD;

//   switch (difficulty) {
//     case EASY:   ballSpeed = 2; pHeight = 60; break;
//     case MEDIUM: ballSpeed = 3; pHeight = 50; break;
//     case HARD:   ballSpeed = 4; pHeight = 35; break;
//   }

//   // Use full screen height
//   p1Y = HEIGHT / 2 - pHeight / 2;
//   p2Y = p1Y;
//   ballX = WIDTH / 2;
//   ballY = HEIGHT / 2;
//   vx = ballSpeed;
//   vy = ballSpeed;
//   p2X = WIDTH - PWIDTH - 10;

//   scoreP = 0;
//   scoreAI = 0;

//   prevP1Y = p1Y;
//   prevP2Y = p2Y;
//   prevBallX = ballX;
//   prevBallY = ballY;

//   lastScoreP = -1; // Force score redraw on setup
//   lastScoreAI = -1;

//   startTime = millis();

//   // Clear screen
//   tft.fillScreen(TFT_BLACK);

//   // Draw initial scoreboard
//   drawScoreboard(tft);

//   // Draw initial paddles and ball
//   tft.fillRect(10, p1Y, PWIDTH, pHeight, TFT_WHITE);
//   tft.fillRect(p2X, p2Y, PWIDTH, pHeight, TFT_WHITE);
//   tft.fillCircle(ballX, ballY, BSIZE, TFT_WHITE);
// }

// bool pongUpdate(TFT_eSPI& tft) {
//   // Handle input
//   int dummy = 0, moveY = 0;
//   int inputResult = handleGameInput(&dummy, &moveY);

//   // Ignore exit during grace period
//   if (millis() - startTime < gracePeriod) {
//     inputResult = 0;
//   }

//   // Save previous positions
//   prevP1Y = p1Y;
//   prevP2Y = p2Y;
//   prevBallX = ballX;
//   prevBallY = ballY;

//   // Update player paddle position (full screen height)
//   p1Y = constrain(p1Y + moveY * PSPEED, 0, HEIGHT - pHeight);

//   // Faster AI paddle follows ball (full screen height)
//   if (ballY < p2Y + pHeight / 2) p2Y -= 2;
//   else if (ballY > p2Y + pHeight / 2) p2Y += 2;
//   p2Y = constrain(p2Y, 0, HEIGHT - pHeight);

//   // Move ball
//   ballX += vx;
//   ballY += vy;

//   // Bounce ball off top and bottom of full screen
//   if (ballY <= 0 || ballY + BSIZE >= HEIGHT) {
//     vy = -vy;
//   }

//   // Bounce ball off paddles
//   if (ballX <= 10 + PWIDTH && ballY + BSIZE >= p1Y && ballY <= p1Y + pHeight) {
//     vx = -vx;
//     ballX = 10 + PWIDTH; // Prevent sticking
//   }
//   if (ballX + BSIZE >= p2X && ballY + BSIZE >= p2Y && ballY <= p2Y + pHeight) {
//     vx = -vx;
//     ballX = p2X - BSIZE; // Prevent sticking
//   }

//   // Check scoring
//   bool scored = false;
//   if (ballX < 0) {
//     scoreAI++;
//     scored = true;
//   } else if (ballX > WIDTH) {
//     scoreP++;
//     scored = true;
//   }

//   if (scored) {
//     // Reset ball and paddles
//     ballX = WIDTH / 2;
//     ballY = HEIGHT / 2;
//     vx = (scoreP > scoreAI) ? -ballSpeed : ballSpeed;
//     vy = ballSpeed;

//     p1Y = HEIGHT / 2 - pHeight / 2;
//     p2Y = p1Y;
//   }

//   // Exit game if requested (after grace period)
//   if (inputResult == 1) {
//     return false;
//   }

//   return true;
// }

// void pongDraw(TFT_eSPI& tft) {
//   // Clear previous positions
//   tft.fillRect(10, prevP1Y, PWIDTH, pHeight, TFT_BLACK);
//   tft.fillRect(p2X, prevP2Y, PWIDTH, pHeight, TFT_BLACK);
//   tft.fillCircle(prevBallX, prevBallY, BSIZE, TFT_BLACK);

//   // Draw new positions
//   tft.fillRect(10, p1Y, PWIDTH, pHeight, TFT_WHITE);
//   tft.fillRect(p2X, p2Y, PWIDTH, pHeight, TFT_WHITE);
//   tft.fillCircle(ballX, ballY, BSIZE, TFT_WHITE);

//   // Always redraw scoreboard so it stays on top
//   drawScoreboard(tft);
// }

#include "pong.h"
#include "main.h"
#include "game_input.h"

// Screen dimensions
int screenWidth = 320;
int screenHeight = 240;

// Paddle settings
int paddleWidth = 10;
int paddleHeight = 35;  // This will change based on difficulty
int paddleSpeed = 5;

// Ball settings
int ballSize = 6;
int ballSpeed = 4;  // This will change based on difficulty

// Player paddle position
int playerPaddleY = 0;

// Computer paddle position
int computerPaddleY = 0;
int computerPaddleX = 0;  // X position of computer paddle

// Ball position and movement
int ballX = 0;
int ballY = 0;
int ballDirectionX = 0;  // -1 for left, 1 for right
int ballDirectionY = 0;  // -1 for up, 1 for down

// Game scores
int playerScore = 0;
int computerScore = 0;

// Previous positions (needed to erase old graphics)
int oldPlayerPaddleY = 0;
int oldComputerPaddleY = 0;
int oldBallX = 0;
int oldBallY = 0;

// Game timing
unsigned long gameStartTime = 0;
unsigned long waitTimeAfterStart = 1000;  // Wait 1 second before allowing exit

// Difficulty setting
PongDifficulty gameDifficulty;

// Track last drawn scores to avoid redrawing unnecessarily
int lastPlayerScore = -1;
int lastComputerScore = -1;

// Function to draw the score at the top of the screen
void drawGameScore(TFT_eSPI& display) {
  // Set text color to white with black background
  display.setTextColor(TFT_WHITE, TFT_BLACK);
  display.setTextSize(2);
  
  // Calculate where to put the score text
  int scoreTextX = screenWidth / 2 - 50;
  int scoreTextY = 5;
  
  // Draw a black rectangle behind the score to make it visible
  display.fillRect(scoreTextX - 5, scoreTextY - 2, 100, 20, TFT_BLACK);
  
  // Draw the actual score text
  display.setCursor(scoreTextX, scoreTextY);
  display.printf("P:%d  AI:%d", playerScore, computerScore);
  
  // Remember what scores we just drew
  lastPlayerScore = playerScore;
  lastComputerScore = computerScore;
}

// Function to set up the game when it starts
void pongSetup(TFT_eSPI& display, PongDifficulty difficulty) {
  // Set the difficulty (this line seems to force HARD mode)
  gameDifficulty = HARD;

  // Set game speed and paddle size based on difficulty
  if (difficulty == EASY) {
    ballSpeed = 2;
    paddleHeight = 60;  // Bigger paddle = easier
  } else if (difficulty == MEDIUM) {
    ballSpeed = 3;
    paddleHeight = 50;
  } else {  // HARD difficulty
    ballSpeed = 4;
    paddleHeight = 35;  // Smaller paddle = harder
  }

  // Put both paddles in the middle of the screen
  playerPaddleY = screenHeight / 2 - paddleHeight / 2;
  computerPaddleY = playerPaddleY;
  
  // Put ball in center of screen
  ballX = screenWidth / 2;
  ballY = screenHeight / 2;
  
  // Ball starts moving right and down
  ballDirectionX = ballSpeed;
  ballDirectionY = ballSpeed;
  
  // Computer paddle is on the right side
  computerPaddleX = screenWidth - paddleWidth - 10;

  // Start with no points
  playerScore = 0;
  computerScore = 0;

  // Remember starting positions for erasing later
  oldPlayerPaddleY = playerPaddleY;
  oldComputerPaddleY = computerPaddleY;
  oldBallX = ballX;
  oldBallY = ballY;

  // Force score to be redrawn when game starts
  lastPlayerScore = -1;
  lastComputerScore = -1;

  // Remember when the game started
  gameStartTime = millis();

  // Clear the entire screen to black
  display.fillScreen(TFT_BLACK);

  // Draw the starting score
  drawGameScore(display);

  // Draw the starting paddles and ball
  display.fillRect(10, playerPaddleY, paddleWidth, paddleHeight, TFT_WHITE);
  display.fillRect(computerPaddleX, computerPaddleY, paddleWidth, paddleHeight, TFT_WHITE);
  display.fillCircle(ballX, ballY, ballSize, TFT_WHITE);
}

// Function that runs every frame to update the game
bool pongUpdate(TFT_eSPI& display) {
  // Get input from the player
  int unusedValue = 0;
  int playerMovement = 0;  // Will be -1 for up, 1 for down, 0 for no movement
  int exitGamePressed = handleGameInput(&unusedValue, &playerMovement);

  // Don't allow exiting the game for the first second
  if (millis() - gameStartTime < waitTimeAfterStart) {
    exitGamePressed = 0;
  }

  // Save current positions so we can erase them later
  oldPlayerPaddleY = playerPaddleY;
  oldComputerPaddleY = computerPaddleY;
  oldBallX = ballX;
  oldBallY = ballY;

  // Move the player's paddle up or down
  playerPaddleY = playerPaddleY + (playerMovement * paddleSpeed);
  
  // Make sure player paddle doesn't go off screen
  if (playerPaddleY < 0) {
    playerPaddleY = 0;
  }
  if (playerPaddleY > screenHeight - paddleHeight) {
    playerPaddleY = screenHeight - paddleHeight;
  }

  // Computer AI: move paddle toward the ball
  int computerPaddleCenter = computerPaddleY + paddleHeight / 2;
  
  if (ballY < computerPaddleCenter) {
    computerPaddleY = computerPaddleY - 2;  // Move up (faster AI)
  } else if (ballY > computerPaddleCenter) {
    computerPaddleY = computerPaddleY + 2;  // Move down (faster AI)
  }
  
  // Make sure computer paddle doesn't go off screen
  if (computerPaddleY < 0) {
    computerPaddleY = 0;
  }
  if (computerPaddleY > screenHeight - paddleHeight) {
    computerPaddleY = screenHeight - paddleHeight;
  }

  // Move the ball
  ballX = ballX + ballDirectionX;
  ballY = ballY + ballDirectionY;

  // Bounce ball off top and bottom of screen
  if (ballY <= 0 || ballY + ballSize >= screenHeight) {
    ballDirectionY = -ballDirectionY;  // Reverse up/down direction
  }

  // Check if ball hits player paddle (left side)
  bool ballHitPlayerPaddle = (ballX <= 10 + paddleWidth && 
                              ballY + ballSize >= playerPaddleY && 
                              ballY <= playerPaddleY + paddleHeight);
  
  if (ballHitPlayerPaddle) {
    ballDirectionX = -ballDirectionX;  // Reverse left/right direction
    ballX = 10 + paddleWidth;  // Move ball away from paddle to prevent sticking
  }

  // Check if ball hits computer paddle (right side)
  bool ballHitComputerPaddle = (ballX + ballSize >= computerPaddleX && 
                                ballY + ballSize >= computerPaddleY && 
                                ballY <= computerPaddleY + paddleHeight);
  
  if (ballHitComputerPaddle) {
    ballDirectionX = -ballDirectionX;  // Reverse left/right direction
    ballX = computerPaddleX - ballSize;  // Move ball away from paddle to prevent sticking
  }

  // Check if someone scored
  bool someoneScored = false;
  
  if (ballX < 0) {
    // Ball went off left side - computer scores
    computerScore++;
    someoneScored = true;
  } else if (ballX > screenWidth) {
    // Ball went off right side - player scores
    playerScore++;
    someoneScored = true;
  }

  // If someone scored, reset the ball and paddles
  if (someoneScored) {
    ballX = screenWidth / 2;
    ballY = screenHeight / 2;
    
    // Ball direction depends on who scored last
    if (playerScore > computerScore) {
      ballDirectionX = -ballSpeed;  // Ball goes toward computer
    } else {
      ballDirectionX = ballSpeed;   // Ball goes toward player
    }
    ballDirectionY = ballSpeed;

    // Reset paddle positions
    playerPaddleY = screenHeight / 2 - paddleHeight / 2;
    computerPaddleY = playerPaddleY;
  }

  // Check if player wants to exit the game
  if (exitGamePressed == 1) {
    return false;  // Exit the game
  }

  return true;  // Continue playing
}

// Function to draw everything on the screen
void pongDraw(TFT_eSPI& display) {
  // Erase the old paddle and ball positions by drawing black rectangles/circles
  display.fillRect(10, oldPlayerPaddleY, paddleWidth, paddleHeight, TFT_BLACK);
  display.fillRect(computerPaddleX, oldComputerPaddleY, paddleWidth, paddleHeight, TFT_BLACK);
  display.fillCircle(oldBallX, oldBallY, ballSize, TFT_BLACK);

  // Draw the new paddle and ball positions in white
  display.fillRect(10, playerPaddleY, paddleWidth, paddleHeight, TFT_WHITE);
  display.fillRect(computerPaddleX, computerPaddleY, paddleWidth, paddleHeight, TFT_WHITE);
  display.fillCircle(ballX, ballY, ballSize, TFT_WHITE);

  // Always redraw the score so it stays visible on top
  drawGameScore(display);
}