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

/* In this example, we define a base class HTMLElement that represents an HTML element. The HTMLElement class has a tag_ member variable that stores the tag name of the element, and a content_ member variable that stores the content of the element as a std::stringstream.

The HTMLElement class has an overloaded << operator that allows content to be added to the element. The str method generates the HTML string for the element by using a std::stringstream and the escape_html function to escape any special characters in the content.

We then define two derived classes, HTMLAnchor and HTMLParagraph, that represent specific HTML elements. The HTMLAnchor class takes an href argument in its constructor, which is added to the content of the element as an attribute.

In the main function, we create instances of HTMLParagraph and HTMLAnchor, add content to them using the << operator, and output the resulting HTML strings to the console using std::cout. */
