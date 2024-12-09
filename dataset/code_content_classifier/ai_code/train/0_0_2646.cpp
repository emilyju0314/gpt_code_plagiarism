#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> balloons(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        std::string row;
        std::cin >> row;
        for (int j = 0; j < n; j++) {
            balloons[i][j] = row[j] - '0';
        }
    }

    int max_product = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            for (int d = 1; d <= n; d++) {
                int product = 1;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if ((abs(r - i) * abs(c - j) == 0 && abs(r - i) + abs(c - j) < d) || (abs(r - i) == abs(c - j) && abs(r - i) < d)) {
                            product = (product * balloons[i][j]) % MOD;
                        }
                    }
                }
                max_product = std::max(max_product, product);
            }
        }
    }

    std::cout << max_product << std::endl;

    return 0;
}