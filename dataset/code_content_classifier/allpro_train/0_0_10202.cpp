#include <iostream>

int main() {
    int N, K;
    std::cin >> N >> K;

    long long ans = 0;
    for (int b = K + 1; b <= N; ++b) {
        int m = N / b; // Number of multiples of b less than N
        int r = N % b; // Remaining numbers less than N
        ans += (long long)m * (b - K);
        ans += std::max(0, r - K);
    }

    std::cout << ans << std::endl;

    return 0;
}