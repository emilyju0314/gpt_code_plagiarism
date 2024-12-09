#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int d;
    while (true) {
        std::cin >> d;
        if (d == 0) break;

        std::vector<double> values(d+3);
        std::vector<int> error_indices;

        for (int i = 0; i < d+3; i++) {
            std::cin >> values[i];
        }

        for (int i = 0; i < d+3; i++) {
            double sum = 0;
            for (int j = 0; j < d+3; j++) {
                if (j != i) {
                    double term = 1.0;
                    for (int k = 0; k < d+3; k++) {
                        if (k != i && k != j) {
                            term *= (values[k] - values[j]) / (values[i] - values[j]);
                        }
                    }
                    sum += term;
                }
            }

            if (fabs(sum - values[i]) > 1.0) {
                error_indices.push_back(i);
            }
        }

        for (auto idx : error_indices) {
            std::cout << idx << std::endl;
        }
    }

    return 0;
}