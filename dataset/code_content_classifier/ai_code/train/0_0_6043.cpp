#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int N;
    std::cin >> N;

    std::vector<long long> T(N), A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> T[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<long long> height(N, 1); // Initialize all mountains to height 1
    for (int i = 1; i < N; i++) {
        if (T[i] > T[i - 1]) {
            height[i] = T[i]; // Update the min possible height
        }
    }
    for (int i = N - 2; i >= 0; i--) {
        if (A[i] > A[i + 1]) {
            height[i] = std::max(height[i], A[i]); // Update the max possible height
        }
    }

    long long result = 1;
    for (int i = 0; i < N; i++) {
        result = (result * height[i]) % MOD;
    }

    std::cout << result << std::endl;

    return 0;
}