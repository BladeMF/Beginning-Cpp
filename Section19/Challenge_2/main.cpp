// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct StudentResponse
{
  std::string name;
  std::string response;
  int grade;
};

int main()
{
  std::vector<StudentResponse> responses{};
  std::fstream responsesFile{"responses.txt", std::fstream::in};
  if (!responsesFile)
  {
    cerr << "Could not open responses.txt" << std::endl;
    return 1;
  }

  std::string correct_responses{};
  std::string name{};
  std::string response{};
  std::getline(responsesFile, correct_responses);
  int total_grades = 0;
  while (responsesFile >> name)
  {
    responsesFile >> response;
    int grade = 0;
    for (size_t i = 0; i < correct_responses.length(); i++)
    {
      if (correct_responses[i] != response[i])
        continue;

      grade++;
    }

    responses.push_back({name, response, grade});
    total_grades += grade;
  }

  float average_grade = static_cast<float>(total_grades) / responses.size();
  responsesFile.close();

  cout << std::setprecision(4) << std::fixed;
  cout << std::setw(15) << std::left << "Name"
       << std::setw(15) << std::left << "Response"
       << std::setw(15) << std::right << "Grade"
       << std::endl;
  cout << std::setw(45) << std::setfill('-') << "" << std::setfill(' ') << std::endl;

  for (auto response : responses)
  {
    cout << std::setw(15) << std::left << response.name
         << std::setw(15) << std::left << response.response
         << std::setw(15) << std::right << response.grade
         << std::endl;
  }

  cout << std::setw(45) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
  cout << std::setw(30) << std::left << "Average grade:"
       << std::setw(15) << std::right << average_grade
       << std::endl;

  return 0;
}
