#include <iostream>

#include <graphics.h>

#include "config.h"
#include "InputBox.h"
#include "KeyboardReader.h"

using namespace graphics;

InputBox::InputBox()
{
	keyboardReader = new KeyboardReader();
}

InputBox::~InputBox()
{
	delete keyboardReader;
}

void InputBox::draw()
{
	Brush br;

	br.fill_color[0] = .1f;
	br.fill_color[1] = .1f;
	br.fill_color[2] = .1f;

	if (getFocus()) {
		br.outline_opacity = 1.0f;
	} else {
		br.outline_opacity = .5f;
	}

	drawRect(getX(), getY(), getWidth(), getHeight(), br);
	
	if (getFocus() && drawCursor) {
		Brush cs;

		cs.fill_color[0] = 0.9f;
		cs.fill_color[1] = 0.6f;
		cs.fill_color[2] = 0.0f;
		cs.outline_opacity = 0.0f;

		drawRect(getX() - (getWidth() / 2) + 3 + getCursorDistance(),
			getY(), 4, getHeight() - 6, cs);
	}

	Brush tx;

	tx.fill_color[0] = 1.0f;
	tx.fill_color[1] = 1.0f;
	tx.fill_color[2] = 1.0f;
	tx.outline_opacity = 0.0f;

	setFont(std::string(ASSET_PATH) + "RobotoMono-Regular.ttf");
	drawText(getX() - (getWidth() / 2) + 5, getY() + 3, 10, getDisplayText(), tx);
}

void InputBox::update()
{
	float time = getGlobalTime();

	// cursor blink
	float blinkDelta = time - cursorBlinkUpdate;
	if (blinkDelta > BLINK_RATE_MS) {
		drawCursor = !drawCursor;
		cursorBlinkUpdate += blinkDelta;
	}

	// keyboard handling if the input box has the focus.
	if (getFocus()) {
		// if we haven't received keyboard input yet, 
		// initialize the poll update.
		if (keyboardPollUpdate == 0) {
			keyboardPollUpdate = time;
			return;
		}

		// calculate the time that passed from the last time
		// we received keyboard input.
		float keyDelta = time - keyboardPollUpdate;

		char key = keyboardReader->getKeyPressed();
		if (key == lastKeyPressed && keyDelta < KEYBOARD_REPEAT_DELAY) {
			// to avoid receiving the same character multiple times, 
			// we introduce a delay here.
			return;
		}

		if (key == 42) { 
			// backspace, remove the last character.
			value = value.substr(0, value.length() - 1);
		} else if (key != '\0' && value.length() < MAX_VALUE_SIZE) { 
			// if we indeed received an input and we can add to the 
			// value of the inputbox, append the key to the value.
			value += key;
		}

		keyboardPollUpdate += keyDelta;
		lastKeyPressed = key;
	}
}

void InputBox::setMouseState(graphics::MouseState mouseState)
{
	Widget::setMouseState(mouseState);

	if (isMouseOver() && mouseState.button_left_released) {
		setFocus(true);
	} else if (!isMouseOver() && mouseState.button_left_released) {
		setFocus(false);
	}
}

bool InputBox::getFocus()
{
	return focus;
}

void InputBox::setFocus(bool isFocused)
{
	focus = isFocused;
}

/// <summary>
/// Calculate the distance at which the cursor should be drawn,
/// based on the value of the input box.
/// </summary>
/// <returns></returns>
float InputBox::getCursorDistance()
{
	return 2 + value.length() * 5.25;
}

/// <summary>
/// Returns the appropriate text to display, based on the actual string value
/// we have collected from the keyboard.
/// 
/// Note: Because the library cannot count the text distance for variable
/// character-length fonts, we use a monospace font in the input box, but this
/// apparently introduces a bug: single space characters are not correctly drawn
/// (some issue with sgg probably). Therefore, we substitute one space for 
/// three spaces in the display string, while the actual underlying value
/// of the input box has only one space.
/// </summary>
/// <returns></returns>
std::string InputBox::getDisplayText()
{
	std::string result;
	
	for (std::string::iterator it = value.begin(); it != value.end(); it++) {
		result += *it;
		if (*it == ' ') {
			result += "  ";
		}
	}

	return result;
}

std::string InputBox::getValue()
{
	return value;
}

void InputBox::setValue(std::string value)
{
	this->value = value;
}
