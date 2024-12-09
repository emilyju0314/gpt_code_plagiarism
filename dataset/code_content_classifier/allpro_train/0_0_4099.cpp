#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<double> probabilities(n);
    for (int i = 0; i < n; i++) {
        std::cin >> probabilities[i];
    }

    double expected_score = 0;
    double total_probability = 1.0;
    double current_block = 0;

    for (int i = 0; i < n; i++) {
        double p = probabilities[i];
        expected_score += total_probability * p * p * (current_block + 1); // Add the expected score of current block

        // Update the total probability and current block
        total_probability *= 1 - p;
        current_block = (1 - p) * (current_block + 1) + p;
    }

    std::cout << std::fixed;
    std::cout << expected_score << std::endl;

    return 0;
}