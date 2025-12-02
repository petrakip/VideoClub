#pragma once
#include "Widget.h"
#include "ToggleGroup.h"
#include "FilterState.h"
#include "InputBox.h"
#include "Button.h"
#include "SingleSlider.h"
#include "DoubleSlider.h"

/// <summary>
/// The movie filter component allowing users to find movies with 
/// different criteria.
/// </summary>
class MovieFilter : public Widget
{
private:
	/// <summary>
	/// The differen genre options available.
	/// </summary>
	ToggleGroup* genreOptions = nullptr;

	/// <summary>
	/// The state of the filter, used to select visible movies in the layout.
	/// </summary>
	FilterState* filterState = nullptr;

	/// <summary>
	/// The director free text filter.
	/// </summary>
	InputBox* director = nullptr;

	/// <summary>
	/// The actor free text filter.
	/// </summary>
	InputBox* actor = nullptr;

	/// <summary>
	/// The title free text filter.
	/// </summary>
	InputBox* title = nullptr;

	/// <summary>
	/// The button resetting the filter to its default settings.
	/// </summary>
	Button* resetFilterButton = nullptr;

	/// <summary>
	/// The min/max year filter.
	/// </summary>
	DoubleSlider* year = nullptr;

	/// <summary>
	/// The max duration filter.
	/// </summary>
	SingleSlider* duration = nullptr;

public:
	/// <summary>
	/// Constructor.
	/// </summary>
	/// <param name="yearMin"></param>
	/// <param name="yearMax"></param>
	/// <param name="durationMin"></param>
	/// <param name="durationMax"></param>
	MovieFilter(int yearMin, int yearMax, int durationMin, int durationMax);

	/// <summary>
	/// Destructor.
	/// </summary>
	~MovieFilter();

	/// <summary>
	/// Widget::draw() override.
	/// </summary>
	void draw() override;

	/// <summary>
	/// Widget::update() override.
	/// </summary>
	void update() override;

	/// <summary>
	/// Sets the available genres.
	/// </summary>
	/// <param name="genres"></param>
	void setGenres(std::vector<std::string>* genres);

	/// <summary>
	/// Sets the filter state to be shared by the layout and this object.
	/// </summary>
	/// <param name="filterState"></param>
	void setFilterState(FilterState* filterState);

	/// <summary>
	/// Widget::setMouseState() override.
	/// </summary>
	/// <param name="mouseState"></param>
	virtual void setMouseState(graphics::MouseState mouseState) override;
};

