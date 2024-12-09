#include <iostream>
#include <cmath>

#define M 998244353
#define MOD 1000000007

int main() {
    long long n;
    std::cin >> n;

    long long ans = 0;
    long long mul = 1;
    long long i = 1;

    while (mul <= n) {
        ans = (ans + (((i - 1) % M) * mul) % M) % MOD;
        i++;
        mul = mul * 10;
    }

    ans = (ans + ((n - mul + 1) * (i - 1) % M) % MOD) % MOD;
    
    std::cout << ans << std::endl;

    return 0;
}