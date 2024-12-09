#include <iostream>
#include <string>

int main() {
    int N, K;
    std::cin >> N >> K;
    
    std::string S;
    std::cin >> S;
    
    for (int i = 0; i < K; i++) {
        std::string new_S = S;
        for (int j = 0; j < N; j++) {
            if (S[j] == 'A') {
                if (j > 0 && S[j-1] == 'A') {
                    new_S[j-1] = 'A';
                } else {
                    new_S[j-1] = 'B';
                }
            } else {
                if (j < N-1 && S[j+1] == 'A') {
                    new_S[j+1] = 'A';
                } else {
                    new_S[j+1] = 'B';
                }
            }
        }
        S = new_S;
    }
    
    std::cout << S << std::endl;
    
    return 0;
}