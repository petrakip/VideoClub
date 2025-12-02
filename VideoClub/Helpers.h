#pragma once
#include <string>
#include <vector>
#include <graphics.h>

using namespace std;

/// <summary>
/// Splits a string into parts and stores the results into a string vector
/// </summary>
/// <param name="s">The string to be split</param>
/// <param name="delimiter">The delimiter by which to split the string</param>
/// <param name="target">The vector that will receive the resulting list of string pointers</param>
void splitString(string s, string delimiter, vector<string>* target);

/// <summary>
/// Joins a string vector into a string, using the specified delimiter.
/// </summary>
/// <param name="source"></param>
/// <param name="delimiter"></param>
/// <returns></returns>
string join(vector<string> source, string delimiter);

/// <summary>
/// Draws text after wrapping to the nearest word (approximately).
/// 
/// Please note that changing the provided font (OpenSans) might require adjusting the constants
/// in the function implementation if the supplanted font has a weird average rectangle per letter (ie.
/// very wide or very narrow fonts). Check the constants averageBoxWidth and averageBoxHeight in the 
/// assorted cpp file.
/// </summary>
/// <param name="pos_x">The horizontal center of the drawn text</param>
/// <param name="pos_y">The vertical center of the drawn text</param>
/// <param name="size">The text size</param>
/// <param name="width">The maximum width allowed for the texct</param>
/// <param name="text">The text to draw</param>
/// <param name="brush">The brush to use</param>
/// <returns>The height of the drawn text</returns>
int drawWrappedText(float pos_x, float pos_y, float size, int width, const string& text, const graphics::Brush& brush);

/// <summary>
/// Transforms a string to lower case.
/// </summary>
/// <param name="input"></param>
/// <returns></returns>
std::string toLowerCase(std::string input);

/// <summary>
/// Defines a helper type for keeping track of min and max pairs.
/// </summary>
typedef struct {
	int min;
	int max;
} limits;