#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int X, N;
    std::cin >> X >> N;

    if (N == 0) {
        std::cout << X << std::endl;
        return 0;
    }

    std::vector<int> sequence(N);
    for (int i = 0; i < N; i++) {
        std::cin >> sequence[i];
    }

    std::sort(sequence.begin(), sequence.end());

    int nearest = -1;
    int min_diff = 101;
    for (int i = 1; i <= 100; i++) {
        if (std::find(sequence.begin(), sequence.end(), i) == sequence.end()) {
            int diff = abs(X - i);
            if (diff < min_diff || (diff == min_diff && i < nearest)) {
                min_diff = diff;
                nearest = i;
            }
        }
    }

    std::cout << nearest << std::endl;

    return 0;
}