#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string a, b;
    std::cin >> a >> b;

    // Remove leading zeroes
    a.erase(0, a.find_first_not_of('0'));
    b.erase(0, b.find_first_not_of('0'));

    int lenA = a.length();
    int lenB = b.length();

    if (lenA < lenB) {
        std::cout << "<";
    } else if (lenA > lenB) {
        std::cout << ">";
    } else {
        if (a < b) {
            std::cout << "<";
        } else if (a > b) {
            std::cout << ">";
        } else {
            std::cout << "=";
        }
    }

    return 0;
}