#ifndef __MOVIE_H__
#define __MOVIE_H__
#include <iostream>

class Movie
{
	friend class Movies;
private:
	std::string name;
	std::string rating;
	int watched;
public:
  Movie(std::string name, std::string rating, int watched);
	~Movie();
};
#endif