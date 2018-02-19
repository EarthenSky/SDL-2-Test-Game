#ifndef WAVETIMERBAR
#define WAVETIMERBAR

#include "UIElement.h"

class WaveTimerBar : public UIElement {
public:
	// The render objects are created here.
	void init(SDL_Renderer *renderer);

	virtual void update();  //This is the math function

	void render(SDL_Renderer *renderer);  //This is the math function
};

#endif // !WAVETIMERBAR