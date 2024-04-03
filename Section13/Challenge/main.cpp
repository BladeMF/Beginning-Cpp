#include <iostream>
#include "Movies.h"

int main()
{
	Movies movies{};
	movies.display_movies();
	movies.add_movie("The Predator", "PG13", 1);
	movies.add_movie("Commando", "PG13", 10);
	movies.display_movies();
	movies.add_movie("The Predator", "PG13", 1);
	movies.add_watch("The Predator");
	movies.add_watch("The Predator 2");
	movies.display_movies();
	return 0;
}