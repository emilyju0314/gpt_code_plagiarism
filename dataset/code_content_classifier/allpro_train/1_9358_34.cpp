#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
const int N = 500100;
const int mod = 1e9 + 7;
vector<pair<int, int> > e[N];
map<long long, int> mp;
int fa[N], mi[N];
long long c[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int main() {
  int n = read(), m = read(), k = read(), Index = 0;
  mi[0] = 1;
  for (int i = 1; i <= n; ++i) mi[i] = 1ll * mi[i - 1] * 2 % mod;
  long long sum = (1ll << k);
  for (int i = 1; i <= n; ++i) c[i] = read();
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read();
    long long x = c[u] ^ c[v];
    if (!mp[x]) mp[x] = ++Index;
    e[mp[x]].push_back(make_pair(u, v));
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) fa[i] = i;
  for (int i = 1; i <= Index; ++i) {
    int siz = n;
    for (pair<int, int> j : e[i]) {
      int u = j.first, v = j.second;
      if (find(u) != find(v)) {
        fa[fa[u]] = fa[v];
        siz--;
      }
    }
    ans = (ans + mi[siz]) % mod;
    for (pair<int, int> j : e[i]) {
      int u = j.first, v = j.second;
      fa[u] = u, fa[v] = v;
    }
  }
  ans = (ans + 1ll * (sum - Index) % mod * mi[n] % mod) % mod;
  cout << ans;
  return 0;
}
