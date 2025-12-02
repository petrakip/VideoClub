#include <graphics.h>

#include "MoviePopup.h"
#include "config.h"
#include "Helpers.h"

using namespace graphics;

void MoviePopup::setMovie(Movie* movie)
{
	this->movie = movie;
}

void MoviePopup::draw()
{
	Brush br;
	
	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;
	br.fill_opacity = 0.8f;
	br.outline_opacity = 1.0f;

	drawRect(getX(), getY(), getWidth(), getHeight(), br);

	Brush im;
	
	im.texture = std::string(ASSET_PATH) + movie->image;
	im.outline_opacity = isMouseOver() ? 1.0f : 0.0f;
	
	drawRect(getX() - 110, getY() + 10, getWidth() / 2, getHeight() * 85 / 100, im);

	Brush tx;

	tx.fill_color[0] = 1.0f;
	tx.fill_color[1] = 1.0f;
	tx.fill_color[2] = 1.0f;

	setFont(std::string(ASSET_PATH) + "OpenSans-Bold.ttf");
	drawText(getX() - (getWidth() / 2) + 15, getY() - 170, 15, movie->name, tx);

	// Summary
	int currentY = getY() - 150;
	setFont(std::string(ASSET_PATH) + "OpenSans-Regular.ttf");
	int textHeight = drawWrappedText(getX() + 25, currentY, 10, 550, movie->summary, tx);
	currentY += textHeight + 10;

	// Duration
	setFont(std::string(ASSET_PATH) + "OpenSans-Bold.ttf");
	drawText(getX() + 25, currentY, 10, "Duration:", tx);
	setFont(std::string(ASSET_PATH) + "OpenSans-Regular.ttf");
	drawText(getX() + 70, currentY, 10, std::to_string(movie->duration) + " minutes", tx);
	currentY += 15;

	// Release year
	setFont(std::string(ASSET_PATH) + "OpenSans-Bold.ttf");
	drawText(getX() + 25, currentY, 10, "Release Year:", tx);
	setFont(std::string(ASSET_PATH) + "OpenSans-Regular.ttf");
	drawText(getX() + 90, currentY, 10, std::to_string(movie->year), tx);
	currentY += 15;

	// Directed by
	setFont(std::string(ASSET_PATH) + "OpenSans-Bold.ttf");
	drawText(getX() + 25, currentY, 10, "Directed by:", tx);
	currentY += 12;
	setFont(std::string(ASSET_PATH) + "OpenSans-Regular.ttf");
	textHeight = drawWrappedText(getX() + 25, currentY, 10, 550, join(movie->directors, ", "), tx);
	currentY += textHeight + 5;

	// Starring
	setFont(std::string(ASSET_PATH) + "OpenSans-Bold.ttf");
	drawText(getX() + 25, currentY, 10, "Starring:", tx);
	currentY += 12;
	setFont(std::string(ASSET_PATH) + "OpenSans-Regular.ttf");
	textHeight = drawWrappedText(getX() + 25, currentY, 10, 550, join(movie->actors, ", "), tx);
	currentY += textHeight + 5;

	// Genres
	setFont(std::string(ASSET_PATH) + "OpenSans-Bold.ttf");
	drawText(getX() + 25, currentY, 10, "Genres:", tx);
	currentY += 12;
	setFont(std::string(ASSET_PATH) + "OpenSans-Regular.ttf");
	textHeight = drawWrappedText(getX() + 25, currentY, 10, 550, join(movie->genres, ", "), tx);
	currentY += textHeight + 5;
}

void MoviePopup::update()
{
}
