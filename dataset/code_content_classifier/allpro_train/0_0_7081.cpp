#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    int sum_a = 0;
    for (auto ai : a) {
        sum_a += ai;
    }

    int max_possible_sum = N * (N - 1) - sum_a;

    if (sum_a <= max_possible_sum) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}