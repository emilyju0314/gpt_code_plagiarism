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

    for (int i = 0; i < N; i++) {
        std::cout << A[i] << std::endl;
    }

    return 0;
}