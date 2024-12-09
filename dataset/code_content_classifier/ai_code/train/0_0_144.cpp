#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int> C(N-1);
    for (int i = 0; i < N-1; i++) {
        std::cin >> C[i];
    }

    int total_satisfaction = B[0];
    for (int i = 1; i < N; i++) {
        total_satisfaction += B[i];
        if (A[i] == A[i-1] + 1) {
            total_satisfaction += C[i-1];
        }
    }

    std::cout << total_satisfaction << std::endl;

    return 0;
}