#include <bits/stdc++.h>
using namespace std;
struct edge {
  int x, y, z;
};
inline bool operator<(const edge &a, const edge &b) { return a.z > b.z; }
inline edge make(int x, int y, int z) {
  static edge t;
  t.x = x, t.y = y, t.z = z;
  return t;
}
edge a[200010];
int n, m, a1[100010], a2[100010], f[200010], num = 0;
long long ans = 0;
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a1[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> a2[i];
  }
  for (int i = 1, k, x; i <= n; i++) {
    cin >> k;
    while (k--) {
      cin >> x;
      a[++num] = make(i, n + x, a1[i] + a2[x]);
      ans += a1[i] + a2[x];
    }
  }
  sort(a + 1, a + num + 1);
  for (int i = 1; i <= n + m; i++) {
    f[i] = i;
  }
  for (int i = 1; i <= num; i++) {
    int tx = find(a[i].x), ty = find(a[i].y);
    if (tx == ty) {
      continue;
    }
    ans -= a[i].z, f[tx] = ty;
  }
  cout << ans << endl;
  return 0;
}
