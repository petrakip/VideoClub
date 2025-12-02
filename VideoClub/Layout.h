#pragma once

#include <vector>

#include <graphics.h>

#include "Widget.h"
#include "Movie.h"
#include "MovieBox.h"
#include "MousePosition.h"
#include "MoviePopup.h"
#include "MovieFilter.h"
#include "FilterState.h"

/// <summary>
/// Represents the entire drawn user interface.
/// </summary>
class Layout : public Widget
{
private:
	/// <summary>
	/// The list of movies to draw.
	/// </summary>
	std::vector<Movie*>* movies = nullptr;

	/// <summary>
	/// The list of <see cref="MovieBox" /> controls to draw.
	/// </summary>
	std::vector<MovieBox*> movieBoxes;

	/// <summary>
	/// A debug widget displaying the current mouse coords. Only
	/// drawn in debug mode.
	/// </summary>
	MousePosition* mousePosition;

	/// <summary>
	/// The movie popup widget, which highlights a clicked movie.
	/// </summary>
	MoviePopup* moviePopup;

	/// <summary>
	/// The movie filter that enables users to look for specific movies.
	/// </summary>
	MovieFilter* movieFilter;

	/// <summary>
	/// The filter state represents the currently active movie filters.
	/// </summary>
	FilterState* filterState;

	/// <summary>
	/// Keeps the index of the currently selected movie. If > -1, which
	/// means that a movie box has been clicked, then the movie popup is drawn.
	/// </summary>
	int selectedMovieIndex = -1;

	/// <summary>
	/// The maximum Y of the filter when it's open.
	/// </summary>
	const int FILTER_OPEN_Y = 100;

	/// <summary>
	/// The minimum Y of the filter when it's closed.
	/// </summary>
	const int FILTER_CLOSED_Y = -80;

public:
	/// <summary>
	/// Constructor.
	/// </summary>
	Layout();

	/// <summary>
	/// Destructor.
	/// </summary>
	~Layout();

	/// <summary>
	/// Invoked by a <see cref="MovieBox" /> whenever it's clicked,
	/// to indicate it should be considered selected.
	/// </summary>
	/// <param name="context"></param>
	/// <param name="box"></param>
	static void boxClicked_Callback(void* context, Widget* box);

	/// <summary>
	/// Widget::draw() override. Draws the entire layout.
	/// </summary>
	void draw() override;

	/// <summary>
	/// Widget::update() override.
	void update() override;

	/// <summary>
	/// Repositions movies before draw() is invoked for each movie box.
	/// </summary>
	void repositionMovies();

	/// <summary>
	/// Sets the movies to be displayed. Also initializes the vector of movie
	/// boxes to draw.
	/// </summary>
	/// <param name="movies"></param>
	void setMovies(std::vector<Movie*>* movies);

	/// <summary>
	/// Widget::setMouseState() override. Determines which UI components
	/// can interact with the mouse depending on the state of the layout.
	/// </summary>
	/// <param name="mouseState"></param>
	void setMouseState(graphics::MouseState mouseState) override;

	/// <summary>
	/// Sets the selected movie.
	/// </summary>
	/// <param name="movieIndex"></param>
	void setSelectedMovie(int movieIndex);

	/// <summary>
	/// Sets all the available genres.
	/// </summary>
	/// <param name="genres"></param>
	void setGenres(std::vector<std::string>* genres);
};