#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }

    int iterations = 0;
    bool stabilized = false;

    while (!stabilized) {
        std::vector<int> newSequence = sequence;
        
        for (int i = 1; i < n - 1; i++) {
            newSequence[i] = std::min({sequence[i-1], sequence[i], sequence[i+1]});
        }

        if (newSequence == sequence) {
            stabilized = true;
        } else {
            sequence = newSequence;
            iterations++;
        }
    }

    std::cout << iterations << std::endl;

    for (int num : sequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}