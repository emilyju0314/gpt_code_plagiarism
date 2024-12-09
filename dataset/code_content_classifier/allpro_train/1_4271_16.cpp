/* -> Written by <-
   -----------
  |K_A_Z_A_M_A|
  |___________|
  |    ___    |
  |   (^_^)   |
  |  /( | )\  |
  |____|_|____|
    H O A N G
*/

#include <bits/stdc++.h>

#define Task            ""
#define F               first
#define S               second
#define pb              push_back
#define bit(x, i)       ((x >> (i)) & 1)
#define inf             1e9 + 7
#define INF             1e18 + 7
#define ll              long long
#define debug(x)        cerr << #x << " is " << x << "\n";
//#define int           ll

using namespace std;

const int MOD = 1e9 + 7;
const int base = 131;
const int B = 32;
const int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy8[] = {1, -1, 0, 1, -1, 0, 1, -1};
const int dx4[] = {0, 0, 1, -1};
const int dy4[] = {1, -1, 0, 0};

int q, a[300005], c[300005];
int par[20][300005];
bool dd[300005];
int h[300005];

int jump(int x, int mid) {
    for (int j = 19; j >= 0; -- j)
        if (bit(mid, j))
            x = par[j][x];
    return x;
}

void solve(int test_case) {
    cin >> q >> a[1] >> c[1];
    dd[1] = 1;
    for (int i = 2; i <= q + 1; ++ i) {
        int t;
        cin >> t;
        if (t == 1) {
            cin >> par[0][i] >> a[i] >> c[i];
            ++ par[0][i];
            for (int j = 1; j <= 19; ++ j)
                par[j][i] = par[j-1][par[j-1][i]];
            h[i] = h[par[0][i]] + 1;
            dd[i] = 1;
        }
        else {
            int u, w;
            cin >> u >> w;
            ++ u;
            int l = -1, r = h[u]+1, x;
            while (r - l > 1) {
                int mid = (l + r) >> 1;
                x = jump(u, mid);
                if (dd[x])
                    l = mid;
                else
                    r = mid;
            }
            ll res = 0;
            ll ans = 0;
            while (l >= 0) {
                x = jump(u, l);
                if (a[x] >= w) {
                    a[x] -= w;
                    if (a[x] == 0) {
                        dd[x] = 0;
                    }
                    res += (ll)w * c[x];
                    ans += w;
                    break;
                }
                w -= a[x];
                res += (ll)a[x] * c[x];
                ans += a[x];
                dd[x] = 0;
                -- l;
            }
            cout << ans << " " << res << "\n";
            cout.flush(); // ko duoc thieu
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
    if (fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    int test_case = 1;
//    cin >> test_case;
//    prepare();
    for (int i = 1; i <= test_case; ++ i) {
        solve(i);
//        bf();
    }
    return 0;
}
