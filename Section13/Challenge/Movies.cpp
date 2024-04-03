#include "Movies.h"

Movie *Movies::find_movie(std::string name) const
{
	for (auto movie : movies)
	{
		if (movie->name == name)
		{
			return movie;
		}
	}
	return nullptr;
}

Movies::Movies() : movies{}
{
}

Movies::~Movies()
{
	std::cout << ">> Destructing Movies" << std::endl;
	for (auto movie : movies)
	{
		delete movie;
	}
}

void Movies::add_movie(std::string name, std::string rating, int watched)
{
	if (contains_movie(name))
	{
		std::cout << "ERROR: Movie '" << name << "' already exists" << std::endl;
		return;
	}
	movies.push_back(new Movie(name, rating, watched));
}

void Movies::add_watch(std::string name)
{
	auto movie = find_movie(name);
	if (movie == nullptr)
	{
		std::cout << "ERROR: Movie '" << name << "' does not exist." << std::endl;
		return;
	}
	movie->watched++;
}

bool Movies::contains_movie(std::string name) const
{
	return find_movie(name) != nullptr;
}

void Movies::display_movies() const
{
	std::cout << "--- Movies list ---\n";
	if (movies.size() == 0)
	{
		std::cout << "There are no movies." << std::endl;
		return;
	}

	for (auto movie : movies)
	{
		std::cout << "Name: " << movie->name << "; "
							<< "Rating: " << movie->rating << "; "
							<< "Watched: " << movie->watched << "; "
							<< "\n";
	}
	std::cout << "------" << std::endl;
}
