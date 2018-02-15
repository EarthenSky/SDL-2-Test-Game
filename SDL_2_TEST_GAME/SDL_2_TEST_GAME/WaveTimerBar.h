#include "UIElement.h"

class WaveTimerBar : public UIElement {
public:
	WaveTimerBar(SDL_Renderer *renderer, std::string path, Point pos, Point texSize);

	virtual void update();

	//virtual render function
};