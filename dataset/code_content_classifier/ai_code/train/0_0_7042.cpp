#include <iostream>
#include <string>
#include <algorithm>

bool areDigitsDistinct(int year) {
    std::string yearStr = std::to_string(year);
    std::sort(yearStr.begin(), yearStr.end());
    return std::adjacent_find(yearStr.begin(), yearStr.end()) == yearStr.end();
}

int main() {
    int y;
    std::cin >> y;

    int nextYear = y + 1;
    while (!areDigitsDistinct(nextYear)) {
        nextYear++;
    }

    std::cout << nextYear << std::endl;

    return 0;
}