#include <graphics.h>

#include "config.h"
#include "MousePosition.h"

void MousePosition::draw()
{
	int mouseX = mouseState.cur_pos_x;
	int mouseY = mouseState.cur_pos_y;

	graphics::Brush br;

	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;

	graphics::setFont(std::string(ASSET_PATH) + "OpenSans-Regular.ttf");
	graphics::drawText(getX(), getY(), 6, std::to_string(mouseX) + ":" + std::to_string(mouseY), br);

	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 1.0f;

	graphics::drawText(getX() + 25, getY(), 6, 
		"(" + std::to_string((int) graphics::windowToCanvasX(mouseX)) 
		+ ":" + std::to_string((int) graphics::windowToCanvasY(mouseY)) + ")", br);
}

void MousePosition::update()
{
}

void MousePosition::setMousePosition(int x, int y)
{	
	mouseX = x;
	mouseY = y;
}