#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> heights(N);
    for (int i = 0; i < N; i++) {
        std::cin >> heights[i];
    }

    int operations = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            operations += heights[i];
        } else {
            if (heights[i] > heights[i-1]) {
                operations += heights[i] - heights[i-1];
            }
        }
    }

    std::cout << operations << std::endl;

    return 0;
}