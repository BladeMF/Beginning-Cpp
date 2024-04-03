#include <iostream>

using namespace std;

int main()
{
	const float SMALL_ROOM_PRICE{25};
	const float LARGE_ROOM_PRICE{35};
	const float SALES_TAX_RATE{6.F / 100};
	const int ESTIMATE_EXPIRY{30};

	int small_rooms, large_rooms;

	cout << "How many small rooms would you like to clean? " << flush;
	cin >> small_rooms;
	cout << "How many large rooms would you like to clean? " << flush;
	cin >> large_rooms;

	cout << "\n"
			 << endl;

	cout << "Estimate for carpet cleaning service\n"
			 << "Number of small rooms: " << small_rooms << "\n"
			 << "Number of large rooms: " << large_rooms << "\n"
			 << "Price per small room: $" << SMALL_ROOM_PRICE << "\n"
			 << "Price per large room: $" << LARGE_ROOM_PRICE << "\n"
			 << "Cost: $"
			 << (small_rooms * SMALL_ROOM_PRICE + large_rooms * LARGE_ROOM_PRICE)
			 << "\n"
			 << "Tax: $"
			 << SALES_TAX_RATE * (small_rooms * SMALL_ROOM_PRICE + large_rooms * LARGE_ROOM_PRICE) << "\n"
			 << "================================================================\n"
			 << "Total estimate: $"
			 << (small_rooms * SMALL_ROOM_PRICE + large_rooms * LARGE_ROOM_PRICE) * (1 + SALES_TAX_RATE)
			 << "\n"
			 << "This estimate is valid for " << ESTIMATE_EXPIRY << " days\n"
			 << endl;

	return 0;
}