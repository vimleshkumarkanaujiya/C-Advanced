#include <iostream>
#include <sstream>

// A helper function to escape HTML special characters
std::string escape_html(const std::string& str) {
    std::stringstream ss;
    for (const char& c : str) {
        switch (c) {
            case '&': ss << "&amp;"; break;
            case '<': ss << "&lt;"; break;
            case '>': ss << "&gt;"; break;
            case '"': ss << "&quot;"; break;
            case '\'': ss << "&#39;"; break;
            default: ss << c;
        }
    }
    return ss.str();
}

// Define functions for HTML elements
std::string html(const std::string& content) {
    return content;
}

template<typename... Args>
std::string a(const std::string& href, Args... args) {
    std::stringstream ss;
    ss << "<a href=\"" << escape_html(href) << "\">";
    ((ss << args), ...);
    ss << "</a>";
    return ss.str();
}

template<typename... Args>
std::string p(Args... args) {
    std::stringstream ss;
    ss << "<p>";
    ((ss << args), ...);
    ss << "</p>";
    return ss.str();
}

int main() {
    std::cout << html("Hello, world!") << std::endl;
    std::cout << a("https://example.com", "Click me!") << std::endl;
    std::cout << p("This is a paragraph.", " This is some more text.") << std::endl;
    return 0;
}

