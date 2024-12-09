#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);

    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int> diff(N);
    for (int i = 0; i < N; i++) {
        diff[i] = B[i] - A[i];
    }

    std::sort(diff.begin(), diff.end());

    for (int i = 0; i < N; i++) {
        if (diff[i] < 0 || diff[i] % 2 != 0) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }

    std::cout << "Yes" << std::endl;
    
    return 0;
}