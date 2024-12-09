#include <bits/stdc++.h>

#define speedup ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr),cout.precision(12)
using namespace std;
using ll = long long;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())
#define fs first
#define sc second

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll cur = 0;
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') {
            cur += i - r;
            ++r;
        }
    }
    ll ans = cur;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, cur);
        if (s[i] == '*') {
            ++l;
            --r;
        } else {
            cur += l;
            cur -= r;
        }
    }
    cout << ans << '\n';
}

int main() {
    speedup;
    int t;
    cin >> t;
    while (t--)
        solve();
}
