#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int operations = 0;
    int current = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > current) {
            if ((A[i] - current) % 2 != 0) {
                std::cout << -1 << std::endl;
                return 0;
            } else {
                operations += (A[i] - current) / 2;
            }
        } else {
            operations += (A[i] - current);
        }
        current = A[i];
    }

    std::cout << operations << std::endl;

    return 0;
}