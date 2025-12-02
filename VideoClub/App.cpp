#include <fstream>
#include <map>

#include <graphics.h>

#include "App.h"
#include "Movie.h"
#include "config.h"
#include "MovieBox.h"
#include "Widget.h"
#include "Helpers.h"

App::App()
{
	loadData();

	layout = new Layout();
	layout->setX(0);
	layout->setY(0);
	layout->setWidth(CANVAS_WIDTH);
	layout->setHeight(CANVAS_HEIGHT);

	layout->setMovies(&this->movies);
	layout->setGenres(&this->genres);
}

App::~App()
{
	std::vector<Movie*>().swap(movies);
	std::vector<std::string>().swap(genres);
	delete layout;
}

void App::draw() {
	layout->draw();
}

void App::update()
{
	// retrieve mouse state.
	graphics::MouseState mouseState;
	graphics::getMouseState(mouseState);
	
	// update all widgets in the layout.
	layout->setMouseState(mouseState);

	// update layout to allow keyboard components to query the keyboard.
	layout->update();
}

void App::loadData() {
	std::map<std::string, int> genres;
	std::fstream dataFile;
	dataFile.open(std::string(ASSET_PATH) + "data.txt", std::ios::in);
	
	if (dataFile.is_open()) {
		std::string line;
		Movie* mv = new Movie();
		int counter = 0;
	
		while (getline(dataFile, line)) {
			counter++;

			switch (counter) {
				case 1: mv->name = line;							break;
				case 2: mv->year = std::stoi(line);					break;
				case 3: mv->duration = std::stoi(line);				break;
				case 4: mv->summary = line;							break;
				case 5: mv->image = line;							break;
				case 6: 
					splitString(line, ", ", &mv->genres);
					
					// use a map to keep distinct genres
					for (std::string g : mv->genres)
						genres.insert_or_assign(g, 1);

					break;
				
				case 7: splitString(line, ", ", &mv->directors);	break;
			
				case 8: 
					splitString(line, ", ", &mv->actors);		
					movies.push_back(mv);
					mv = new Movie();
					break;

				case 9: counter = 0; continue;
			}
		}

		dataFile.close();

		// move distinct genres from map into the final genres vector
		std::vector<std::string>().swap(this->genres);

		for (std::map<string, int>::const_iterator it = genres.begin(); it != genres.end(); it++) {
			this->genres.push_back(it->first);
		}
	}
}
