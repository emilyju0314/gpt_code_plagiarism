#include <iostream>
#include <string>

bool canEraseString(std::string s) {
    int countA = 0, countB = 0, countC = 0;
    for(char c : s) {
        if(c == 'A') {
            countA++;
        } else if(c == 'B') {
            countB++;
        } else if(c == 'C') {
            countC++;
        }
    }
    return ((countA == countB) && (countC == 0)) || ((countB == countC) && (countA == 0));
}

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        std::string s;
        std::cin >> s;

        if(canEraseString(s)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}