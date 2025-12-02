#include <graphics.h>
#include <iostream>

#include "MovieBox.h"
#include "Widget.h"
#include "config.h"

void MovieBox::draw()
{
	graphics::Brush im;
	im.texture = std::string(ASSET_PATH) + imagePath;
	im.outline_opacity = isMouseOver() ? 1.0f : 0.0f;
	graphics::drawRect(getX(), getY(), getWidth(), getHeight(), im);
}

void MovieBox::update()
{
}

void MovieBox::setImagePath(std::string imagePath)
{
	this->imagePath = imagePath;
}
