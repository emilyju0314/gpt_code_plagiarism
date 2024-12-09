#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    int n = s.length();
    std::unordered_map<char, char> mapping;

    for (int i = 0; i < n; i++) {
        if (mapping.find(s[i]) != mapping.end()) {
            if (mapping[s[i]] != t[i]) {
                std::cout << -1 << std::endl;
                return 0;
            }
        } else {
            mapping[s[i]] = t[i];
        }
    }

    int count = 0;
    for (const auto& pair : mapping) {
        if (pair.first != pair.second) {
            count++;
        }
    }

    std::cout << count << std::endl;
    for (const auto& pair : mapping) {
        if (pair.first != pair.second) {
            std::cout << pair.first << " " << pair.second << std::endl;
        }
    }

    return 0;
}