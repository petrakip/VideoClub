#pragma once
#include <graphics.h>

/// <summary>
/// Helper integer pair struct to specify coordinates
/// and dimensions.
/// </summary>
struct Point
{
	int x;
	int y;
};

/// <summary>
/// Represents a basic UI component.
/// </summary>
class Widget
{
private:
	/// <summary>
	/// The dimensions of the widget.
	/// </summary>
	Point dimensions;

	/// <summary>
	/// The location of the widget.
	/// </summary>
	Point location;

	/// <summary>
	/// Indicates whether the mouse is over the widget.
	/// </summary>
	bool mouseOver = false;

	/// <summary>
	/// Keeps an integer as a helper data item.
	/// </summary>
	int data;

	/// <summary>
	/// Can be used to specify a callback when a widget is clicked.
	/// </summary>
	std::function<void(void* context, Widget* box)> clickCallback;

	/// <summary>
	/// The receiver / owner of the callback function.
	/// </summary>
	void* clickContext;

protected:
	/// <summary>
	/// The current mouse state as returned by SGG.
	/// </summary>
	graphics::MouseState mouseState;

public:
	/// <summary>
	/// All widgets need to specify how they are drawn.
	/// </summary>
	virtual void draw() = 0;

	/// <summary>
	/// All widgets need to specify what happens when they get 
	/// updated.
	/// </summary>
	virtual void update() = 0;

	/// <summary>
	/// Gets the position x of the widget.
	/// </summary>
	/// <returns></returns>
	int getX();

	/// <summary>
	/// Sets the position x of the widget.
	/// </summary>
	/// <param name="value"></param>
	void setX(int value);

	/// <summary>
	/// Gets the position y of the widget.
	/// </summary>
	/// <returns></returns>
	int getY();

	/// <summary>
	/// Sets the position x of the widget.
	/// </summary>
	/// <param name="value"></param>
	void setY(int value);

	/// <summary>
	/// Gets the width of the widget.
	/// </summary>
	/// <returns></returns>
	int getWidth();

	/// <summary>
	/// Sets the width of the widget.
	/// </summary>
	/// <param name="value"></param>
	void setWidth(int value);

	/// <summary>
	/// Gets the height of the widget.
	/// </summary>
	/// <returns></returns>
	int getHeight();

	/// <summary>
	/// Sets the height of the widget.
	/// </summary>
	/// <param name="value"></param>
	void setHeight(int value);

	/// <summary>
	/// Used to make the widget aware of the mouse state. Widgets
	/// should collect their mouse state from this override.
	/// </summary>
	/// <param name="mouseState"></param>
	virtual void setMouseState(graphics::MouseState mouseState);

	/// <summary>
	/// Clears the mouse state and sets mouseOver to false.
	/// </summary>
	void clearMouseState();

	/// <summary>
	/// Returns true if the mouse is over the widget.
	/// </summary>
	/// <returns></returns>
	bool isMouseOver();
	
	/// <summary>
	/// Retrieves the data of the widget.
	/// </summary>
	/// <returns></returns>
	int getData();

	/// <summary>
	/// Sets the data value of the widget.
	/// </summary>
	/// <param name="value"></param>
	void setData(int value);

	/// <summary>
	/// Sets a callback to be triggered whenever the widget is clicked.
	/// </summary>
	/// <param name="operation"></param>
	/// <param name="context"></param>
	void setClickCallback(void (*operation)(void* context, Widget* box), void* context);
};