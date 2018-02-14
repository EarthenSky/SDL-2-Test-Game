#include "UIElement.h"

class WaveTimerBar : public UIElement {
public:
	WaveTimerBar() : UIElement(SDL_Renderer *renderer, std::string path, Point pos);

	virtual void update();

};