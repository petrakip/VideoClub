#pragma once
#include "Widget.h"

/// <summary>
/// A debugging widget indicating the current mouse position
/// in both window (in white) and canvas (in magenta) coordinates.
/// </summary>
class MousePosition : public Widget
{
private:
	/// <summary>
	/// Current mouse X.
	/// </summary>
	int mouseX = 0;

	/// <summary>
	/// Current mouse Y.
	/// </summary>
	int mouseY = 0;

public:
	/// <summary>
	/// Widget::draw() override. Draws the current mouse position.
	/// </summary>
	void draw() override;

	/// <summary>
	/// Widget::update() override.
	/// </summary>
	void update() override;

	/// <summary>
	/// Sets the current mouse position. Expects window coordinates.
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void setMousePosition(int x, int y);
};