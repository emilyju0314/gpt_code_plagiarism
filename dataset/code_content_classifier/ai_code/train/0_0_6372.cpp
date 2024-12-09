#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int left_zero = -1;
    int right_zero = -1;
    std::vector<int> result(n);

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            left_zero = i;
        }
        result[i] = i - left_zero;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0) {
            right_zero = i;
        }
        if (right_zero != -1) {
            result[i] = std::min(result[i], right_zero - i);
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << result[i] << " ";
    }

    return 0;
}