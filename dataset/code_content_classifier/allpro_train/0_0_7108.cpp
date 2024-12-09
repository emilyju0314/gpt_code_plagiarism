#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(2*n);
    for (int i = 0; i < 2*n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    int sum_first_n = 0;
    int sum_last_n = 0;

    for (int i = 0; i < n; i++) {
        sum_first_n += a[i];
        sum_last_n += a[i+n];
    }

    if (sum_first_n == sum_last_n) {
        std::cout << "-1" << std::endl;
    } else {
        for (int i = 0; i < 2*n; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}