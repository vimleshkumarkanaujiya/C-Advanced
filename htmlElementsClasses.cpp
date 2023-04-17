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

// Base class for HTML elements
class HTMLElement {
protected:
    std::string tag_;
    std::stringstream content_;

public:
    HTMLElement(const std::string& tag) : tag_(tag) {}
    virtual ~HTMLElement() {}

    // Add content to the element
    template<typename T>
    HTMLElement& operator<<(T&& val) {
        content_ << val;
        return *this;
    }

    // Generate the HTML string for the element
    virtual std::string str() const {
        std::stringstream ss;
        ss << "<" << tag_ << ">";
        ss << escape_html(content_.str());
        ss << "</" << tag_ << ">";
        return ss.str();
    }
};

// Derived classes for specific HTML elements
class HTMLAnchor : public HTMLElement {
public:
    HTMLAnchor(const std::string& href) : HTMLElement("a") {
        content_ << "href=\"" << escape_html(href) << "\"";
    }
};

class HTMLParagraph : public HTMLElement {
public:
    HTMLParagraph() : HTMLElement("p") {}
};

int main() {
    HTMLParagraph p;
    p << "This is a paragraph." << " This is some more text.";

    HTMLAnchor a("https://example.com");
    a << "Click me!";

    std::cout << p.str() << std::endl;
    std::cout << a.str() << std::endl;
    return 0;
}

