// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

struct City
{
	std::string name;
	long population;
	double cost;
};

// Assume each country has at least 1 city
struct Country
{
	std::string name;
	std::vector<City> cities;
};

struct Tours
{
	std::string title;
	std::vector<Country> countries;
};

int count_digits(float number)
{
	float fraction = number - std::floor(number);
	std::cout << fraction << std::endl
						<< number << std::endl;
	int digits = 1;
	while (number > 10)
	{
		number /= 10;
		digits++;
	}

	return digits;
};

void print_line(int city_width, int population_width, int cost_width)
{
	char old_fill{std::cout.fill()};
	std::cout << std::setfill('-');
	std::cout << "+" << std::setw(city_width + 2) << ""
						<< "+" << std::setw(population_width + 2) << ""
						<< "+" << std::setw(cost_width + 2) << ""
						<< "+" << std::endl;
	std::cout << std::setfill(old_fill);
}

int main()
{
	Tours tours{
			"Tour Ticket Prices from Miami",
			{
					{
							"Colombia",
							{{"Bogota", 8778000, 400.98},
							 {"Cali", 2401000, 424.12},
							 {"Medellin", 2464000, 350.98},
							 {"Cartagena", 972000, 345.34}},
					},
					{
							"Brazil",
							{{"Rio De Janiero", 13500000, 567.45},
							 {"Sao Paulo", 11310000, 975.45},
							 {"Salvador", 18234000, 855.99}},
					},
					{
							"Chile",
							{{"Valdivia", 260000, 569.12},
							 {"Santiago", 7040000, 520.00}},
					},
					{"Argentina",
					 {{"Buenos Aires", 3010000, 723.77}}},
			}};

	std::string city_header{"City"};
	std::string population_header{"Population"};
	std::string cost_header{"Cost"};
	size_t max_city_width{city_header.size()};
	size_t max_population_width{population_header.size()};
	size_t max_price_width{cost_header.size()};
	for (auto country : tours.countries)
	{
		for (auto city : country.cities)
		{
			max_city_width = std::max<int>(max_city_width, city.name.size());
			max_population_width = std::max<int>(count_digits(city.population), max_population_width);
			max_price_width = std::max<int>(count_digits(city.cost), max_price_width);
		}
	}
	max_price_width += 3; // a dot and two digits

	// Unformatted display so you can see how to access the vector elements
	std::cout << std::fixed;
	std::cout << tours.title << std::endl;
	for (auto country : tours.countries)
	{ // loop through the countries
		std::cout << country.name << std::endl;
		print_line(max_city_width, max_population_width, max_price_width);
		std::cout << "| " << std::setw(max_city_width) << std::left << "City"
							<< " | " << std::setw(max_population_width) << std::right << "Population"
							<< " | " << std::setw(max_price_width) << std::right << "Cost"
							<< " |" << std::endl;
		print_line(max_city_width, max_population_width, max_price_width);
		for (auto city : country.cities)
		{ // loop through the cities for each country
			std::cout << "| " << std::setw(max_city_width) << std::left << city.name
								<< " | " << std::setprecision(0) << std::right << std::setw(max_population_width) << city.population
								<< " | " << std::setprecision(2) << std::right << std::setw(max_price_width) << city.cost
								<< " |" << std::endl;
			print_line(max_city_width, max_population_width, max_price_width);
		}
	}

	std::cout << std::endl
						<< std::endl;
	return 0;
}