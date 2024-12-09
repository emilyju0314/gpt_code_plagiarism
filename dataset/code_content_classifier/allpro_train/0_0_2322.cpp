#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int K;
    std::cin >> K;

    std::vector<int> A(K);
    for (int i = 0; i < K; i++) {
        std::cin >> A[i];
    }

    // Calculate the smallest possible number of children
    int n_min = 2;
    int n_max = 2;
    for (int i = K - 1; i >= 0; i--) {
        if (n_max < A[i]) {
            std::cout << -1 << std::endl;
            return 0;
        }
        n_min = ((n_min + A[i] - 1) / A[i]) * A[i];
        n_max = (n_max / A[i]) * A[i] + A[i] - 1;
    }

    std::cout << n_min << " " << n_max << std::endl;
    
    return 0;
}