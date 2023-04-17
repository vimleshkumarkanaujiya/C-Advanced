#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "example.txt";
    std::string search_string = "hello";
    std::string line;

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    while (std::getline(file, line)) {
        size_t pos = line.find(search_string);
        while (pos != std::string::npos) {
            std::cout << "Found \"" << search_string << "\" at position " << pos
                      << " on line: " << line << std::endl;
            pos = line.find(search_string, pos + 1);
        }
    }

    file.close();
    return 0;
}

