#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N), B(N);
    int sum_A = 0, sum_B = 0;

    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum_A += A[i];
    }

    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
        sum_B += B[i];
    }

    if (sum_A < sum_B) {
        std::cout << -1 << std::endl;
        return 0;
    }

    int diff_count = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] < B[i]) {
            diff_count += (B[i] - A[i]);
        }
    }

    std::cout << diff_count << std::endl;

    return 0;
}