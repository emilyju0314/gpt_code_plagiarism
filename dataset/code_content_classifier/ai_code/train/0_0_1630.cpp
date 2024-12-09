#include <iostream>
#include <vector>

int main() {
    int N, D;
    std::cin >> N >> D;
    
    std::vector<int> distance(N);
    for (int i = 0; i < N; i++) {
        std::cin >> distance[i];
    }
    
    int Q;
    std::cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        int q;
        std::cin >> q;
        
        long long min_dist = D;
        long long sum = 0;
        
        for (int j = 0; j < N; j++) {
            if (j == q - 1) {
                continue;
            }
            sum += distance[j];
            min_dist = std::min(min_dist, std::abs(D - sum));
        }
        
        if (min_dist >= distance[q - 1]) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    
    return 0;
}