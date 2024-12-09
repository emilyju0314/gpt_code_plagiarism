#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
pair<int, int> a[100010];
int n;
vector<int> vx, vy;
vector<int> g[100010 << 1];
long long pw(long long a, int n) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = ret * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ret;
}
int sz[100010 << 1];
pair<int, int> p[100010 << 1];
int finds(int x) {
  return p[x].first == x ? x : p[x].first = finds(p[x].first);
}
void Union(int x, int y) {
  int a = finds(x), b = finds(y);
  if (a == b)
    p[a].second = 0;
  else {
    if (sz[a] > sz[b]) swap(a, b);
    sz[b] += sz[a];
    p[a].first = b;
    p[b].second &= p[a].second;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].first, &a[i].second);
    vx.push_back(a[i].first), vy.push_back(a[i].second);
  }
  sort(vx.begin(), vx.end()), sort(vy.begin(), vy.end());
  vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
  vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
  int u = vx.size(), v = vy.size();
  int tot = u + v;
  for (int i = 1; i <= tot; i++) p[i] = pair<int, int>(i, 1), sz[i] = 1;
  for (int i = 1; i <= n; i++) {
    a[i].first = lower_bound(vx.begin(), vx.end(), a[i].first) - vx.begin() + 1;
    a[i].second =
        lower_bound(vy.begin(), vy.end(), a[i].second) - vy.begin() + 1;
    Union(a[i].first, a[i].second + u);
  }
  long long ans = 1;
  for (int i = 1; i <= tot; i++)
    if (p[i].first == i) {
      long long num = pw(2, sz[i]);
      if (p[i].second) num--;
      ans = ans * num % mod;
    }
  printf("%lld\n", ans);
  return 0;
}
