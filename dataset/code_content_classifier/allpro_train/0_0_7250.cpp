#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<long long> A(N), rain(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        rain[i] = (A[(i+1)%N] + A[i])/2;
    }

    for (int i = 0; i < N; i++) {
        std::cout << rain[i] << " ";
    }

    return 0;
}