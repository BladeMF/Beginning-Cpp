// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include <algorithm>

class Song
{
	friend std::ostream &operator<<(std::ostream &os, const Song &s);
	std::string name;
	std::string artist;
	int rating;

public:
	Song() = default;
	Song(std::string name, std::string artist, int rating)
			: name{name}, artist{artist}, rating{rating} {}
	std::string get_name() const
	{
		return name;
	}
	std::string get_artist() const
	{
		return artist;
	}
	int get_rating() const
	{
		return rating;
	}

	bool operator<(const Song &rhs) const
	{
		return this->name < rhs.name;
	}

	bool operator==(const Song &rhs) const
	{
		return this->name == rhs.name;
	}
};

std::ostream &operator<<(std::ostream &os, const Song &s)
{
	os << std::setw(20) << std::left << s.name
		 << std::setw(30) << std::left << s.artist
		 << std::setw(2) << std::left << s.rating;
	return os;
}

void display_menu()
{
	std::cout << "\nF - Play First Song" << std::endl;
	std::cout << "N - Play Next song" << std::endl;
	std::cout << "P - Play Previous song" << std::endl;
	std::cout << "A - Add and play a new Song at current location" << std::endl;
	std::cout << "L - List the current playlist" << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song)
{
	std::cout << "Playing:\n"
						<< song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song)
{
	std::for_each(playlist.begin(), playlist.end(), [&current_song](const Song &song)
								{ std::cout << song << std::endl; });
	std::cout << "Current song:" << std::endl;
	std::cout << current_song << std::endl;
}

void create_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song);

int main()
{
	std::list<Song> playlist{
			{"God's Plan", "Drake", 5},
			{"Never Be The Same", "Camila Cabello", 5},
			{"Pray For Me", "The Weekend and K. Lamar", 4},
			{"The Middle", "Zedd, Maren Morris & Grey", 5},
			{"Wait", "Maroone 5", 4},
			{"Whatever It Takes", "Imagine Dragons", 3}};

	std::list<Song>::iterator current_song = playlist.begin();

	char option;

	do
	{
		display_menu();

		std::cin >> option;
		option = std::tolower(option);

		switch (option)
		{
		case 'f':
			current_song = playlist.begin();
			play_current_song(*current_song);
			break;
		case 'n':
			current_song++;
			if (current_song == playlist.end())
				current_song = playlist.begin();
			play_current_song(*current_song);
			break;
		case 'p':
			if (current_song == playlist.begin())
				current_song = playlist.end();
			current_song--;
			play_current_song(*current_song);
			break;
		case 'a':
			create_song(playlist, current_song);
			display_playlist(playlist, *current_song);
			break;
		case 'l':
			display_playlist(playlist, *current_song);
			break;
		}
	} while (option != 'q');

	std::cout << "Thanks for listening!" << std::endl;
	return 0;
}

void create_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song)
{
	std::string name;
	std::string artist;
	int rating{0};
	// When consuming whitespace-delimited input (e.g. int n; std::cin >> n;)
	// any whitespace that follows, including a newline character, will be left
	// on the input stream. Then when switching to line-oriented input, the
	// first line retrieved with getline will be just that whitespace.
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	do
	{
		std::cout << "Enter a song name: ";
		std::getline(std::cin, name);
	} while (name == "");

	do
	{
		std::cout << "Enter a song artist: ";
		std::getline(std::cin, artist);
	} while (artist == "");
	std::cout << "Enter a song rating: ";
	std::cin >> rating;
	playlist.emplace(current_song, name, artist, rating);
}
