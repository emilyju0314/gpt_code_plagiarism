#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5, Mod = 998244353;
struct Edge {
  int nxt, to;
} e[maxn << 1];
int hd[maxn], e_cnt = 1;
void add(int u, int v) {
  e[++e_cnt] = (Edge){hd[u], v};
  hd[u] = e_cnt;
}
int n, f[maxn][3];
pair<int, int> inp[maxn];
void dfs(int u, int r) {
  int tmp[2] = {0, 1};
  bool flg = false;
  for (int i = hd[u]; i; i = e[i].nxt) {
    if (e[i].to == r) {
      flg = true;
      f[u][0] = tmp[0];
      f[u][2] = tmp[1];
      tmp[0] = 0;
    } else {
      dfs(e[i].to, u);
      if (flg) {
        f[u][0] = (long long)f[u][0] * (f[e[i].to][0] + f[e[i].to][1]) % Mod;
        f[u][2] = (long long)f[u][2] * (f[e[i].to][0] + f[e[i].to][1]) % Mod;
      }
      int cur[2];
      cur[0] = ((long long)tmp[1] * f[e[i].to][1] +
                (long long)tmp[0] * (f[e[i].to][0] + f[e[i].to][1])) %
               Mod;
      cur[1] = (long long)tmp[1] * (f[e[i].to][0] + f[e[i].to][2]) % Mod;
      tmp[0] = cur[0];
      tmp[1] = cur[1];
    }
  }
  f[u][1] = (tmp[0] + tmp[1]) % Mod;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) cin >> inp[i].first >> inp[i].second;
  add(1, 0);
  add(0, 1);
  for (int i = n - 1; i; i--)
    add(inp[i].first, inp[i].second), add(inp[i].second, inp[i].first);
  dfs(1, 0);
  cout << (f[1][0] + f[1][1]) % Mod << '\n';
  return 0;
}
