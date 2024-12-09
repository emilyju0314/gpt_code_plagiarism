#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::string colors;
    std::cin >> colors;

    std::unordered_map<char, int> colorCount;

    for (char c : colors) {
        colorCount[c]++;
    }

    bool possible = true;

    for (auto it = colorCount.begin(); it != colorCount.end(); it++) {
        if (it->second == n) {
            possible = true;
            break;
        } else if (it->second == 1) {
            continue;
        } else {
            possible = false;
            break;
        }
    }

    if (possible) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}