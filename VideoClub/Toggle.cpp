#include <graphics.h>

#include "config.h"
#include "Toggle.h"

using namespace graphics;

Toggle::Toggle(std::string label, int fontSize)
{
	this->label = label;
	this->fontSize = fontSize;

	// We basically ignore given dimensions here,
	// since we want each toggle to scale its width
	// and height with the given font size.
	this->setWidth(fontSize * label.length() * 0.8);
	this->setHeight(fontSize + 4);
	toggled = true;
}

void Toggle::draw()
{
	Brush br;
	if (toggled) {
		br.fill_color[0] = 0.7f;
		br.fill_color[1] = 0.4f;
		br.fill_color[2] = 0.0f;
		br.outline_opacity = 1.0f;
	} else {
		br.fill_color[0] = 0.2f;
		br.fill_color[1] = 0.2f;
		br.fill_color[2] = 0.2f;
		br.outline_opacity = 0.0f;
	}

	drawRect(getX(), getY(), getWidth(), getHeight(), br);

	Brush tx;
	tx.fill_color[0] = 1.0f;
	tx.fill_color[1] = 1.0f;
	tx.fill_color[2] = 1.0f;
	setFont(std::string(ASSET_PATH) + "OpenSans-Regular.ttf");
	drawText(getX() - (getWidth() / 3), getY() + 2, fontSize, label, tx);

}

void Toggle::update()
{
}

void Toggle::toggle()
{
	toggled = !toggled;
}

bool Toggle::getToggled()
{
	return toggled;
}

std::string Toggle::getLabel()
{
	return label;
}
