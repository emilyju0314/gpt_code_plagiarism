#include <iostream>
#include <string>

int main() {
    std::string S, T;
    std::cin >> S >> T;

    int tLength = T.length();
    int sLength = S.length();

    for (int i = sLength - tLength; i >= 0; i--) {
        bool possible = true;
        std::string tempS = S;

        for (int j = 0; j < tLength; j++) {
            if (tempS[i + j] != T[j] && tempS[i + j] != '?') {
                possible = false;
                break;
            } else {
                tempS[i + j] = T[j];
            }
        }

        if (possible) {
            for (int k = 0; k < sLength; k++) {
                if (tempS[k] == '?') {
                    tempS[k] = 'a'; // Filling remaining '?' with 'a'
                }
            }

            std::cout << tempS << std::endl;
            return 0;
        }
    }

    std::cout << "UNRESTORABLE" << std::endl;
    return 0;
}