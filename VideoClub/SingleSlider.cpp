#include "SingleSlider.h"
#include "config.h"
#include <iostream>

using namespace graphics;

SingleSlider::SingleSlider(int min, int max)
{
	limits.min = min;
	limits.max = max;

	value = limits.min;
}

void SingleSlider::draw()
{
	Brush br;
	br.fill_color[0] = .3f;
	br.fill_color[1] = .3f;
	br.fill_color[2] = .3f;
	if (focus) {
		br.outline_opacity = 1.0f;
	} else {
		br.outline_opacity = .5f;
	}
	drawRect(getX(), getY() - 5, getWidth(), getHeight() / 8, br);
	
	std::string stringValue = std::to_string(value);
	std::string stringMin = std::to_string(limits.min);
	std::string stringMax = std::to_string(limits.max);

	Brush tx;
	tx.fill_color[0] = 1.0f;
	tx.fill_color[1] = 1.0f;
	tx.fill_color[2] = 1.0f;


	setFont(std::string(ASSET_PATH) + "OpenSans-Bold.ttf");
	drawText(getX() - (getWidth() / 2), getY() + 8, 6, stringMin, tx);

	setFont(std::string(ASSET_PATH) + "OpenSans-Bold.ttf");
	drawText(getX() + (getWidth() / 2) - (stringMax.length() * 3), getY() + 8, 6, stringMax, tx);

	int minX = getX() - (getWidth() / 2) + 10;
	int maxX = getX() + (getWidth() / 2) - 10;

	float distanceUnit = (float)(maxX - minX) / (limits.max - limits.min);

//#if _DEBUG
//	std::cout << "Distance Unit: " << distanceUnit << ","
//			  << "Limits: " << limits.min << "-" << limits.max << ", "
//			  << "Motion range: " << minX << "-" << maxX << ", "
//			  << "Numerator: " << (float)(maxX - minX) << ", "
//			  << "Denominator: " << limits.max - limits.min
//			  << std::endl;
//#endif

	int distanceFromMin = value - limits.min;
	
	if (distanceFromMin < 0) distanceFromMin = 0;

	Brush sl;
	if (focus) {
		sl.fill_color[0] = .7f;
		sl.fill_color[1] = .4f;
		sl.fill_color[2] = .0f;
		sl.outline_opacity = 1.0f;
	} else {
		sl.fill_color[0] = .5f;
		sl.fill_color[1] = .5f;
		sl.fill_color[2] = .5f;
		sl.outline_opacity = .7f;
	}
	drawRect(minX + (distanceFromMin * distanceUnit), getY() - 5, 10, getHeight() - 10, sl);

	setFont(std::string(ASSET_PATH) + "OpenSans-Regular.ttf");
	drawText(minX + (distanceFromMin * distanceUnit) - (stringValue.length() * 2), getY() - 13, 6, stringValue, tx);
}

void SingleSlider::update()
{
	if (isMouseOver() && mouseState.button_left_released && !focus) {
		focus = true;
		return;
	} 
	
	if (!isMouseOver() && mouseState.button_left_released && focus) {
		focus = false;
		return;
	}

	if (focus && (mouseState.dragging || mouseState.button_left_released)) {
		int minX = getX() - (getWidth() / 2) + 10;
		int maxX = getX() + (getWidth() / 2) - 10;
		float distanceUnit = (float)(maxX - minX) / (limits.max - limits.min);
		int dX = windowToCanvasX(mouseState.cur_pos_x) - minX;
		if (dX < 0) return;
		setValue(limits.min + (dX / distanceUnit));
	}
}

int SingleSlider::getValue()
{
	return value;
}

void SingleSlider::setValue(int value)
{
	if (value < limits.min) {
		this->value = limits.min;
		return;
	} 

	if (value > limits.max) {
		this->value = limits.max;
		return;
	}

	this->value = value;
}

int SingleSlider::getMax()
{
	return limits.max;
}

int SingleSlider::getMin()
{
	return limits.min;
}
