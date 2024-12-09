#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::string S;
    std::cin >> S;

    std::unordered_set<char> charSet;

    bool allUnique = true;
    for (char c : S) {
        if (charSet.count(c) > 0) {
            allUnique = false;
            break;
        }
        charSet.insert(c);
    }

    if (allUnique) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}