#pragma once
#include "Widget.h"
#include "Toggle.h"
#include "FilterState.h"

/// <summary>
/// Represents a group of <see cref="Toggle"/> buttons.
/// </summary>
class ToggleGroup : public Widget
{
private:
	/// <summary>
	/// Keeps the shared filter state.
	/// </summary>
	FilterState* filterState = nullptr;
	
	/// <summary>
	/// The available toggle buttons.
	/// </summary>
	std::vector<Toggle*> options;

public:
	/// <summary>
	/// Destructor.
	/// </summary>
	~ToggleGroup();

	/// <summary>
	/// Widget::draw() override.
	/// </summary>
	void draw() override;

	/// <summary>
	/// Widget::update() override.
	/// </summary>
	void update() override;

	/// <summary>
	/// Repositions options before each draw().
	/// </summary>
	void repositionOptions();

	/// <summary>
	/// Initializes the options to be offered.
	/// </summary>
	/// <param name="options"></param>
	void initialize(std::vector<std::string>* options);

	/// <summary>
	/// Widget::setMouseState() override.
	/// </summary>
	/// <param name="mouseState"></param>
	virtual void setMouseState(graphics::MouseState mouseState) override;

	/// <summary>
	/// Sets the filter state.
	/// </summary>
	/// <param name="filterState"></param>
	void setFilterState(FilterState* filterState);

	/// <summary>
	/// Resets all toggles to the on position.
	/// </summary>
	void reset();
};

