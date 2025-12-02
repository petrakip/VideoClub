#pragma once
#include "Movie.h"
#include "Layout.h"

/// <summary>
/// The central application class.
/// </summary>
class App
{
private:
	/// <summary>
	/// Loads movies data from a file. Expects the file to be in bin\assets\data.txt.
	/// 
	/// File format:
	/// Format:
	/// 1. Name
	/// 2. Year
	/// 3. Duration in minutes
	/// 4. Summary
	/// 5. Image
	/// 6. Genres (with delimiter: ', ')
	/// 7. Directors (with delimiter: ', ')
	/// 8. Actors (with delimiter: ', ')
	/// 9. < empty line >
	/// </summary>
	void loadData();
	
	/// <summary>
	/// Contains all loaded movies after initialization.
	/// </summary>
	std::vector<Movie*> movies;

	/// <summary>
	/// Contains distinct genres after initialization.
	/// </summary>
	std::vector<std::string> genres;

	/// <summary>
	/// Points to a <see cref="Layout" /> instance employed to draw
	/// the entire user interface.
	/// </summary>
	Layout* layout;

public:
	/// <summary>
	/// Constructor.
	/// </summary>
	App();

	/// <summary>
	/// Destructor.
	/// </summary>
	virtual ~App();

	/// <summary>
	/// Hook for the global draw function.
	/// </summary>
	void draw();

	/// <summary>
	/// Hook for the global update function.
	/// </summary>
	void update();
};

