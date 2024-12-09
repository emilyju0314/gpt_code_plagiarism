#include <iostream>
#include <string>

bool canFullyEraseString(std::string s) {
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
    return (countA == 0 && countB == 0) || (countB == 0 && countC == 0);
}

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        std::string s;
        std::cin >> s;

        if(canFullyEraseString(s)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}