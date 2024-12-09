#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::string s;
        std::cin >> n >> s;

        std::vector<std::vector<int>> cnt(26, std::vector<int>(n+1, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 26; j++) {
                cnt[j][i+1] = cnt[j][i] + (s[i] == ('a' + j));
            }
        }

        int ans = n;
        for(int j = 0; j < 26; j++) {
            int l = 0, r = n-1, res = 0;

            while(l < r) {
                if(s[l] == ('a' + j)) { l++; }
                else if(s[r] == ('a' + j)) { r--; }
                else { res += 2; l++; r--; }
            }

            if(l == r && s[l] != ('a' + j)) {
                res++;
            }

            for(int i = 0; i <= n; i++) {
                ans = std::min(ans, res + i - cnt[j][i] * 2);
            }
        }

        if(ans == n) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << ans << std::endl;
        }
    }

    return 0;
}