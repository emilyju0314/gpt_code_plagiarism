#include <iostream>
#include <string>

int main() {
    int N, K;
    std::string S;
    std::cin >> N >> K >> S;

    // Lowercase the K-th character in the string
    S[K-1] = tolower(S[K-1]);

    std::cout << S << std::endl;

    return 0;
}