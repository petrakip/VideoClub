#include "MovieFilter.h"
#include "config.h"

using namespace graphics;

MovieFilter::MovieFilter(int yearMin, int yearMax, int durationMin, int durationMax)
{
	genreOptions = new ToggleGroup();
	director = new InputBox();
	actor = new InputBox();
	title = new InputBox();

	resetFilterButton = new Button("Clear Filter");

	year = new DoubleSlider(yearMin, yearMax);
	duration = new SingleSlider(durationMin, durationMax);
	duration->setValue(durationMax);
}

MovieFilter::~MovieFilter()
{
	delete genreOptions;
	delete director;
	delete actor;
	delete title;
	delete resetFilterButton;

	// filterState does not belong to us, just clear the pointer.
	filterState = nullptr;
}

void MovieFilter::draw()
{
	Brush br;
	br.fill_color[0] = .03f;
	br.fill_color[1] = .03f;
	br.fill_color[2] = .03f;
	br.outline_opacity = 1.0;
	drawRect(getX(), getY(), getWidth(), getHeight(), br);

	Brush tx;
	tx.fill_color[0] = 1.0f;
	tx.fill_color[1] = 1.0f;
	tx.fill_color[2] = 1.0f;
	setFont(std::string(ASSET_PATH) + "OpenSans-Bold.ttf");
	drawText(getX(), getY() + 95, 10, "filter", tx);
	
	drawLine(getX() - (getWidth() / 2) + 10, getY() + 83, getX() + (getWidth() / 2) - 10, getY() + 83, br);

	drawText(getX() - (getWidth() / 2) + 20, getY() - 80, 12, "Genres:", tx);
	genreOptions->setX(getX() - (getWidth() / 2) + 105);
	genreOptions->setY(getY() - 35);
	genreOptions->setWidth(170);
	genreOptions->setHeight(70);
	genreOptions->draw();

	setFont(std::string(ASSET_PATH) + "OpenSans-Bold.ttf");
	drawText(getX() + 10, getY() - 80, 12, "Director:", tx);
	director->setX(getX() + 95);
	director->setY(getY() - 60);
	director->setHeight(15);
	director->setWidth(170);
	director->draw();

	setFont(std::string(ASSET_PATH) + "OpenSans-Bold.ttf");
	drawText(getX() + 10, getY() - 35, 12, "Actor:", tx);
	actor->setX(getX() + 95);
	actor->setY(getY() - 20);
	actor->setHeight(15);
	actor->setWidth(170);
	actor->draw();

	setFont(std::string(ASSET_PATH) + "OpenSans-Bold.ttf");
	drawText(getX() + 10, getY() + 5, 12, "Title:", tx);
	title->setX(getX() + 95);
	title->setY(getY() + 20);
	title->setHeight(15);
	title->setWidth(170);
	title->draw();

	resetFilterButton->setX(getX() + 130);
	resetFilterButton->setY(getY() + 60);
	resetFilterButton->setWidth(100);
	resetFilterButton->setHeight(25);
	resetFilterButton->draw();

	setFont(std::string(ASSET_PATH) + "OpenSans-Bold.ttf");
	drawText(getX() - (getWidth() / 2) + 20, getY() + 27, 12, "Year:", tx);

	year->setX(getX() - (getWidth() / 2) + 135);
	year->setY(getY() + 25);
	year->setWidth(110);
	year->setHeight(20);
	year->draw();

	setFont(std::string(ASSET_PATH) + "OpenSans-Bold.ttf");
	drawText(getX() - (getWidth() / 2) + 20, getY() + 57, 12, "Duration:", tx);

	duration->setX(getX() - (getWidth() / 2) + 135);
	duration->setY(getY() + 55);
	duration->setWidth(110);
	duration->setHeight(20);
	duration->draw();
}

void MovieFilter::update()
{
	director->update();
	filterState->setDirector(director->getValue());

	actor->update();
	filterState->setActor(actor->getValue());

	title->update();
	filterState->setTitle(title->getValue());

	year->update();
	filterState->setMinYear(year->getLowerValue());
	filterState->setMaxYear(year->getUpperValue());

	duration->update();
	filterState->setMaxDuration(duration->getValue());
}

void MovieFilter::setGenres(std::vector<std::string>* genres)
{
	genreOptions->initialize(genres);
}

void MovieFilter::setFilterState(FilterState* filterState)
{
	this->filterState = filterState;
	genreOptions->setFilterState(filterState);
}

void MovieFilter::setMouseState(graphics::MouseState mouseState)
{
	Widget::setMouseState(mouseState);

	genreOptions->setMouseState(mouseState);
	director->setMouseState(mouseState);
	actor->setMouseState(mouseState);
	title->setMouseState(mouseState);
	resetFilterButton->setMouseState(mouseState);
	year->setMouseState(mouseState);
	duration->setMouseState(mouseState);

	if (resetFilterButton->isMouseOver() && mouseState.button_left_released) {
		director->setValue("");
		actor->setValue("");
		title->setValue("");
		genreOptions->reset();
		year->setLowerValue(year->getMin());
		year->setUpperValue(year->getMax());
		duration->setValue(duration->getMax());
	}
}
