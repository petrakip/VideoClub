#pragma once

#include <graphics.h>

#include "Movie.h"
#include "Widget.h"

/// <summary>
/// Represents a small portait depiction of a movie's image.
/// </summary>
class MovieBox :public Widget
{
private:
	/// <summary>
	/// The image to draw.
	/// </summary>
	std::string imagePath;

	/// <summary>
	/// Used to optionally specify a callback to be invoked when 
	/// the movie box is clicked.
	/// </summary>
	std::function<void(void* context, MovieBox* box)> clickCallback;

	/// <summary>
	/// The object to invoke the callback on.
	/// </summary>
	void* clickContext = nullptr;

public:
	/// <summary>
	/// Widget::draw() override.
	/// </summary>
	void draw() override;

	/// <summary>
	/// Widget::update() override. 
	/// </summary>
	void update() override;

	/// <summary>
	/// Sets the imagePath.
	/// </summary>
	/// <param name="imagePath"></param>
	void setImagePath(std::string imagePath);
};