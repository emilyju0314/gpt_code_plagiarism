#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;

    bool easilyPlayable = true;
    for (int i = 0; i < S.length(); i++) {
        if ((i % 2 == 0 && S[i] == 'L') || (i % 2 == 1 && (S[i] == 'R' || S[i] == 'U'))) {
            easilyPlayable = false;
            break;
        }
    }

    if (easilyPlayable) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}