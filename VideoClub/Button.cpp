#include "Button.h"
#include "config.h"

using namespace graphics;

Button::Button(std::string label)
{
	this->label = label;
}

void Button::draw()
{
	Brush br;
	br.fill_color[0] = 0.7f;
	br.fill_color[1] = 0.4f;
	br.fill_color[2] = 0.0f;
	br.outline_opacity = 1.0f;
	drawRect(getX(), getY(), getWidth(), getHeight(), br);

	Brush tx;
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	setFont(std::string(ASSET_PATH) + "OpenSans-Bold.ttf");
	drawText(getX() - 35, getY()+ 5, 14, label, tx);
}

void Button::update()
{
}
