#include <iostream>
#include <string>

bool canBeMatched(std::string s) {
    while (s.size() >= 3) {
        if (s.substr(0, 3) == "ABC") {
            s.erase(0, 3);
        } else if (s.substr(s.size() - 3) == "ABC") {
            s.erase(s.size() - 3);
        } else {
            return false;
        }
    }
    return s.empty();
}

int main() {
    std::string S;
    std::cin >> S;

    if (canBeMatched(S)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}