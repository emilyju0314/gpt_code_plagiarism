#include <bits/stdc++.h>
using namespace std;
const long long maxn = 60 + 10;
const long long maxm = 1e3 + 10;
const long long INF = 0x3f3f3f3f;
const long long dx[] = {0, 0, -1, 1};
const long long dy[] = {1, -1, 0, 0};
const long long P = 1e9 + 7;
long long k, n;
long long power(long long a, long long b) {
  long long ans = 1 % P;
  for (; b; b >>= 1) {
    if (b & 1) ans = ans * a % P;
    a = a * a % P;
  }
  return ans;
}
map<string, long long> m1;
long long dp[maxn][7];
void solve() {
  cin >> k >> n;
  memset(dp, 0, sizeof(dp));
  for (long long i = 1; i <= 6; i++) dp[1][i] = 1;
  for (long long i = 2; i <= k; i++)
    for (long long j = 1; j <= 6; j++)
      for (long long k = 1; k <= 6; k++)
        for (long long p = 1; p <= 6; p++) {
          if (j == p || j + p == 7 || k == p || k + p == 7) continue;
          dp[i][p] += dp[i - 1][j] * dp[i - 1][k];
          dp[i][p] %= P;
        }
  m1["white"] = 1;
  m1["yellow"] = 6;
  m1["green"] = 2;
  m1["blue"] = 5;
  m1["red"] = 3;
  m1["orange"] = 4;
  struct node {
    long long v[7];
    node() { memset(v, 0, sizeof(v)); }
  };
  map<long long, node> ans;
  map<long long, long long> col, vis;
  priority_queue<long long> pq;
  for (long long i = 1; i <= n; i++) {
    long long x;
    string s;
    cin >> x >> s;
    col[x] = m1[s];
    pq.push(x);
    vis[x] = 1;
  }
  while (!pq.empty()) {
    long long t = pq.top();
    pq.pop();
    node n1, n2;
    if (t >= pow(2, k - 1)) {
      node tmp;
      tmp.v[col[t]] = 1;
      ans[t] = tmp;
      if (!vis[t >> 1]) pq.push(t >> 1);
      continue;
    }
    if (!col[t << 1])
      for (long long i = 1; i <= 6; i++)
        n1.v[i] = dp[k - (long long)log2(t * 2)][i];
    else
      n1 = ans[t << 1];
    if (!col[t << 1 | 1])
      for (long long i = 1; i <= 6; i++)
        n2.v[i] = dp[k - (long long)log2(t * 2 + 1)][i];
    else
      n2 = ans[t << 1 | 1];
    node tmp;
    for (long long j = 1; j <= 6; j++)
      for (long long k = 1; k <= 6; k++)
        for (long long p = 1; p <= 6; p++) {
          if (j == p || k == p || j + p == 7 || k + p == 7) continue;
          tmp.v[p] += n1.v[j] * n2.v[k];
          tmp.v[p] %= P;
        }
    if (col[t]) {
      for (long long i = 1; i <= 6; i++) {
        if (i != col[t]) tmp.v[i] = 0;
      }
    } else {
      col[t] = 7;
    }
    ans[t] = tmp;
    if (t >= 2 && !vis[t / 2]) pq.push(t / 2), vis[t / 2] = 1;
  }
  long long res = 0;
  for (long long i = 1; i <= 6; i++) res = (res + ans[1].v[i]) % P;
  cout << res << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
