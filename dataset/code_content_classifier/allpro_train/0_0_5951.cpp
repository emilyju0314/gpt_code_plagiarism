#include <iostream>
#include <vector>

int main() {
    int N, M, Q;
    std::cin >> N >> M >> Q;

    std::vector<int> trains(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int L, R;
        std::cin >> L >> R;
        for (int j = L; j <= R; j++) {
            trains[j]++;
        }
    }

    std::vector<int> prefixSum(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        prefixSum[i] = prefixSum[i - 1] + trains[i];
    }

    for (int i = 0; i < Q; i++) {
        int p, q;
        std::cin >> p >> q;
        std::cout << prefixSum[q] - prefixSum[p - 1] << std::endl;
    }

    return 0;
}