#include <graphics.h>
#include "ToggleGroup.h"

using namespace graphics;

ToggleGroup::~ToggleGroup()
{
	std::vector<Toggle*>().swap(options);

	// just clear the pointer since filterState is created elsewhere.
	filterState = nullptr;
}

void ToggleGroup::draw()
{
	Brush br;
	br.fill_color[0] = .06f;
	br.fill_color[1] = .06f;
	br.fill_color[2] = .06f;
	br.outline_opacity = .0f;

	drawRect(getX(), getY(), getWidth(), getHeight(), br);

	repositionOptions();
	for (Toggle* t : options)
		t->draw();
}

void ToggleGroup::update()
{
}

void ToggleGroup::repositionOptions()
{
	const int distance = 3;

	int currentX = getX() - (getWidth() / 2) + 2;
	int currentY = getY() - (getHeight() / 2) + 2;

	for (Toggle* t : options) {
		int possibleOverflow = currentX + t->getWidth() + distance;

		if (possibleOverflow > getX() + (getWidth() / 2)) {
			currentY += t->getHeight() + distance;
			currentX = getX() - (getWidth() / 2) + 2;
		}

		currentX += t->getWidth() / 2;
		t->setX(currentX);
		t->setY(currentY + (t->getHeight() / 2));
		currentX += (t->getWidth() / 2) + distance;
	}
}

void ToggleGroup::initialize(std::vector<std::string>* options)
{
	for (std::string option : *options) 
		this->options.push_back(new Toggle(option, 7));
}

void ToggleGroup::setMouseState(graphics::MouseState mouseState)
{
	Widget::setMouseState(mouseState);

	for (Toggle* t : options) {
		t->setMouseState(mouseState);
		if (t->isMouseOver() && mouseState.button_left_released) {
			t->toggle();
			filterState->setActiveGenre(t->getLabel(), t->getToggled());
		}
	}
}

void ToggleGroup::setFilterState(FilterState* filterState)
{
	this->filterState = filterState;
}

void ToggleGroup::reset()
{
	for (Toggle* t : options) {
		if (!t->getToggled()) {
			t->toggle();
			filterState->setActiveGenre(t->getLabel(), t->getToggled());
		}
	}
}
