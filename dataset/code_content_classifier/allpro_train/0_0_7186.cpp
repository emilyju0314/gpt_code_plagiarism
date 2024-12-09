#include <iostream>
#include <vector>

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = i + 1;
    }

    for (int q = 0; q < Q; q++) {
        int query, k;
        std::cin >> query >> k;

        if (query == 0) {
            std::cout << A[k - 1] << std::endl;
        } else if (query == 1) {
            int temp = A[k - 1];
            A[k - 1] = A[k];
            A[k] = temp;
        }
    }

    return 0;
}