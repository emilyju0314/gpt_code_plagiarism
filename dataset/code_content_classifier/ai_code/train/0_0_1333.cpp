#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> dp0(n + 1);
    std::vector<int> dp1(n + 1);

    dp0[1] = 1;
    dp1[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp0[i] = (dp1[i - 1] + dp0[i - 1]) % MOD;
        dp1[i] = (dp0[i - 1] + dp1[i - 1]) % MOD;
    }

    int result = (dp0[n] + dp1[n]) % MOD;
    std::cout << result << std::endl;

    return 0;
}