#include <bits/stdc++.h>
using namespace std;
const int MXN = 300020;
const long long MOD = 998244353;
vector<int> adj[MXN];
long long dpdwn[MXN], dpup[MXN], dc[MXN], tmp[MXN];
int n;
long long P(long long a) {
  long long res = 1, b = MOD - 2;
  while (b > 0) {
    if (b & 1) {
      res *= a;
      res %= MOD;
    }
    a *= a;
    a %= MOD;
    b >>= 1;
  }
  return res;
}
long long divide(long long a, long long b) { return (a * P(b)) % MOD; }
void DFS(int v, int dad) {
  if (adj[v].size() == 1 && dad != -1) {
    dpdwn[v] = 0;
    dpup[v] = 1;
    dc[v] = 1;
  }
  dpup[v] = 1;
  dc[v] = 1;
  for (int i = 0; i < adj[v].size(); i++) {
    int u = adj[v][i];
    if (u == dad) continue;
    DFS(u, v);
    dpup[v] *= ((dpdwn[u] + dpdwn[u]) % MOD + dc[u]) % MOD;
    dpup[v] %= MOD;
    dc[v] *= (dpdwn[u] + dc[u]) % MOD;
    dc[v] %= MOD;
    tmp[u] = ((dpdwn[u] + dpdwn[u]) % MOD + dc[u]) % MOD;
  }
  for (int i = 0; i < adj[v].size(); i++) {
    int u = adj[v][i];
    if (u == dad) continue;
    dpdwn[v] += (dpup[u] * divide(dpup[v], tmp[u])) % MOD;
    dpdwn[v] %= MOD;
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    cin >> v >> u;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  DFS(1, -1);
  long long ans = (dpdwn[1] + dc[1]) % MOD;
  cout << ans << "\n";
}
