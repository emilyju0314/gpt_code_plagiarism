#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 3 * (int)1e5 + 10;
ll T[maxN];
vector < pair < ll, int > > ask[maxN];
int m;
ll best[maxN];
ll pref[maxN];
ll valPref[maxN];
ll valSuf[maxN];
struct pt{
    ll x, y;
    pt(ll _x, ll _y) {
        x = _x;
        y = _y;
    }
};
vector < pt > vec;
bool del(const pt& x, const pt& y, const pt& z) {
    return (y.y - x.y) * (x.x - z.x) <= (z.y - x.y) * (x.x - y.x);
}
void add(ll x, ll y) {
    pt nw(x, y);
    while (vec.size() >= 2 && del(vec[vec.size() - 1], vec[vec.size() - 2], nw)) {
        vec.pop_back();
    }
    vec.push_back(nw);
}
ll get(const pt& a, ll y) {
    return (a.x * y + a.y);
}
const ll INF = 2 * (ll)1e18;
ll get(ll x) {
    if (vec.empty()) return -INF;
    int l = 0;
    int r = vec.size() - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (get(vec[m], x) > get(vec[m + 1], x)) {
            r = m;
        }
        else l = m;
    }
    return max(get(vec[r], x), get(vec[l], x));
}
void cl() {
    vec.clear();
}
ll c2[maxN];
void solve(int l, int r) {
    if (l == r) {
        for (auto it : ask[l]) {
            best[it.second] = max(best[it.second], valPref[l - 1] + valSuf[l + 1] + max(0LL, 1 - it.first));
        }
        return;
    }
    int mid = (l + r) / 2;
    solve(l, mid);
    solve(mid + 1, r);
    cl();
    for (int i = r + 1; i >= mid + 1 + 1; i--) {
        add(-i, -pref[i - 1] + c2[i + 1] + valSuf[i]);
    }
    ll best = -1e18;
    for (int i = l; i <= mid; i++) {
        best = max(best, get(i) + pref[i - 1] + c2[i] + valPref[i - 1]);
        for (auto it : ask[i]) {
            ::best[it.second] = max(::best[it.second], best + T[i] - it.first);
        }
    }
    cl();
    for (int i = l - 1; i <= mid - 1; i++) {
        add(i, pref[i] + c2[i] + valPref[i]);
    }
    best = -1e18;
    for (int i = r; i >= mid + 1; i--) {
        best = max(best, get(-i) - pref[i] + c2[i + 1] + valSuf[i + 1]);
        for (auto it : ask[i]) {
            ::best[it.second] = max(::best[it.second], best + T[i] - it.first);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> T[i];
        pref[i] = pref[i - 1] + T[i];
    }
    cin >> m;
    for (int i = 0; i <= n + 2; i++) {
        c2[i] = (1LL * i * i - i) / 2;
    }
    for (int i = 1; i <= m; i++) {
        int a;
        ll b;
        cin >> a >> b;
        ask[a].emplace_back(b, i);
        best[i] = 0;
    }
    valPref[0] = 0;
    // add 0
    add(0, pref[0] + c2[0]);
    for (int i = 1; i <= n; i++) {
        valPref[i] = valPref[i - 1];
        valPref[i] = max(valPref[i], get(-i) + c2[i + 1] - pref[i]);
        add(i, pref[i] + c2[i] + valPref[i]);
    }
    cl();
    valSuf[n + 1] = 0;
    add(-n - 1, -pref[n] + c2[n + 2]);
    for (int i = n; i >= 1; i--) {
        valSuf[i] = valSuf[i + 1];
        valSuf[i] = max(valSuf[i], get(i) + pref[i - 1] + c2[i]);
        add(-i, -pref[i - 1] + c2[i + 1] + valSuf[i]);
    }
    solve(1, n);
    for (int i = 1; i <= m; i++) cout << best[i] << '\n';
    return 0;
}