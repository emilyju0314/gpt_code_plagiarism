#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<double> max_distribution(n);
    for (int i = 0; i < n; i++) {
        std::cin >> max_distribution[i];
    }

    std::vector<double> min_distribution(n);
    for (int i = 0; i < n; i++) {
        std::cin >> min_distribution[i];
    }

    // Calculate the probability distribution for a on the first dice
    std::vector<double> a_distribution(n);
    for (int i = 0; i < n; i++) {
        a_distribution[i] = max_distribution[i] - (i > 0 ? max_distribution[i - 1] : 0);
    }

    // Calculate the probability distribution for b on the second dice
    std::vector<double> b_distribution(n);
    for (int i = 0; i < n; i++) {
        b_distribution[i] = min_distribution[i] - (i > 0 ? min_distribution[i - 1] : 0);
    }

    // Output the results
    for (int i = 0; i < n; i++) {
        std::cout << a_distribution[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < n; i++) {
        std::cout << b_distribution[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}