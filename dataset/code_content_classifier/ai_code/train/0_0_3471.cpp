#include <iostream>
#include <string>
#include <unordered_set>

bool isDiverse(std::string s) {
    std::unordered_set<char> seen;
    char prev = 0;
    for(char c : s) {
        if(seen.count(c) || (prev != 0 && c - prev != 1)) {
            return false;
        }
        seen.insert(c);
        prev = c;
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;

        if(isDiverse(s)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}