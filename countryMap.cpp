#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, std::string> countryCapitals;

    // Add country-capital pairs to the hashmap
    countryCapitals["USA"] = "Washington, D.C.";
    countryCapitals["Canada"] = "Ottawa";
    countryCapitals["United Kingdom"] = "London";
    countryCapitals["France"] = "Paris";
    countryCapitals["Germany"] = "Berlin";
    countryCapitals["India"] = "New Delhi";
    countryCapitals["China"] = "Beijing";
    countryCapitals["Japan"] = "Tokyo";
    countryCapitals["Brazil"] = "Brasilia";
    countryCapitals["Australia"] = "Canberra";

    // Access and print the capitals using country names
    std::cout << "Capital of India: " << countryCapitals["India"] << std::endl;
    std::cout << "Capital of France: " << countryCapitals["France"] << std::endl;
    std::cout << "Capital of Brazil: " << countryCapitals["Brazil"] << std::endl;

    // Iterate over the hashmap
    std::cout << "\nAll country-capital pairs:" << std::endl;
    for (const auto& pair : countryCapitals) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
