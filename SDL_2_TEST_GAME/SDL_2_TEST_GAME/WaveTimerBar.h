#ifndef WAVETIMERBAR
#define WAVETIMERBAR

#include "UIElement.h"
#include "EnemyManager.h"
#include <stdlib.h>  // For rand()
#include <time.h>  // For time()

extern EnemyManager gEnemyManager;

class WaveTimerBar : public UIElement {
public:
	int currentWave = 1;

	// The render objects are created here.
	void init(SDL_Renderer *renderer);

	virtual void update();  //This is the math function

	void render(SDL_Renderer *renderer);  //This is the math function
};

#endif // !WAVETIMERBAR