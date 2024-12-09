#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    long long total_happiness = 0;

    for (int i = 0; i < N; i++) {
        total_happiness += (long long)A[i] * (i % 2 == 0 ? 1 : -1);
    }

    std::cout << total_happiness << std::endl;

    return 0;
}