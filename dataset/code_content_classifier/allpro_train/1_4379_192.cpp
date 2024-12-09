#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int n, k;
int u[maxn], v[maxn];
int a[maxn], cnt[maxn];
vector<int> g[maxn];
int dfs(int u, int fa) {
  int& x = cnt[u];
  if (binary_search(a, a + k, u)) {
    ++x;
  }
  for (int v : g[u]) {
    if (v != fa) {
      x += dfs(v, u);
    }
  }
  return x;
}
int main() {
  scanf("%d%d", &n, &k);
  k <<= 1;
  for (int i = 0; i < k; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a, a + k);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &u[i], &v[i]);
    g[u[i]].push_back(v[i]);
    g[v[i]].push_back(u[i]);
  }
  dfs(1, -1);
  long long ans = 0;
  for (int i = 1; i < n; ++i) {
    ans += min(k - min(cnt[u[i]], cnt[v[i]]), min(cnt[u[i]], cnt[v[i]]));
  }
  cout << ans;
  return 0;
}
