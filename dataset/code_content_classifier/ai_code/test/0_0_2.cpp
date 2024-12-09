#include <iostream>
#include <vector>
#include <unordered_map>

const int MOD = 1e9 + 7;

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    long long answer = 0;
    if (k == 1) {
        answer = (long long)n * m * (m + 1) / 2;
        answer %= MOD;
    } else {
        std::unordered_map<int, int> count;
        int prefix_sum = 0;
        count[0] = 1;
        
        for (int i = 0; i < n * m; i++) {
            prefix_sum = (prefix_sum + a[i % n]) % k;
            answer = (answer + count[(k - prefix_sum) % k]) % MOD;
            count[prefix_sum]++;
        }
    }

    std::cout << answer << std::endl;

    return 0;
}