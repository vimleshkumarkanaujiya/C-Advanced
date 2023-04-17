#include <iostream>
#include <regex>
#include <string>

int main() {
    // Input string
    std::string str = "The quick brown fox jumps over the lazy dog.";

    // Regular expression pattern
    std::regex pattern("the", std::regex_constants::icase);

    // Loop through matches
    for (auto it = std::sregex_iterator(str.begin(), str.end(), pattern); it != std::sregex_iterator(); ++it) {
        std::smatch match = *it;
        std::cout << "Matched at position " << match.position() << ": " << match.str() << std::endl;
    }

    return 0;
}

/* This program first defines an input string (str) and a regular expression pattern (pattern). The pattern in this case is the word "the", with the icase flag set to make the search case-insensitive.

The program then uses a for loop to search for all matches of the pattern in the string, using the std::sregex_iterator class. For each match, it retrieves the match object (std::smatch) and prints the position of the match and the matched substring to the console.

You can modify this program to search for different patterns, or to search for patterns in a file instead of a string, by adjusting the str and pattern variables. */

