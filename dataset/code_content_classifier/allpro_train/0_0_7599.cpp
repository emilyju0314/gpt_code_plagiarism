#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    int size = 1 << N;
    std::vector<int> A(size);
    for (int i = 0; i < size; i++) {
        std::cin >> A[i];
    }

    std::vector<int> max_values(size);

    for (int i = 1; i < size; i++) {
        int max_value = 0;
        for (int j = 0; j < i; j++) {
            if ((j | i) <= i) {
                max_value = std::max(max_value, A[j] + A[i]);
            }
        }
        max_values[i] = max_value;
    }

    for (int i = 1; i < size; i++) {
        std::cout << max_values[i] << std::endl;
    }

    return 0;
}