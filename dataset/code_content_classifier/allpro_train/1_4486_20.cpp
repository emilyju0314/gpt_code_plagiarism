#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2e5 + 10;
int a[maxN];
ll dp[maxN];
int x[maxN];
ll pref[maxN];
map < ll, ll > mp[maxN];
ll solve(ll cur, int c) {
    if (c == 1) return cur;
    if (mp[c].count(cur)) return mp[c][cur];
    if (cur >= -pref[2]) return cur;
    int it = lower_bound(pref + 2, pref + c + 1, -cur) - pref;
    it -= 1;
    assert(-pref[it] >= cur);
    cur = -2 * pref[it] - cur;
    return mp[c][cur] = solve(cur, it - 1);

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; i++) pref[i] = pref[i - 1] + a[i];
    int m;
    cin >> m;
    while (m--) {
        ll cur;
        cin >> cur;
        cur -= pref[n - 1];
        cur = solve(cur, n - 2);
        cout << a[1] + pref[1] + cur << '\n';
    }
    /*for (int i = 1; i <= m; i++) {
        cin >> x[i];
    }
    dp[n - 1] = a[n - 1] - a[n];
    ll mn = -pref[n - 2] - dp[n - 1];
    for (int i = n - 2; i >= 1; i--) {
        dp[i] = a[i] + pref[i] + mn;
        mn = max(mn, -pref[i - 1] - dp[i]);
    }
    cout << dp[1];*/
    return 0;
}