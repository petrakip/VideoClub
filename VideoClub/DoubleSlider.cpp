#include "DoubleSlider.h"
#include "config.h"

using namespace graphics;

DoubleSlider::DoubleSlider(int min, int max)
{
	limits.min = min;
	limits.max = max;

	lowerValue = min;
	upperValue = max;
}

void DoubleSlider::draw()
{
	Brush br;
	br.fill_color[0] = .3f;
	br.fill_color[1] = .3f;
	br.fill_color[2] = .3f;
	if (focus) {
		br.outline_opacity = 1.0f;
	}
	else {
		br.outline_opacity = .5f;
	}
	drawRect(getX(), getY() - 5, getWidth(), getHeight() / 8, br);

	std::string stringLowerValue = std::to_string(lowerValue);
	std::string stringUpperValue = std::to_string(upperValue);
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

	int distanceFromMin = lowerValue - limits.min;
	int distanceFromMax = upperValue - limits.min;
	int minMaxDistance = upperValue - lowerValue;

	if (distanceFromMin < 0) distanceFromMin = 0;
	if (distanceFromMax > (limits.max - limits.min)) distanceFromMax = limits.max - limits.min;

	Brush sel;
	
	if (focus) {
		sel.fill_color[0] = 0.0f;
		sel.fill_color[1] = 0.0f;
		sel.fill_color[2] = 1.0f;
		sel.outline_opacity = 1.0f;
	} else {
		sel.fill_color[0] = .3f;
		sel.fill_color[1] = .3f;
		sel.fill_color[2] = 1.0f;
		sel.outline_opacity = .5f;
	}

	drawRect(minX + (distanceFromMin * distanceUnit) + (minMaxDistance * distanceUnit) / 2,
		getY() - 5, 
		minMaxDistance * distanceUnit,
		getHeight() / 8, 
		sel);

	Brush sl;
	if (focus) {
		sl.fill_color[0] = .7f;
		sl.fill_color[1] = .4f;
		sl.fill_color[2] = .0f;
		sl.outline_opacity = 1.0f;
	}
	else {
		sl.fill_color[0] = .5f;
		sl.fill_color[1] = .5f;
		sl.fill_color[2] = .5f;
		sl.outline_opacity = .7f;
	}

	drawRect(minX + (distanceFromMin * distanceUnit), getY() - 5, 10, getHeight() - 10, sl);
	drawRect(minX + (distanceFromMax * distanceUnit), getY() - 5, 10, getHeight() - 10, sl);

	setFont(std::string(ASSET_PATH) + "OpenSans-Regular.ttf");
	drawText(minX + (distanceFromMin * distanceUnit) - (stringLowerValue.length() * 2), getY() - 13, 6, stringLowerValue, tx);
	drawText(minX + (distanceFromMin * distanceUnit), getY() - 3, 6, "[", tx);

	setFont(std::string(ASSET_PATH) + "OpenSans-Regular.ttf");
	drawText(minX + (distanceFromMax * distanceUnit) - (stringUpperValue.length() * 2), getY() - 13, 6, stringUpperValue, tx);
	drawText(minX + (distanceFromMax * distanceUnit), getY() - 3, 6, "]", tx);

}

void DoubleSlider::update()
{
	if (isMouseOver() && mouseState.button_left_released && !focus) {
		focus = true;
		return;
	}

	if (!isMouseOver() && mouseState.button_left_released && focus) {
		focus = false;
		return;
	}

	if (focus && mouseState.dragging) {
		int minX = getX() - (getWidth() / 2) + 10;
		int maxX = getX() + (getWidth() / 2) - 10;
		float distanceUnit = (float)(maxX - minX) / (limits.max - limits.min);
		
		int distanceFromMin = lowerValue - limits.min;
		int distanceFromMax = upperValue - limits.min;

		if (distanceFromMin < 0) distanceFromMin = 0;
		if (distanceFromMax > (limits.max - limits.min)) distanceFromMax = limits.max - limits.min;
		
		int lowerX = minX + (distanceFromMin * distanceUnit);
		int upperX = minX + (distanceFromMax * distanceUnit);

		int mouseX = windowToCanvasX(mouseState.cur_pos_x);

		if (abs(lowerX - mouseX) < abs(upperX - mouseX)) {
			int dX = windowToCanvasX(mouseState.cur_pos_x) - minX;
			if (dX < 0) return;
			setLowerValue(limits.min + (dX / distanceUnit));
		} else {
			int dX = windowToCanvasX(mouseState.cur_pos_x) - minX;
			if (dX < 0) return;
			setUpperValue(limits.min + (dX / distanceUnit));

		}
	}
}

int DoubleSlider::getLowerValue()
{
	return lowerValue;
}

void DoubleSlider::setLowerValue(int value)
{
	if (value < limits.min) {
		this->lowerValue = limits.min;
		return;
	}

	if (value > upperValue) {
		this->lowerValue = upperValue - 1;
		return;
	}

	this->lowerValue = value;
}

int DoubleSlider::getUpperValue()
{
	return upperValue;
}

int DoubleSlider::getMax()
{
	return limits.max;
}

void DoubleSlider::setUpperValue(int value)
{
	if (value < lowerValue) {
		this->upperValue = lowerValue + 1;
		return;
	}

	if (value > limits.max) {
		this->upperValue = limits.max;
		return;
	}

	this->upperValue = value;
}

int DoubleSlider::getMin()
{
	return limits.min;
}
