#include <iostream>
#include <string>

int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    int slimes = 1;
    for (int i = 1; i < N; i++) {
        if (S[i] != S[i - 1]) {
            slimes++;
        }
    }

    std::cout << slimes << std::endl;

    return 0;
}