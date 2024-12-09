#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int l, k;
    cin >> l >> k;
    vector<vector<ll>> dp(l+1, vector<ll>(2));
    dp[0][1] = 1;
    for (int i = 1; i <= l; ++i) {
        dp[i][0] += dp[i-1][1];
        dp[i][1] += dp[i-1][0];
        if(i >= k){
            dp[i][0] += dp[i-k][1];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= l; ++i) {
        ans += dp[i][0];
    }
    cout << ans << "\n";
    return 0;
}
