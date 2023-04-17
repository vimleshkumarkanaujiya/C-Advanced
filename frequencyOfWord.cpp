#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

int main() {
    std::ifstream file("textfile.txt");
    if (!file) {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    std::unordered_map<std::string, int> word_count;
    std::string word;
    while (file >> word) {
        ++word_count[word];
    }

    for (const auto& [word, count] : word_count) {
        std::cout << word << ": " << count << "\n";
    }

    return 0;
}

/* In this example, we open a file and check if it was successfully opened. Then, we create an unordered_map with std::string as the key and int as the value. As we read the file line by line, we use the ++ operator to increment the count of each word in the word_count hashmap. Finally, we print out the word count for each word in the file.

This example demonstrates the use of an unordered_map to store and retrieve data quickly and efficiently. It also shows how easy it is to iterate over the elements of an unordered_map using the range-based for loop and the structured binding syntax. */
