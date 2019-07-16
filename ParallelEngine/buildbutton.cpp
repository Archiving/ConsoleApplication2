#include "buildbutton.h"

BuildButton::BuildButton(float x1, float y1, float x2, float y2, ALLEGRO_BITMAP* bitmap, ALLEGRO_FONT* fontType,
	ALLEGRO_COLOR fontColor, std::string text, bool visible, Building* returnBuilding_) :
	Button(x1, y1, x2, y2, bitmap, fontType, fontColor, text, visible, placingBuilding), returnBuilding(returnBuilding_) {}