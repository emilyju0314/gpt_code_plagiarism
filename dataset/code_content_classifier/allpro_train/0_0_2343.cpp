#include <iostream>
#include <vector>

#define MOD 998244353

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sequence(n);
    for(int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }

    long long ans = 0;

    for(int i = 0; i < n; i++) {
        int count_good_arrays = std::min(i + 1, n - i);
        ans = (ans + (long long)count_good_arrays * sequence[i]) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}