#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        std::cin >> numbers[i];
    }

    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    double max_value = 0;
    for (int i = 0; i < N - 3; i++) {
        for (int j = i + 1; j < N - 2; j++) {
            for (int k = j + 1; k < N - 1; k++) {
                for (int l = k + 1; l < N; l++) {
                    double value = (double) (numbers[i] + numbers[j]) / (numbers[k] - numbers[l]);
                    max_value = std::max(max_value, value);
                }
            }
        }
    }

    std::cout << std::fixed << std::setprecision(5) << max_value << std::endl;

    return 0;
}