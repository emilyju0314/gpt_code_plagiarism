#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;

    bool validYYMM = false;
    bool validMMYY = false;

    int year = std::stoi(S.substr(0, 2));
    int month = std::stoi(S.substr(2, 2));

    if (year >= 1 && year <= 12) {
        validMMYY = true;
    }
    if (month >= 1 && month <= 12) {
        validYYMM = true;
    }

    if (validYYMM && validMMYY) {
        std::cout << "AMBIGUOUS" << std::endl;
    } else if (validYYMM) {
        std::cout << "YYMM" << std::endl;
    } else if (validMMYY) {
        std::cout << "MMYY" << std::endl;
    } else {
        std::cout << "NA" << std::endl;
    }

    return 0;
}