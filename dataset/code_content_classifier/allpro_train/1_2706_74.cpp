//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>
//#include <ctime>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(nullptr)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define REP(n) FOR(O, 1, (n))
#define pb push_back
#define f first
#define s second
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<piii> viii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1000100, MAXK = 20;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ld PI = asin(1) * 2;

void setIO () {
    FAST_IO;
}

void setIO (string s) {
    setIO();
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int n, m;
ll k[MAXN];
ll c[MAXN];

int main()
{
    setIO();

    int t; cin >> t;
    while (t--)  {
        cin >> n >> m;
        FOR(i, 1, n) cin >> k[i];
        FOR(i, 1, m) cin >> c[i];
        sort(k+1, k+n+1);
        reverse(k+1, k+n+1);
        ll ans = 0ll;
        int id = 1;
        FOR(i, 1, n) {
            if (id <= m && id <= k[i]) {
                ans += c[id];
                id++;
            } else ans += c[k[i]];

        }
        cout << ans << "\n";
    }


    return 0;
}
