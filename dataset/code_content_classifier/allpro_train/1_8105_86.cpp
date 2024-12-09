#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
int fx[1000005];
int vis[1000005];
int n, m, u, v;
void init() {
  for (int i = 1; i <= n; i++) {
    fx[i] = i;
  }
}
int findx(int x) {
  if (fx[x] == x)
    return x;
  else
    return fx[x] = findx(fx[x]);
}
void unit(int x, int y) {
  int xx = fx[x], yy = fx[y];
  fx[xx] = fx[yy];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(a, 0, sizeof(a));
  memset(vis, 0, sizeof(vis));
  cin >> n >> m;
  init();
  long long quan = 0, edge = 0, num = n - 1;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    if (u == v) {
      quan++;
    } else {
      edge++;
      a[u]++;
      a[v]++;
      if (findx(u) != findx(v)) {
        unit(u, v);
        num--;
      }
    }
    vis[u] = 1;
    vis[v] = 1;
  }
  long long result = 0;
  result += quan * (quan - 1) / 2 + quan * edge;
  for (int i = 1; i <= n; i++) {
    result += a[i] * (a[i] - 1) / 2;
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] != 1) {
      num--;
    }
  }
  if (num != 0) {
    cout << 0 << endl;
  } else
    cout << result << endl;
  return 0;
}
