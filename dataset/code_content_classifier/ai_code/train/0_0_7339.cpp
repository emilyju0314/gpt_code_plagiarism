#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    long long minSadness = 0;
    std::sort(A.begin(), A.end());

    int median = A[N/2];
    for(int i = 0; i < N; i++) {
        minSadness += std::abs(A[i] - median);
    }

    std::cout << minSadness << std::endl;

    return 0;
}