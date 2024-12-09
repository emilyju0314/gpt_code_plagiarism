#include <bits/stdc++.h>
using namespace std;
template <class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first - t.first, s.second - t.second);
}
template <class S, class T>
ostream &operator<<(ostream &os, pair<S, T> p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
const long long inf = 1000000001;
const long long INF = (long long)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
vector<long long> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
vector<long long> dx2 = {1, 1, 0, -1, -1, -1, 0, 1},
                  dy2 = {0, 1, 1, 1, 0, -1, -1, -1};
const long long MOD = 1000000007;
const long long N = 100011;
vector<vector<long long> > G(N);
vector<vector<long long> > dp(N, vector<long long>(2));
vector<long long> d(N);
long long ans = 0;
void dfs(long long now, long long par) {
  long long res1 = 0, res2 = 0;
  long long ch_num = 0;
  for (long long ch : G[now]) {
    if (ch == par) continue;
    dfs(ch, now);
    chmax(res1, dp[ch][0]);
    chmax(res2, dp[ch][1]);
    ch_num++;
  }
  dp[now][0] = max(res1, res2) + ch_num - 1;
  dp[now][1] = res1 + 1;
  long long add = 0;
  if (par != -1) add++;
  chmax(ans, max(dp[now][1], dp[now][0] + add));
  chmax(dp[now][1], dp[now][0]);
  vector<long long> use(2), un(2);
  if (ch_num >= 2) {
    for (long long ch : G[now]) {
      if (use[0] <= dp[ch][1]) {
        use[1] = use[0];
        use[0] = dp[ch][1];
      } else if (use[1] <= dp[ch][1]) {
        use[1] = dp[ch][1];
      }
      if (un[0] <= dp[ch][0]) {
        un[1] = un[0];
        un[0] = dp[ch][0];
      } else if (un[1] <= dp[ch][0]) {
        un[1] = dp[ch][0];
      }
    }
  }
  chmax(ans, use[0] + use[1] + ch_num - 2 + add);
  chmax(ans, un[0] + un[1] + 1);
}
void dfs1(long long now, long long par, long long dis) {
  d[now] = dis;
  for (long long ch : G[now]) {
    if (ch == par) continue;
    dfs1(ch, now, dis + 1);
  }
}
signed main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < (long long)(n - 1); i++) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(0, -1);
  cout << ans << endl;
}
