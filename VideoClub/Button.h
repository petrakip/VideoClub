#pragma once
#include "Widget.h"

/// <summary>
/// Represents a drawable button widget.
/// </summary>
class Button : public Widget
{
private:
	/// <summary>
	/// The text displayed on the button.
	/// </summary>
	std::string label;

public:
	/// <summary>
	/// Constructor.
	/// </summary>
	/// <param name="label"></param>
	Button(std::string label);

	/// <summary>
	/// Override for Widget::draw(). Draws the button.
	/// </summary>
	void draw() override;

	/// <summary>
	/// Override for Widget::update().
	/// </summary>
	void update() override;
};

