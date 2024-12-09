#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int a[N], x[N], y[N], ans[N];
int n, m;
int dfs(int k, int l1, int l2) {
  l2 = min(l2, x[k]);
  int r1 = max(l1 + 1, y[k]), r2 = l2 + 4;
  if (l1 > l2 || r1 > r2) return -1;
  int p = dfs(k + 1, r1 + 1, r2 + 1) - 1;
  if (p > 0) {
    int q = max(l1, p - 4);
    for (int i = q; i <= p; ++i) ans[i] = k;
    return q;
  }
  return l1 <= n + 1 && l2 >= n + 1 && k > m ? n + 1 : -1;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  fill(x, x + N, n + 1);
  fill(y, y + N, -1);
  m = 0;
  for (int i = 1; i <= n; ++i)
    if (a[i] > 0) {
      x[a[i]] = min(x[a[i]], i);
      y[a[i]] = max(y[a[i]], i);
      m = max(m, a[i]);
    }
  if (dfs(1, 1, 1) > 0) {
    cout << ans[n] << endl;
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
    cout << endl;
  } else {
    cout << "-1\n";
  }
  return 0;
}
