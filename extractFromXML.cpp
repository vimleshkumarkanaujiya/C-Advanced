#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "example.xml";
    std::string tag = "name";
    std::string line;
    bool found_tag = false;

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    while (std::getline(file, line)) {
        size_t start_pos = line.find("<" + tag + ">");
        if (start_pos != std::string::npos) {
            found_tag = true;
            start_pos += tag.length() + 2; // skip past tag and opening bracket
            size_t end_pos = line.find("</" + tag + ">", start_pos);
            if (end_pos != std::string::npos) {
                std::cout << "Value of tag \"" << tag << "\": "
                          << line.substr(start_pos, end_pos - start_pos)
                          << std::endl;
            }
        }
    }

    if (!found_tag) {
        std::cout << "Tag \"" << tag << "\" not found in file." << std::endl;
    }

    file.close();
    return 0;
}

/* In this example, we define a filename string variable that stores the name of the XML file to search, a tag variable that stores the name of the tag whose value we want to extract, a line variable that stores each line of the file as it is read, and a found_tag boolean variable to keep track of whether we found the tag in the file.

We open the file using a std::ifstream object and check if it was opened successfully. If not, we print an error message and exit the program.

We then read each line of the file using a std::getline loop, and search for the opening tag using the find method of the std::string class. If the tag is found, we extract the value of the tag by finding the closing tag and using the substr method of the std::string class to extract the substring between the opening and closing tags.

If the tag is not found, we print a message to the console.

Finally, we close the file and return 0 to indicate success. */
