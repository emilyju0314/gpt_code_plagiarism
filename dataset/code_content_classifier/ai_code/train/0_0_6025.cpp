#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        std::cin >> m;

        std::vector<int> responses(m);
        for (int j = 0; j < m; j++) {
            std::cin >> responses[j];
        }

        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += responses[j];
        }

        double mean = static_cast<double>(sum) / m;

        double var = 0;
        for (int j = 0; j < m; j++) {
            var += pow(responses[j] - mean, 2);
        }
        var = var / m;

        if (fabs(var - mean) < 0.000001) {
            std::cout << "uniform" << std::endl;
        } else {
            std::cout << "poisson" << std::endl;
        }
    }

    return 0;
}