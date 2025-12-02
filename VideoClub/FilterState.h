#pragma once
#include <map>
#include <vector>
#include <string>
#include "Movie.h"

/// <summary>
/// Represents the current state of the filter. It's used by the 
/// MovieFilter widget to communicate to the Layout which movies should 
/// be displayed.
/// </summary>
class FilterState
{
private:
	/// <summary>
	/// A map keeping track of the genres to show (having value = true), 
	/// and which to hide (having value = false).
	/// </summary>
	std::map<std::string, bool> genres;

	/// <summary>
	/// The free text filter value for directors. If the string contained can be
	/// found anywhere within the directors of the movie, the movie is displayed.
	/// </summary>
	std::string director;

	/// <summary>
	/// The free text filter value for actors. If the string contained can be
	/// found anywhere within the actors of the movie, the movie is displayed.
	/// </summary>
	std::string actor;

	/// <summary>
	/// The free text filter value for the movie title. If the string contained can be
	/// found anywhere within the title of the movie, the movie is displayed.
	/// </summary>
	std::string title;

	/// <summary>
	/// The maximum duration filter value will only include movies with less than or 
	/// equal to that duration.
	/// </summary>
	int maxDuration;

	/// <summary>
	/// The minimum year at which a movie is considered visible.
	/// </summary>
	int minYear;

	/// <summary>
	/// The maximum year at which a movie is considered visible.
	/// </summary>
	int maxYear;

public:
	~FilterState();

	/// <summary>
	/// Activates or deactivates a genre.
	/// </summary>
	/// <param name="genre"></param>
	/// <param name="active"></param>
	void setActiveGenre(std::string genre, bool active);

	/// <summary>
	/// Load distinct available genres into the filter.
	/// </summary>
	/// <param name="genres"></param>
	void setGenres(std::vector<std::string>* genres);

	/// <summary>
	/// The main filter method, invoked for every movie, every time
	/// it is about to be drawn.
	/// </summary>
	/// <param name="movie"></param>
	/// <returns></returns>
	bool shouldDisplay(Movie* movie);

	/// <summary>
	/// Sets the director value.
	/// </summary>
	/// <param name="value"></param>
	void setDirector(std::string value);

	/// <summary>
	/// Sets the actor value.
	/// </summary>
	/// <param name="value"></param>
	void setActor(std::string value);

	/// <summary>
	/// Sets the title value.
	/// </summary>
	/// <param name="value"></param>
	void setTitle(std::string value);

	/// <summary>
	/// Sets the maximum duration value.
	/// </summary>
	/// <param name="value"></param>
	void setMaxDuration(int value);

	/// <summary>
	/// Sets the minimum year value.
	/// </summary>
	/// <param name="value"></param>
	void setMinYear(int value);

	/// <summary>
	/// Sets the maximum year value.
	/// </summary>
	/// <param name="value"></param>
	void setMaxYear(int value);
};