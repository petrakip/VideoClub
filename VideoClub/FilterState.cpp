#include "FilterState.h"
#include "Helpers.h"

void FilterState::setGenres(std::vector<std::string>* genres)
{
	for (std::string g : *genres)
		this->genres.insert_or_assign(g, true);
}

bool FilterState::shouldDisplay(Movie* movie)
{
	bool result = false;

	// Genres, duration and year filters are combined with an AND condition,
	// which means that for a movie to appear it has to conform to all three
	// conditions.

	// Filter for genres first.
	for (std::string genre : movie->genres)
		if (this->genres.at(genre)) {
			result = true;
			break;
		}

	// Duration filter
	result = result && movie->duration <= maxDuration;

	// Year filter
	result = result && movie->year >= minYear && movie->year <= maxYear;

	// if any of the text boxes are filled, ignore genres, duration and year filters.
	if (!director.empty() || !actor.empty() || !title.empty())
		result = false;

	// Text filters are designed to be combined with an OR condition,
	// which means that whatever text is entered into any of the textboxes,
	// will force a movie that fits the criteria to appear.

	// Filter for directors.
	if (!director.empty()) {
		for (std::string d : movie->directors)
			if (toLowerCase(d).find(director) != std::string::npos) {
				result = true;
				break;
			}
	}

	// Filter for actors.
	if (!actor.empty()) {
		for (std::string d : movie->actors)
			if (toLowerCase(d).find(actor) != std::string::npos) {
				result = true;
				break;
			}
	}

	// Filter for title.
	if (!title.empty())
		result = result || toLowerCase(movie->name).find(title) != std::string::npos;

	return result;
}

void FilterState::setDirector(std::string value)
{
	director = value;
}

void FilterState::setActor(std::string value)
{
	actor = value;
}

void FilterState::setTitle(std::string value)
{
	title = value;
}

void FilterState::setMaxDuration(int value)
{
	maxDuration = value;
}

void FilterState::setMinYear(int value)
{
	minYear = value;
}

void FilterState::setMaxYear(int value)
{
	maxYear = value;
}

FilterState::~FilterState()
{
	std::map<std::string, bool>().swap(genres);
}

void FilterState::setActiveGenre(std::string genre, bool active)
{
	this->genres.insert_or_assign(genre, active);
}
