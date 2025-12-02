#pragma once
#include "Widget.h"
#include "KeyboardReader.h"

/// <summary>
/// Represents a text box accepting text from the user.
/// </summary>
class InputBox : public Widget
{
private:
	/// <summary>
	/// Represents the maximum total characters the inputbox will accept.
	/// </summary>
	const int MAX_VALUE_SIZE = 30;

	/// <summary>
	/// Cursor blink rate.
	/// </summary>
	const float BLINK_RATE_MS = 500.0f;

	/// <summary>
	/// The delay after which the keyboard buffer can be polled again after
	/// any keystroke is first hit.
	/// </summary>
	const float KEYBOARD_REPEAT_DELAY = 200.0f;

	/// <summary>
	/// Indicates whether the user is actively interacting with this widget.
	/// </summary>
	bool focus = false;

	/// <summary>
	/// Time passed since the last time the cursor was updated.
	/// </summary>
	float cursorBlinkUpdate = 0.0f;

	/// <summary>
	/// Used to determine if the cursor should be drawn. Is manipulated
	/// both by the blink and the focus functionality.
	/// </summary>
	bool drawCursor = false;

	/// <summary>
	/// Keeps track of the last key pressed. Used to limit the repeat rate
	/// of a key being present in the keyboard buffer.
	/// </summary>
	char lastKeyPressed = '\0';

	/// <summary>
	/// Time passed since the last keyboard update was received.
	/// </summary>
	float keyboardPollUpdate = 0.0f;

	/// <summary>
	/// Provides a poll function returning the last visible character pressed.
	/// </summary>
	KeyboardReader* keyboardReader;

	/// <summary>
	/// The current text of the inputbox.
	/// </summary>
	std::string value = "";

public:
	/// <summary>
	/// Constructor.
	/// </summary>
	InputBox();

	/// <summary>
	/// Destructor.
	/// </summary>
	~InputBox();

	/// <summary>
	/// Widget::draw() override. Draws the input box.
	/// </summary>
	void draw() override;

	/// <summary>
	/// Widget::update() override. Provides blink and keyboard reading functionality.
	/// </summary>
	void update() override;

	/// <summary>
	/// Widget::setMouseState() override. Provides focus functionality.
	/// </summary>
	/// <param name="mouseState"></param>
	void setMouseState(graphics::MouseState mouseState) override;

	/// <summary>
	/// Returns whether the input box has focus.
	/// </summary>
	/// <returns></returns>
	bool getFocus();

	/// <summary>
	/// Sets the focus for the input box.
	/// </summary>
	/// <param name="isFocused"></param>
	void setFocus(bool isFocused);

	/// <summary>
	/// Determines the distance at which the cursor is to be drawn.
	/// </summary>
	/// <returns></returns>
	float getCursorDistance();

	/// <summary>
	/// Returns the display text to be drawn, that differs from the 
	/// actual text value of the input box. This is probably due to the
	/// specific type used having some issue with mapping the space glyph 
	/// texture, but remapping the type was not possible due to the exercise's 
	/// restrictions.
	/// </summary>
	/// <returns></returns>
	std::string getDisplayText();

	/// <summary>
	/// Returns the actual typed text value.
	/// </summary>
	/// <returns></returns>
	std::string getValue();

	/// <summary>
	/// Sets the actual text value.
	/// </summary>
	/// <param name="value"></param>
	void setValue(std::string value);
};
