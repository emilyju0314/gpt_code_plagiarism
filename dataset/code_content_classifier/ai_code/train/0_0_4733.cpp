#include <iostream>
#include <vector>

#define MOD 1000000007

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    long long res = 0;
    for(int i = 0; i < n; i++) {
        long long prod = 1;
        for(int j = 0; j < n; j++) {
            if(j != i) {
                prod = (prod * a[j]) % MOD;
            }
        }
        res = (res + prod) % MOD;
    }

    long long denominator = 1;
    for(int i = 1; i <= k; i++) {
        denominator = (denominator * n) % MOD;
    }

    long long inverse = 1;
    for(int i = 1; i <= MOD - 2; i++) {
        inverse = (inverse * denominator) % MOD;
    }

    long long ans = (res * inverse) % MOD;
    std::cout << ans << std::endl;

    return 0;
}