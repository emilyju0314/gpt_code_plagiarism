#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<long long> A(N);
    std::vector<long long> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    long long total_cost = 0;
    long long remaining_materials = 0;
    for(int i = 0; i < N; i++) {
        long long available_materials = A[i] + remaining_materials;
        total_cost += std::min(available_materials, B[i]);
        remaining_materials = available_materials - B[i];
    }

    std::cout << total_cost << std::endl;

    return 0;
}