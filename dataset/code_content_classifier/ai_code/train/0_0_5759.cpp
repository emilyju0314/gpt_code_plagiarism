#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> abbreviations;
    abbreviations["IAO'9"] = 1989;
    abbreviations["IAO'0"] = 1990;
    int currentYear = 1991;

    int n;
    std::cin >> n;

    while (n--) {
        std::string abbreviation;
        std::cin >> abbreviation;

        if (abbreviations.find(abbreviation) == abbreviations.end()) {
            abbreviations[abbreviation] = currentYear;
        }

        currentYear++;
    }

    for (const auto& entry : abbreviations) {
        std::cout << entry.second << std::endl;
    }

    return 0;
}