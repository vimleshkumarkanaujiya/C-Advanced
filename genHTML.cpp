#include <iostream>
#include <fstream>

int main() {
    // Create an HTML file named "index.html" in the current directory
    std::ofstream html_file("index.html");

    // Write the contents of the HTML file
    html_file << "<!DOCTYPE html>\n";
    html_file << "<html>\n";
    html_file << "<head>\n";
    html_file << "<title>My Website</title>\n";
    html_file << "</head>\n";
    html_file << "<body>\n";
    html_file << "<h1>Welcome to My Website</h1>\n";
    html_file << "<p>This is a static website created using C++.</p>\n";
    html_file << "</body>\n";
    html_file << "</html>\n";

    // Close the HTML file
    html_file.close();

    return 0;
}
