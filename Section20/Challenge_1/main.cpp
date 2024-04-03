// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

bool is_palindrome(const std::string &s)
{
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    std::deque<char> dq;
    std::string s2;
    std::copy_if(s.cbegin(), s.cend(), std::back_inserter(s2), [](unsigned char c)
                 { return std::isalnum(c); });
    std::transform(s2.cbegin(), s2.cend(), s2.begin(), [](unsigned char c)
                   { return std::tolower(c); });
    std::for_each(s2.begin(), s2.end(), [&dq](char c)
                  { dq.push_front(c); });
    return std::equal(s2.begin(), s2.end(), dq.begin());
}

int main()
{
    std::vector<std::string> test_strings{"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
                                          "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
                                          "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome"};

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result"
              << "String" << std::endl;
    for (const auto &s : test_strings)
    {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}