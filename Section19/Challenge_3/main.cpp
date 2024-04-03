// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    std::string search{};
    cout << "Enter the word to search: ";
    cin >> search;

    std::fstream searchFile{"romeoandjuliet.txt", std::fstream::in};
    if (!searchFile)
    {
        cerr << "Could not open romeoandjuliet.txt" << std::endl;
        return 1;
    }
    std::string found{};
    int totalWords{0};
    int matches{0};
    while (searchFile >> found)
    {
        totalWords++;
        if (found.find(search) != std::string::npos)
        {
            matches++;
        }
    }

    cout << "Total words: " << totalWords << std::endl;
    cout << "Matches: " << matches << std::endl;

    searchFile.close();
    cout << endl;
    return 0;
}
