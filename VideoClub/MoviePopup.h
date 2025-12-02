#pragma once
#include "Widget.h"
#include "Movie.h"

/// <summary>
/// Represents a large view of a selected movie's attributes.
/// </summary>
class MoviePopup : public Widget
{
private:
	/// <summary>
	/// The movie to display.
	/// </summary>
	Movie* movie = nullptr;

public:
	/// <summary>
	/// Sets the movie to display.
	/// </summary>
	/// <param name="movie"></param>
	void setMovie(Movie* movie);

	/// <summary>
	/// Widget::draw() override.
	/// </summary>
	void draw() override;

	/// <summary>
	/// Widget::update() override.
	/// </summary>
	void update() override;
};