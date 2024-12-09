#include <iostream>
#include <string>

int main() {
    int N;
    std::string S, T;
    std::cin >> N >> S >> T;
    
    for (int i = 0; i < N; i++) {
        std::cout << S[i] << T[i];
    }
    
    return 0;
}