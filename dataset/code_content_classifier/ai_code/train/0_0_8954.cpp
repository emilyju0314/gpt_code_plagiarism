#include <iostream>
#include <vector>
#include <cmath>

int binomialCoefficient(int n, int k) {
    int res = 1;
    if (k > n - k) {
        k = n - k;
    }
    for (int i = 0; i < k; ++i) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res % 1000000007;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int li, ri, ki;
        std::cin >> li >> ri >> ki;

        for (int j = li - 1; j < ri; ++j) {
            a[j] += binomialCoefficient(ri - li + 1, j - li + 1) * ki;
            a[j] %= 1000000007;
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }

    return 0;
}