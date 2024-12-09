#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int> A(N, 0); // Initialize an array A with all zeros

    // Try to reconstruct the original array A based on array B
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int sum = B[i] + B[j];
            if (sum % 2 != 0) {
                std::cout << "NO" << std::endl;
                return 0;
            }
            A[i] = sum / 2;
            A[j] = B[i] - A[i];
        }
    }

    std::cout << "YES" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}