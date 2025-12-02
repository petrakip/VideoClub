#include "Widget.h"

int Widget::getX()
{
	return location.x;
}

void Widget::setX(int value)
{
	location.x = value;
}

int Widget::getY()
{
	return location.y;
}

void Widget::setY(int value)
{
	location.y = value;
}

int Widget::getWidth()
{
	return dimensions.x;
}

void Widget::setWidth(int value)
{
	dimensions.x = value;
}

int Widget::getHeight()
{
	return dimensions.y;
}

void Widget::setHeight(int value)
{
	dimensions.y = value;
}

void Widget::setMouseState(graphics::MouseState mouseState)
{
	this->mouseState = mouseState;

	int mouseX = graphics::windowToCanvasX(mouseState.cur_pos_x);
	int mouseY = graphics::windowToCanvasY(mouseState.cur_pos_y);

	int left = getX() - (getWidth() / 2);
	int top = getY() - (getHeight() / 2);

	mouseOver = left < mouseX
		&& left + getWidth() > mouseX
		&& top < mouseY
		&& top + getHeight() > mouseY;

	if (isMouseOver() && mouseState.button_left_released && clickCallback != nullptr) {
		clickCallback(clickContext, this);
	}
}

void Widget::clearMouseState()
{
	mouseOver = false;
}

bool Widget::isMouseOver()
{
	return mouseOver;
}

int Widget::getData()
{
	return data;
}

void Widget::setData(int value)
{
	data = value;
}

void Widget::setClickCallback(void(*operation)(void* context, Widget* box), void* context)
{
	clickCallback = operation;
	clickContext = context;
}
