#ifndef UI
#define UI

#include <SDL.h>
#include <stdio.h>
#include <vector>  //for std::vector
//#include "UIElement.h"
#include "WaveTimerBar.h"
#include "HP.h"

void initUI(SDL_Renderer *renderer);

void updateUI();
void renderUI(SDL_Renderer *renderer);

#endif

