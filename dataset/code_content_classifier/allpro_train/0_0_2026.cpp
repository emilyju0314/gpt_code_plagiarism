#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    std::vector<int> x(n);
    int m = n / 2;
    for (int i = 0; i < m; i++) {
        x[i * 2] = a[i + m];
    }
    for (int i = 0; i < n - m; i++) {
        x[i * 2 + 1] = a[i];
    }

    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += std::abs(x[i] - x[i + 1]);
    }

    std::cout << "The lexicographically smallest sequence x is: ";
    for (int i = 0; i < n; i++) {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}