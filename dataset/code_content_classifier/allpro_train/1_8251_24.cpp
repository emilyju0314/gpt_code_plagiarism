#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<double, double> pd;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef map<int, int> mapi;
typedef map<ll, ll> mapl;
double eps = 1e-12;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i > b; i--)
#define repl(i, a, b) for (ll i = a; i < b; i++)
#define perl(i, a, b) for (ll i = a; i > b; i--)
#define maploop(p, i) for (auto i = p.begin(); i != p.end(); i++)
#define Ceil(a, b) (((a % b) == 0) ? (a / b) : ((a / b) + 1))
#define stable [](const auto &a, const auto &b) { return a.fi < b.fi; }
#define ln cout << endl;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define tsolve(t) \
    ll t;         \
    cin >> t;     \
    while (t--)   \
    {             \
        solve();  \
    }

// ==================== Solve =====================
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    string tmp = s;
    sort(tmp.begin(), tmp.end());
    if (s == tmp)
    {
        cout << "YES" << endl;
        return;
    }
    bool f = 0, g = 0;
    rep(i, 0, n)
    {
        if (i < n - 1 && s[i] == '1' && s[i + 1] == '1')
            f = 1;
        if (f)
        {
            if (i < n - 1 && s[i] == '0' && s[i + 1] == '0')
                g = 1;
        }
    }
    if (f && g)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}
// ================================================
signed main()
{
    FASTIO

    tsolve(t)
        // solve();

        return 0;
}