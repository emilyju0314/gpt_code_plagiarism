#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> B(M);
    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    long long total_taste = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            total_taste += static_cast<long long>(A[i]) * static_cast<long long>(B[j]);
        }
    }

    std::cout << total_taste << std::endl;

    return 0;
}