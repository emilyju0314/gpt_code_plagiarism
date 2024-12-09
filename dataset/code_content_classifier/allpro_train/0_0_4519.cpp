#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

const int MOD = 1000000007;

int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (1LL * result * base) % MOD;
        }
        base = (1LL * base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, p;
    std::cin >> n >> p;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    std::vector<int> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }

    int res = 0;
    for (int x = 1; x <= n; x++) {
        std::vector<int> perm(n);
        std::iota(perm.begin(), perm.end(), 1);

        do {
            bool valid = true;
            for (int i = 0; i < x; i++) {
                if (a[perm[i] - 1] > i) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                res = (res + 1) % MOD;
            }
        } while (std::next_permutation(perm.begin(), perm.begin() + x));
    }

    int good = 0;
    std::vector<int> good_x;
    for (int x = 1; x <= n; x++) {
        if (res % p != 0) {
            good++;
            good_x.push_back(x);
        }

        res = (1LL * res * power(x, MOD - 2)) % MOD;
    }

    std::cout << good << std::endl;
    for (int x : good_x) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}