#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int B = 60;
const int MOD = 1e9 + 7;
int n, pot2[B], cnt[B][2];
vector<pair<int, long long int> > adj[N];
vector<long long int> mat;
long long int sum[N];
void dfs(int u) {
  for (int i = 0; i < (int)(B); i++) cnt[i][(sum[u] >> i) & 1]++;
  for (auto e : adj[u]) {
    int v;
    long long int c;
    tie(v, c) = e;
    if (sum[v] == -1) {
      sum[v] = sum[u] ^ c;
      dfs(v);
    } else {
      long long int cyc = sum[u] ^ sum[v] ^ c;
      if (cyc) mat.push_back(cyc);
    }
  }
}
vector<long long int> get_base(vector<long long int> m) {
  int sz = ((int)(m).size());
  vector<bool> vis(sz);
  vector<long long int> res;
  for (int j = 0; j < (int)(B); j++) {
    int i = -1;
    for (int ii = 0; ii < (int)(sz); ii++)
      if (!vis[ii] && ((m[ii] >> j) & 1)) {
        i = ii;
        break;
      }
    if (i != -1) {
      res.push_back(m[i]);
      vis[i] = true;
      for (int ii = 0; ii < (int)(sz); ii++)
        if (!vis[ii] && ((m[ii] >> j) & 1)) m[ii] ^= m[i];
    }
  }
  return res;
}
int power[B][2];
void add(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
int safe_add(int x, int y) {
  add(x, y);
  return x;
}
int comb2(int n) { return (long long int)n * (n - 1) / 2 % MOD; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  pot2[0] = 1;
  for (int n = (int)(1); n < ((int)B); n++) pot2[n] = 2LL * pot2[n - 1] % MOD;
  int m;
  cin >> n >> m;
  while (m--) {
    int u, v;
    long long int c;
    cin >> u >> v >> c;
    u--;
    v--;
    adj[u].emplace_back(v, c);
    adj[v].emplace_back(u, c);
  }
  int res = 0;
  memset(sum, -1, sizeof sum);
  for (int u = 0; u < (int)(n); u++)
    if (sum[u] == -1) {
      mat.clear();
      memset(cnt, 0, sizeof cnt);
      sum[u] = 0;
      dfs(u);
      auto base = get_base(mat);
      for (int i = 0; i < (int)(B); i++)
        for (int j = 0; j < (int)(2); j++) power[i][j] = 1 - j;
      for (auto x : base) {
        for (int i = 0; i < (int)(B); i++) {
          int zi = power[i][0], oi = power[i][1];
          if ((x >> i) & 1) swap(zi, oi);
          add(power[i][0], zi);
          add(power[i][1], oi);
        }
      }
      for (int i = 0; i < (int)(B); i++) {
        int z1 = power[i][0], o1 = power[i][1];
        int z2 = safe_add(comb2(cnt[i][0]), comb2(cnt[i][1]));
        int o2 = (long long int)cnt[i][0] * cnt[i][1] % MOD;
        int more = ((long long int)z1 * o2 + (long long int)o1 * z2) % MOD;
        more = (long long int)more * pot2[i] % MOD;
        add(res, more);
      }
    }
  cout << res << endl;
  return 0;
}
