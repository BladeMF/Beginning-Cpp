// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
	std::ifstream in_file{"romeoandjuliet"};
	std::ofstream out_file{"romeoandjuliet_out"};

	if (!in_file)
	{
		std::cerr << "Could not open input file" << std::endl;
		return 1;
	}

	if (!out_file)
	{
		std::cerr << "Could not open output file" << std::endl;
		return 1;
	}

	int line_number = 1;
	out_file << std::setfill(' ');
	std::string line;
	while (std::getline(in_file, line))
	{
		if (line.find_first_not_of("\r\n\t ") != std::string::npos)
		{
			out_file << std::setw(4) << line_number++ << "\t";
		}
		out_file << line << "\n";
	}
	out_file.close();
	in_file.close();

	return 0;
}
