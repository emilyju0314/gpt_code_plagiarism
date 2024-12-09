#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 998244353;

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

        std::sort(a.begin(), a.end());

        int mex = 0;
        int answer = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] >= mex) {
                mex++;
                answer = (1ll * answer * (i + 1)) % MOD;
            }
        }

        std::cout << answer << std::endl;
    }

    return 0;
}