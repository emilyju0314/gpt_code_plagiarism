#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 998244353;

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> a(n+1), b(k+1), nxt(n+1), prev(n+1);
        for(int i = 1; i <= n; i++) {
            std::cin >> a[i];
            nxt[i] = i + 1;
            prev[i] = i - 1;
        }

        for(int i = 1; i <= k; i++) {
            std::cin >> b[i];
        }

        long long ans = 1;

        for(int i = 1; i <= n; i++) {
            int pos = a[i];
            int t = 0;

            if (b.back() == pos) {
                t++;
            }
            // Find the valid positions for a_i in array a
            if (prev[pos] != 0) {
                if (std::find(b.begin(), b.end(), prev[pos]) == b.end()) {
                    t++;
                }
                int pos_prev = prev[pos];
                prev[nxt[pos_prev]] = pos_prev;
                nxt[prev[pos]] = nxt[pos];
            }
            if (nxt[pos] != n+1) {
                if (std::find(b.begin(), b.end(), nxt[pos]) == b.end()) {
                    t++;
                }
                int pos_next = nxt[pos];
                prev[nxt[pos_next]] = pos;
                nxt[prev[pos]] = pos_next;
            }

            ans = (ans * t) % MOD;
            b.pop_back();
        }

        std::cout << ans << std::endl;
    }
    
    return 0;
}