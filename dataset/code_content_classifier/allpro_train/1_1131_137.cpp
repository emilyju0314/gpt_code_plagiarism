#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> dis(v, vector<int>(v, 1e9));
    rep(i, e) {
        int s, t, d;
        cin >> s >> t >> d;
        dis[s][t] = d;
    }

    vector<vector<int>> dp((1 << v), vector<int>(v, 1e9));

    rep(i, v) dp[0][0] = 0;
    rep(s, 1 << v) {
        rep(now, v) {
            rep(to, v) {
                if ((s >> to) & 1 || dis[now][to] == 1e9) continue;
                chmin(dp[s|(1 << to)][to], dp[s][now] + dis[now][to]);
            }
        }
    }

    int ans = dp[(1 << v) - 1][0];
    cout << (ans == 1e9 ? -1 : ans) << endl;
    return 0;
}
