#include <iostream>
#include <string>
#include <cmath>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::string genome = "ACTG";
    int min_operations = INT_MAX;

    for (int i = 0; i <= n - 4; ++i) {
        int operations = 0;
        for (int j = 0; j < 4; ++j) {
            int diff_forward = std::abs(s[i + j] - genome[j]);
            int diff_backward = 26 - diff_forward;
            operations += std::min(diff_forward, diff_backward);
        }
        min_operations = std::min(min_operations, operations);
    }

    std::cout << min_operations << std::endl;

    return 0;
}