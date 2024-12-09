#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int weights[33][33];
bool flag[33];
int search(int x, int sums, int limit) {
  if (sums > limit) return 0;
  if (x > n) return 1;
  int result = search(x + 1, sums, limit);
  for (int i = 1; i <= n && result < k; i++) {
    if (!flag[i] && weights[x][i]) {
      flag[i] = true;
      result = result + search(x + 1, sums + weights[x][i], limit);
      flag[i] = false;
    }
  }
  return result;
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    weights[u][v] = w;
  }
  int l = 0, r = 1000 * n;
  int result = -1;
  while (l <= r) {
    m = (l + r) / 2;
    if (search(1, 0, m) >= k) {
      result = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  cout << result << endl;
  return 0;
}
