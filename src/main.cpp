#include "lamp.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>

// Constants
const int SCREEN_WIDTH = 512;
const int SCREEN_HEIGHT = 512;
const int BLINK_RATE = 50;
const Uint32 BLINK_DURATION = 100;
const Uint32 DRAIN_INCREMENT_INTERVAL = 10000;
const int DRAIN_INCREMENT = 1;

// Global variables
SDL_Renderer *gRenderer = NULL;
SDL_Window *gWindow = NULL;

bool init();

void close();

int main(int argc, char const *argv[]) {
  if (!init()) {
    printf("Failed to initialize! SDL_Error: %s\n", SDL_GetError());
  } else {
    // Main loop flag
    bool shouldQuit = false;

    // Event handler
    SDL_Event event;

    // Timer variables
    Uint32 ticksSinceLastDrain = 0;
    Uint32 ticksAtLastDrain = 0;
    Uint32 ticksSinceLastBlinkSession = 0;
    Uint32 ticksAtLastBlinkSession = 0;
    Uint32 ticksSinceLastBlink = 0;
    Uint32 ticksAtLastBlink = 0;
    Uint32 currentTicks = 0;

    // Lamp
    Lamp lamp;

    // Screen Color
    Uint8 r, g, b, a;

    bool isBlinking = false;

    while (!shouldQuit) {
      while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
          shouldQuit = true;
        } else if (event.type == SDL_KEYDOWN) {
          if (event.key.keysym.sym == SDLK_UP) {
            lamp.pump();
          }
        }
      }
      // Clear screen
      SDL_RenderClear(gRenderer);

      currentTicks = SDL_GetTicks();

      if (lamp.isDrained()) {
        SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
      } else {
        ticksSinceLastDrain = currentTicks - ticksAtLastDrain;
        if (ticksSinceLastDrain > 1000) {
          // Drain lamp power
          lamp.drain();
          ticksAtLastDrain = currentTicks;
        }
        ticksSinceLastBlinkSession = currentTicks - ticksAtLastBlinkSession;

        if (isBlinking) {
          ticksSinceLastBlink = currentTicks - ticksAtLastBlink;
          if (ticksSinceLastBlink > BLINK_DURATION) {
            if (SDL_GetRenderDrawColor(gRenderer, &r, &g, &b, &a) == 0) {
              ticksAtLastBlink = currentTicks;
              if (r == 0) {
                // Turn screen white
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                isBlinking = false;
                ticksAtLastBlinkSession = currentTicks;
              } else {
                // Turn screen black
                SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
              }
            } else {
              printf("SDL_GetRendererDrawColor Failed! SDL_Error: %s\n",
                     SDL_GetError());
            }
          }
        } else if ((lamp.getCharge() / 10) * BLINK_RATE <
                   ticksSinceLastBlinkSession) {
          isBlinking = true;
        }

        if (currentTicks % DRAIN_INCREMENT_INTERVAL < 17) {
          lamp.increaseDrainRate(DRAIN_INCREMENT);
        }
      }

      // Update screen
      SDL_RenderPresent(gRenderer);
    }
  }

  close();
  return 0;
}

// Initialize SDL libraries
bool init() {
  // Success flag
  bool success = true;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Failed to initialize SDL! SDL_Error:%s\n", SDL_GetError());
    success = false;
  } else {
    // Create window
    gWindow = SDL_CreateWindow("Achluophobia", SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                               SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (gWindow == NULL) {
      printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
      success = false;
    } else {
      // Create renderer for window
      gRenderer = SDL_CreateRenderer(
          gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
      if (gRenderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n",
               SDL_GetError());
        success = false;
      } else {
        // Initialize renderer color
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
      }
    }
  }
  return success;
}

void close() {
  // Destroy window and renderer
  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gWindow);
  gWindow = NULL;
  gRenderer = NULL;

  // Quit SDL subsystems
  SDL_Quit();
}
