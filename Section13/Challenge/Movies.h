#ifndef __MOVIES_H__
#define __MOVIES_H__
#include <iostream>
#include <vector>
#include "Movie.h"

class Movies
{
private:
	std::vector<Movie *> movies;
	Movie *find_movie(std::string name) const;

public:
	Movies();
	~Movies();
	void add_movie(std::string name, std::string rating, int watched);
	void add_watch(std::string name);
	bool contains_movie(std::string name) const;
	void display_movies() const;
};
#endif