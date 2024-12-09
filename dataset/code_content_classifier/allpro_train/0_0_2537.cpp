#include <iostream>
#include <vector>

#define MOD 1000000007
#define ll long long

ll solve(int n, std::vector<ll>& seq) {
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                ans += (seq[i] & seq[j]) * (seq[j] | seq[k]);
                ans %= MOD;
            }
        }
    }
    return ans;
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;
        std::vector<ll> seq(n);
        for(int i = 0; i < n; i++) {
            std::cin >> seq[i];
        }
        
        ll ans = solve(n, seq);
        std::cout << ans << std::endl;
    }

    return 0;
}