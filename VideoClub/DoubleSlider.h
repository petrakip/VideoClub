#pragma once
#include "Widget.h"
#include "Helpers.h"

/// <summary>
/// A double slider UI component that allows the user
/// to input a range of values.
/// </summary>
class DoubleSlider : public Widget
{
private:
	/// <summary>
	/// The minimum and maximum values allowed by the slider.
	/// </summary>
	limits limits;

	/// <summary>
	/// If the user is actively using the control, this is true. Otherwise, it's false.
	/// </summary>
	bool focus = false;

	/// <summary>
	/// The lower value of the slider.
	/// </summary>
	int lowerValue;
	
	/// <summary>
	/// The upper value of the slider.
	/// </summary>
	int upperValue;

public:
	/// <summary>
	/// Constructor. Initializes limits and also sets lowerValue = min, and upperValue = max.
	/// </summary>
	DoubleSlider(int min, int max);

	/// <summary>
	/// Widget::draw() override. Draws the slider.
	/// </summary>
	void draw() override;

	/// <summary>
	/// Widget::update() override. Determines focus and slider behavior.
	/// </summary>
	void update() override;

	/// <summary>
	/// Returns the lower value of the slider.
	/// </summary>
	int getLowerValue();

	/// <summary>
	/// Sets the lower value of the slider.
	/// </summary>
	void setLowerValue(int value);

	/// <summary>
	/// Returns the upper value of the slider.
	/// </summary>
	int getUpperValue();

	/// <summary>
	/// Sets the upper value of the slider.
	/// </summary>
	void setUpperValue(int value);

	/// <summary>
	/// Returns the upper limit of the slider.
	/// </summary>
	int getMax();

	/// <summary>
	/// Returns the lower limit of the slider.
	/// </summary>
	int getMin();
};