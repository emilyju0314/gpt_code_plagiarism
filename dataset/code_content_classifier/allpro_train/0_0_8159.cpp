#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }

    int min_value = sequence[n-1];
    int steps = 0;

    for (int i = n-2; i >= 0; i--) {
        if (sequence[i] > min_value) {
            steps += abs(sequence[i] - min_value);
        } else {
            min_value = sequence[i];
        }
    }

    std::cout << steps << std::endl;

    return 0;
}