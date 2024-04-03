#include "Movie.h"

Movie::Movie(std::string name, std::string rating, int watched)
		: name{name}, rating{rating}, watched{watched}
{
}

Movie::~Movie()
{
	std::cout << ">> Destructing Movie (" << this->name << ")" << std::endl;
}
