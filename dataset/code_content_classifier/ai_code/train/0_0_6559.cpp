#include <iostream>
#include <string>

int main() {
    int N, K;
    std::string S;
    
    std::cin >> N >> S >> K;
    
    char matchChar = S[K-1];
    
    for(int i = 0; i < N; i++) {
        if(S[i] != matchChar) {
            std::cout << "*";
        } else {
            std::cout << S[i];
        }
    }
    
    return 0;
}