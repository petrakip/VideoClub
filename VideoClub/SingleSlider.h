#pragma once
#include "Widget.h"
#include "Helpers.h"

/// <summary>
/// Represents a single slider UI component.
/// </summary>
class SingleSlider : public Widget
{
private:
	/// <summary>
	/// The minimum and maximum value of the slider.
	/// </summary>
	limits limits;

	/// <summary>
	/// The current value of the slider.
	/// </summary>
	int value = 0;

	/// <summary>
	/// Indicates whether the user is actively interacting
	/// with this component.
	/// </summary>
	bool focus = false;

public:
	/// <summary>
	/// Constructor. Also sets value = min.
	/// </summary>
	/// <param name="min"></param>
	/// <param name="max"></param>
	SingleSlider(int min, int max);

	/// <summary>
	/// Widget:draw() override.
	/// </summary>
	void draw() override;

	/// <summary>
	/// Widget::update() override.
	/// </summary>
	void update() override;

	/// <summary>
	/// Returns the current slider value.
	/// </summary>
	/// <returns></returns>
	int getValue();

	/// <summary>
	/// Sets the current slider value.
	/// </summary>
	/// <param name="value"></param>
	void setValue(int value);

	/// <summary>
	/// Returns the maximum value.
	/// </summary>
	/// <returns></returns>
	int getMax();

	/// <summary>
	/// Returns the minimum value.
	/// </summary>
	/// <returns></returns>
	int getMin();
};

