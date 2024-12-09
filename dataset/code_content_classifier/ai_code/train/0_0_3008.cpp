#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;

    if (S[0] == 'A' && S[2] == 'C') {
        int count = 0;
        for (int i = 0; i < S.size(); i++) {
            if (i != 0 && i != 2 && i != S.size() - 1) {
                if (isupper(S[i])) {
                    count++;
                } else {
                    std::cout << "WA" << std::endl;
                    return 0;
                }
            }
        }
        if (count == 1) {
            std::cout << "AC" << std::endl;
        } else {
            std::cout << "WA" << std::endl;
        }
    } else {
        std::cout << "WA" << std::endl;
    }

    return 0;
}