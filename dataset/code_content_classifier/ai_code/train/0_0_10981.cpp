#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;

    char current = S[0];
    int count = 0;

    for (int i = 1; i < S.length(); i++) {
        if (S[i] != current) {
            count++;
            current = S[i];
        }
    }

    std::cout << count << std::endl;

    return 0;
}