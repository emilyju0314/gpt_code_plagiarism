#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    if (n == 1 || n == 2) {
        std::cout << "0" << std::endl;
    } else {
        int min_changes = n;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int a = b[0] + i;
                int b_diff = (b[1] + j) - a;
                int changes = std::abs(i) + std::abs(j);
                bool valid = true;

                for (int k = 2; k < n; ++k) {
                    a += b_diff;
                    if (std::abs(b[k] - a) > 1) {
                        valid = false;
                        break;
                    }
                    changes += std::abs(b[k] - a - b_diff);
                }

                if (valid) {
                    min_changes = std::min(min_changes, changes);
                }
            }
        }

        if (min_changes == n) {
            std::cout << "-1" << std::endl;
        } else {
            std::cout << min_changes << std::endl;
        }
    }

    return 0;
}