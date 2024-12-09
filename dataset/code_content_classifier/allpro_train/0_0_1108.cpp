#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string S;
    std::cin >> S;

    int count = 1;
    for (int i = 0; i < S.size()-1; ++i) {
        if (S[i] != S[i+1]) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}