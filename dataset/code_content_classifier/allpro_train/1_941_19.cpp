#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

ll grundy[200][200];

ll dfs(ll w, ll b) {
    if(grundy[w][b] >= 0) return grundy[w][b];

    set<ll> se;
    if(w-1 >= 0) se.insert(dfs(w-1, b));
    if(b-1 >= 0) se.insert(dfs(w+1, b-1));
    for(ll i = 1; i <= b && i <= w; i++) se.insert(dfs(w, b-i));

    ll res = 0;
    while(se.count(res)) res++;
    return grundy[w][b] = res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll n; cin >> n;

    rep(i, 200) rep(j, 200) grundy[i][j] = -1;
    grundy[0][0] = 0;

    ll g = 0;
    rep(i, n) {
        ll w, b;
        cin >> w >> b;
        g ^= dfs(w, b);
    }

    if(g == 0) cout << 1 << endl;
    else cout << 0 << endl;
}

