#pragma once
#include "Widget.h"

/// <summary>
/// Represents a button that can be turned on or off.
/// </summary>
class Toggle : public Widget
{
private:
	/// <summary>
	/// The text displayed on the button.
	/// </summary>
	std::string label;

	/// <summary>
	/// The size of the font to use.
	/// </summary>
	int fontSize;

	/// <summary>
	/// If true, the button is active. Otherwise, it's inactive.
	/// </summary>
	bool toggled;

public:
	/// <summary>
	/// Constructor.
	/// </summary>
	/// <param name="label"></param>
	/// <param name="fontSize"></param>
	Toggle(std::string label, int fontSize);

	/// <summary>
	/// Widget::draw() override.
	/// </summary>
	void draw() override;

	/// <summary>
	/// Widget::update() override.
	/// </summary>
	void update() override;

	/// <summary>
	/// Turns the button on if it's off, and off if it's on.
	/// </summary>
	void toggle();

	/// <summary>
	/// Gets the toggle state of the button. True if on, false if off.
	/// </summary>
	/// <returns></returns>
	bool getToggled();

	/// <summary>
	/// Returns the text on the button.
	/// </summary>
	/// <returns></returns>
	std::string getLabel();
};