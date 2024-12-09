#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int max_diff = 0;
    int neg_sum = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            neg_sum += a[i];
        }
    }

    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
            total_sum += a[i];
        } else {
            total_sum -= a[i];
        }
    }

    max_diff = total_sum + 2 * neg_sum;

    std::cout << max_diff << std::endl;

    return 0;
}