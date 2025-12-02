#pragma once
#include <map>
#include <graphics.h>

/// <summary>
/// Helper class that uses the SGG keyboard function to get any
/// readable / text character from the keyboard buffer.
/// </summary>
class KeyboardReader
{
private:
	/// <summary>
	/// Contains a map of scancode_t to an actual character.
	/// </summary>
	std::map<graphics::scancode_t, char> textScancodes;

public:
	/// <summary>
	/// Constructor. Initializes <see cref="textScancodes"/>.
	/// </summary>
	KeyboardReader();

	/// <summary>
	/// Destructor.
	/// </summary>
	~KeyboardReader();

	/// <summary>
	/// Polls the keyboard in turn for every character in the <see cref="textScancodes"/>
	/// map to determine if any of the characters has been pressed.
	/// </summary>
	/// <returns>
	/// The first character that was found to have been pressed or '\0' 
	/// if no character was pressed.
	/// </returns>
	char getKeyPressed();
};

