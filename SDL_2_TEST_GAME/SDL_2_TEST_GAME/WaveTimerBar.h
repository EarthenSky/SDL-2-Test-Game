#ifndef WAVETIMERBAR
#define WAVETIMERBAR

#include "UIElement.h"

class WaveTimerBar : public UIElement {
public:
	// The render objects are created here.
	WaveTimerBar(SDL_Renderer *renderer);

	virtual void update();  //This is the math function
};

#endif // !WAVETIMERBAR