#include <iostream>
#include <vector>

#define MOD 998244353

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> h(n);
    for(int i = 0; i < n; i++) {
        std::cin >> h[i];
    }

    long long ans = 0;
    for(int i = 1; i <= k; i++) {
        long long possible_suits = 1;
        for(int j = 0; j < n; j++) {
            if(i == h[j]) continue;
            possible_suits = (possible_suits * (k-1)) % MOD;
        }
        ans = (ans + possible_suits) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}