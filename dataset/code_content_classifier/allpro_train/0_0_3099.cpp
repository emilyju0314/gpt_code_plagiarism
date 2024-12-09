#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N;
    
    std::vector<int> T(N);
    for (int i = 0; i < N; i++) {
        std::cin >> T[i];
    }
    
    std::cin >> M;
    
    for (int i = 0; i < M; i++) {
        int P, X;
        std::cin >> P >> X;
        int total_time = 0;
        
        for (int j = 0; j < N; j++) {
            if (j == P-1) {
                total_time += X;
            } else {
                total_time += T[j];
            }
        }
        
        std::cout << total_time << std::endl;
    }
    
    return 0;
}