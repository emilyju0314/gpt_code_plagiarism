#include <iostream>
#include <vector>

const int MOD = 998244353;

long long solve(const std::vector<int>& a) {
    int n = a.size();
    std::vector<long long> sum(n, 0);
    std::vector<int> stack;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        while (!stack.empty() && a[i] < a[stack.back()]) {
            stack.pop_back();
        }
        if (stack.empty()) {
            sum[i] = (i + 1) * 1LL * a[i] % MOD;
        } else {
            sum[i] = (sum[stack.back()] + (i - stack.back()) * 1LL * a[i]) % MOD;
        }
        stack.push_back(i);
        ans = (ans + sum[i]) % MOD;
    }

    return ans;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        long long result = solve(a);
        std::cout << result << std::endl;
    }

    return 0;
}