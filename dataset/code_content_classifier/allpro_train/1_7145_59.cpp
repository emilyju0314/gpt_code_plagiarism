#include <bits/stdc++.h>
using namespace std;
const bool OnLineJudge = 1;
const int N = 200005;
int n, x, y, sp;
long long res;
vector<int> a[N];
inline int dfs(const int u, const int p) {
  int cnt = 0;
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (v != p) {
      int cur = dfs(v, u);
      sp += (cnt < 2 && cur);
      cnt += cur;
    }
  }
  if (cnt < 2) return 1;
  return 0;
}
int main() {
  if (!OnLineJudge) {
    freopen("input.inp", "r", stdin);
  }
  std ::ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> x >> y;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  if (n == 2)
    cout << x << "\n";
  else if (n == 3) {
    cout << x + min(x, y) << "\n";
  } else {
    if (x >= y) {
      bool check = false;
      for (int u = 1; u <= n; u++)
        if (a[u].size() == n - 1) check = true;
      res = 1ll * y * (n - 1);
      if (check) res += 1ll * (x - y);
    } else {
      dfs(1, 0);
      res = 1ll * sp * x + 1ll * y * (n - sp - 1);
    }
    cout << res << "\n";
  }
  return 0;
}
