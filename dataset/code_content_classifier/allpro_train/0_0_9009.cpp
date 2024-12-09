#include <iostream>
#include <vector>

const int MOD = 490019;

int main() {
    int n, m, c;
    std::cin >> n >> m >> c;

    std::vector<int> a(n);
    std::vector<int> b(m);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int power = (i*i) * (j*j*j);
            sum += (long long) a[i] * b[j] * pow(c, power);
            sum %= MOD;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}