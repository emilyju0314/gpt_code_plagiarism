#include <iostream>
#include <vector>

void generateSequence(int N, int M, std::vector<int>& L) {
    std::vector<int> K(N + M - 1, 1);
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(i + j < N + M - 1) {
                K[i + j] &= (L[i] == j);
            }
        }
    }
    
    for(int i = 0; i < N + M - 1; ++i) {
        std::cout << K[i];
    }
    std::cout << std::endl;
}

int main() {
    int N, M;
    
    while (std::cin >> N >> M) {
        if(N == 0 && M == 0) {
            break;
        }
        
        std::vector<int> L(N);
        for(int i = 0; i < N; ++i) {
            std::cin >> L[i];
        }
        
        generateSequence(N, M, L);
    }
    
    return 0;
}