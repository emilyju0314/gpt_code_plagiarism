#include <iostream>
#include <string>
#include <set>

int main() {
    std::string username;
    std::cin >> username;

    std::set<char> uniqueChars;
    for (char c : username) {
        uniqueChars.insert(c);
    }

    if (uniqueChars.size() % 2 == 0) {
        std::cout << "IGNORE HIM!" << std::endl;
    } else {
        std::cout << "CHAT WITH HER!" << std::endl;
    }

    return 0;
}