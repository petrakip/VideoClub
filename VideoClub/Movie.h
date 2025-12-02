#pragma once
#include <string>
#include <vector>

/// <summary>
/// A data class representing a movie's characteristics.
/// </summary>
class Movie
{
public:
	/// <summary>
	/// The name or title of the movie.
	/// </summary>
	std::string name;

	/// <summary>
	/// The duration of the movie.
	/// </summary>
	int duration;

	/// <summary>
	/// The production year of the movie.
	/// </summary>
	int year;

	/// <summary>
	/// A summary of the movie.
	/// </summary>
	std::string summary;

	/// <summary>
	/// The image of the movie. Expects a portrait image
	/// akin to a movie poster or a Video Club card.
	/// </summary>
	std::string image;
	
	/// <summary>
	/// The list of genres of the movie.
	/// </summary>
	std::vector<std::string> genres;

	/// <summary>
	/// The list of directors of the movie.
	/// </summary>
	std::vector<std::string> directors;

	/// <summary>
	/// The list of actors of the movie.
	/// </summary>
	std::vector<std::string> actors;
	
	/// <summary>
	/// Constructor.
	/// </summary>
	Movie();

	/// <summary>
	/// Destructor.
	/// </summary>
	~Movie();
};
