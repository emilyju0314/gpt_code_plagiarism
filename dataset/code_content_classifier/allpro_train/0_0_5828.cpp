#include <iostream>
#define MOD 1000000009

typedef long long ll;

ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    ll result = mod_pow(2, m, MOD) - 1;
    result = mod_pow(result, n, MOD);

    std::cout << result << std::endl;

    return 0;
}