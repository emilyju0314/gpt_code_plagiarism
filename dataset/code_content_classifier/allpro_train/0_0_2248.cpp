#include <iostream>
#include <string>

int main() {
    int N, K;
    
    while (std::cin >> N >> K) {
        if (N == 0 && K == 0) {
            break;
        }
        
        std::string champernown = "0.";
        
        for (int i = 1; i <= N + K; i++) {
            champernown += std::to_string(i);
        }
        
        for (int i = N + 1; i <= N + K; i++) {
            std::cout << champernown[i];
        }
        std::cout << std::endl;
    }
    
    return 0;
}