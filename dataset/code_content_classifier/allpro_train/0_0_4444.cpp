#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string genome1, genome2;
    std::cin >> genome1 >> genome2;

    if(genome1.length() != genome2.length()) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    int diff = 0;
    for(int i = 0; i < genome1.length(); i++) {
        if(genome1[i] != genome2[i]) {
            diff++;
        }
    }

    if(diff == 2) {
        std::sort(genome1.begin(), genome1.end());
        std::sort(genome2.begin(), genome2.end());
        if(genome1 == genome2) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}