#include <iostream>
#include <vector>

int main() {
    int N, M;
    
    while (true) {
        std::cin >> N >> M;
        
        if (N == 0 && M == 0) {
            break;
        }
        
        std::vector<int> A(N);
        
        for (int i = 0; i < N; i++) {
            std::cin >> A[i];
        }
        
        int cost_per_person = M / N;
        int total_collected = 0;
        
        for (int i = 0; i < N; i++) {
            if (A[i] < cost_per_person) {
                total_collected += A[i];
            } else {
                total_collected += cost_per_person;
            }
        }
        
        std::cout << total_collected << std::endl;
    }
    
    return 0;
}