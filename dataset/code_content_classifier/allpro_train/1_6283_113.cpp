#include <bits/stdc++.h>
using namespace std;
const int maxn = 2111, p = 1e9 + 7;
struct tree {
  int son[maxn][maxn], cnt[maxn], s[maxn], n;
  vector<int> v[maxn];
  void read() {
    cin >> n;
    for (int i = (1); i <= (n - 1); ++i) {
      int x, y;
      cin >> x >> y;
      v[x].push_back(y);
      v[y].push_back(x);
    }
  }
  void dfs(int x, int fa) {
    cnt[x] = 0;
    s[x] = 0;
    for (int y : v[x]) {
      if (y == fa) continue;
      son[x][++cnt[x]] = y;
      s[x] |= (1 << (y - 1));
      dfs(y, x);
    }
  }
} a, b;
int f[maxn][5000];
int dp(int x, int now, int S) {
  if (!now || !S) return !S;
  int &ret = f[a.son[x][now]][S];
  if (ret) return ret - 1;
  ret = dp(x, now - 1, S);
  for (int y = a.son[x][now], k = 0; k < b.n; ++k)
    if (S >> k & 1)
      ret = (ret +
             1ll * dp(x, now - 1, S - (1 << k)) * dp(y, a.cnt[y], b.s[k + 1])) %
            p;
  return ret++;
}
int poww(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * a % p;
    b >>= 1;
    a = 1ll * a * a % p;
  }
  return ans;
}
int main() {
  a.read();
  b.read();
  a.dfs(1, 0);
  int ans1 = 0, ans2 = 0;
  for (int i = (1); i <= (b.n); ++i) {
    b.dfs(i, 0);
    for (int j = (1); j <= (a.n); ++j)
      ans1 = (ans1 + dp(j, a.cnt[j], b.s[i])) % p;
    memset(f, 0, sizeof(f));
  }
  a = b;
  a.dfs(1, 0);
  for (int i = (1); i <= (b.n); ++i) {
    b.dfs(i, 0);
    for (int j = (1); j <= (a.n); ++j)
      ans2 = (ans2 + dp(j, a.cnt[j], b.s[i])) % p;
    memset(f, 0, sizeof(f));
  }
  ans1 = 1ll * ans1 * poww(ans2, p - 2) % p;
  cout << ans1;
}
