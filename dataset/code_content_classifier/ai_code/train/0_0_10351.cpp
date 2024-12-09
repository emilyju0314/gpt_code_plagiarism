#include <iostream>
#include <vector>

const int MOD = 1000000007;

int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (1LL * res * a) % MOD;
        }
        a = (1LL * a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> prefix_phi(n);
    prefix_phi[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefix_phi[i] = (1LL * prefix_phi[i - 1] * a[i]) % MOD;
    }

    int q;
    std::cin >> q;
    while (q--) {
        int li, ri;
        std::cin >> li >> ri;
        --li, --ri;
        int result = prefix_phi[ri];
        if (li > 0) {
            result = (1LL * result * power(prefix_phi[li - 1], MOD - 2)) % MOD;
        }
        std::cout << result << std::endl;
    }

    return 0;
}