#include <iostream>
#include <string>
#include <map>

int main() {
    int n;
    std::cin >> n;

    std::map<std::string, int> abbreviations;

    for (int i = 0; i < n; i++) {
        std::string abbreviation;
        std::cin >> abbreviation;

        std::string year = abbreviation.substr(4);
        int paddingZeros = 0;
        for (int j = 0; j < year.size(); j++) {
            if (year[j] == '0') {
                paddingZeros++;
            } else {
                break;
            }
        }

        int actualYear = std::stoi(year) + paddingZeros * 10;
        abbreviations[abbreviation] = actualYear;
    }

    for (auto& entry : abbreviations) {
        std::cout << entry.second << "\n";
    }

    return 0;
}