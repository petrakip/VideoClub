#include <iostream>

#include "Layout.h"
#include "MovieBox.h"
#include "config.h"

Layout::Layout()
{
	// Mouse position initialization.

	mousePosition = new MousePosition();

	mousePosition->setX(CANVAS_WIDTH - 100);
	mousePosition->setY(CANVAS_HEIGHT - 20);

	// Movie popup initialization.

	moviePopup = new MoviePopup();

	moviePopup->setX(CANVAS_WIDTH / 2);
	moviePopup->setY(CANVAS_HEIGHT / 2);
	moviePopup->setWidth(CANVAS_WIDTH / 2);
	moviePopup->setHeight((CANVAS_HEIGHT * 80) / 100);

	// Filter state initialization.
	filterState = new FilterState();
}

Layout::~Layout()
{
	// we don't own this vector, so simply clear it.
	movies = nullptr;

	// swap the prefilled MovieBox vector with an empty one to release memory.
	std::vector<MovieBox*>().swap(movieBoxes);

	delete mousePosition;
	delete moviePopup;
	delete movieFilter;
	delete filterState;
}

void Layout::boxClicked_Callback(void* context, Widget* box)
{
	Layout* l = reinterpret_cast<Layout*>(context);
	l->setSelectedMovie(box->getData());

#if _DEBUG
	std::cout << "Selected a movie: " << box->getData() << std::endl;
#endif
}

void Layout::repositionMovies() {
	if (movies == nullptr) return;

	int currentX = (LAYOUT_BOX_WIDTH / 2) + LAYOUT_MARGIN;
	int currentY = (LAYOUT_BOX_HEIGHT / 2) + LAYOUT_MARGIN;

	for (MovieBox* mb : movieBoxes) {
		if (!filterState->shouldDisplay(movies->at(mb->getData()))) continue;

		int possibleOverflow = currentX
			+ LAYOUT_HORIZONTAL_SPACING
			+ LAYOUT_BOX_WIDTH
			+ LAYOUT_MARGIN;

		if (possibleOverflow > CANVAS_WIDTH) {
			currentY += LAYOUT_VERTICAL_SPACING;
			currentY += LAYOUT_BOX_HEIGHT;
			currentX = LAYOUT_BOX_WIDTH / 2 + LAYOUT_MARGIN;
		}

		mb->setX(currentX);
		mb->setY(currentY);
		mb->setWidth(LAYOUT_BOX_WIDTH);
		mb->setHeight(LAYOUT_BOX_HEIGHT);

		currentX += LAYOUT_HORIZONTAL_SPACING + LAYOUT_BOX_WIDTH;
	}
}

void Layout::draw()
{
#if _DEBUG
	mousePosition->draw();
#endif

	if (this->movies == nullptr) return;

	repositionMovies();
	for (MovieBox* mb : movieBoxes) {
		if (!filterState->shouldDisplay(movies->at(mb->getData()))) continue;
		mb->draw();
	}

	if (selectedMovieIndex > -1) {
		moviePopup->setMovie(movies->at(selectedMovieIndex));
		moviePopup->draw();
	}

	movieFilter->draw();
}

void Layout::update()
{
	movieFilter->update();
}

void Layout::setMovies(std::vector<Movie*>* movies)
{
	this->movies = movies;
	std::vector<MovieBox*>().swap(movieBoxes);

	if (movies == nullptr) return;
	
	int index = 0;
	int yearMin = 1000000;
	int yearMax = 0;
	int durationMin = 1000000;
	int durationMax = 0;

	for (Movie* movie : *movies) {
		MovieBox* mb = new MovieBox();

		mb->setImagePath(movie->image);
		mb->setData(index++);
		mb->setClickCallback(Layout::boxClicked_Callback, this);

		movieBoxes.push_back(mb);

		if (movie->year < yearMin) yearMin = movie->year;
		if (movie->year > yearMax) yearMax = movie->year;
		if (movie->duration < durationMin) durationMin = movie->duration;
		if (movie->duration > durationMax) durationMax = movie->duration;
	}

	// Movie filter initialization.
	if (movieFilter != nullptr) delete movieFilter;
	movieFilter = new MovieFilter(yearMin, yearMax, durationMin, durationMax);

	movieFilter->setX(CANVAS_WIDTH / 2);
	movieFilter->setY(-80);
	movieFilter->setWidth(400);
	movieFilter->setHeight(200);
	movieFilter->setFilterState(filterState);
}

void Layout::setGenres(std::vector<std::string>* genres) {
	movieFilter->setGenres(genres);
	filterState->setGenres(genres);
}

void Layout::setMouseState(graphics::MouseState mouseState)
{
	Widget::setMouseState(mouseState);

	if (selectedMovieIndex > -1) {
		// Stop boxes listening for mouse state if a movie is selected.
		for (auto& movieBox : movieBoxes) movieBox->clearMouseState();

		// If the mouse was clicked and it's not over the popup, close
		// the popup and resume events.
		if (mouseState.button_left_released && !moviePopup->isMouseOver())
			selectedMovieIndex = -1;
	} else {
		movieFilter->setMouseState(mouseState);
		
		if (movieFilter->isMouseOver()) {
			if (movieFilter->getY() < FILTER_OPEN_Y) {
				movieFilter->setY(movieFilter->getY() + 5);
			}
		} else if (!mouseState.dragging) {
			if (movieFilter->getY() > FILTER_CLOSED_Y) {
				movieFilter->setY(movieFilter->getY() - 5);
			}

			for (MovieBox* movieBox : movieBoxes) movieBox->setMouseState(mouseState);
		}
	}

	mousePosition->setMouseState(mouseState);
}

void Layout::setSelectedMovie(int movieIndex)
{
	selectedMovieIndex = movieIndex;
}
