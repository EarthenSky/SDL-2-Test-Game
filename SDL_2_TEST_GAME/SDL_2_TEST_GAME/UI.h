#ifndef UI
#define UI

#include <SDL.h>
#include <stdio.h>
#include <list>  //for std::list
#include "UIElement.h"
#include "WaveTimerBar.h"

void initUI(SDL_Renderer *renderer);

void updateUI();
void renderUI(SDL_Renderer *renderer);

void freeUI();

#endif

