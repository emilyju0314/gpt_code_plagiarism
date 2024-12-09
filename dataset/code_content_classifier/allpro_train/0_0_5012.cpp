#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> beans(N);
    for (int i = 0; i < N; i++) {
        std::cin >> beans[i];
    }

    int Q;
    std::cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        int l, r, D;
        std::cin >> l >> r >> D;

        int min_diff = INT_MAX;
        for (int j = l; j <= r; j++) {
            int diff = std::abs(beans[j] - D);
            min_diff = std::min(min_diff, diff);
        }

        std::cout << min_diff << std::endl;
    }

    return 0;
}