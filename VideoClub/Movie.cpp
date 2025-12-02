#include "Movie.h"

Movie::Movie()
{
}

Movie::~Movie()
{
	std::vector<std::string>().swap(genres);
	std::vector<std::string>().swap(actors);
	std::vector<std::string>().swap(directors);
}
