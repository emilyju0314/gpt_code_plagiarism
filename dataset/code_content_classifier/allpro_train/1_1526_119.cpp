#include <bits/stdc++.h>
using namespace std;
void solutionB();
int main() {
  ios_base::sync_with_stdio(false);
  solutionB();
  return EXIT_SUCCESS;
}
int n, a[128][5], c[5], cost[5];
int ans;
int base[6] = {500, 1000, 1500, 2000, 2500, 3000};
int get_score(int index) {
  int r = 0;
  for (int i = 0; i < 5; ++i) {
    if (a[index][i] == -1) continue;
    r += base[cost[i]] - a[index][i] * base[cost[i]] / 250;
  }
  return r;
}
void dfs(int v) {
  if (v == 5) {
    int res = -1;
    for (int m = 0; m <= 5000; ++m) {
      int min_m = 0;
      bool ok = true;
      for (int i = 0; i < 5; ++i) {
        int l, r, x;
        if (cost[i] < 5) {
          x = 1 << cost[i];
          r = (n + m - x * c[i]);
          if (r < 0) ok = false;
          r /= x;
          l = (n + m - 2 * x * c[i]);
          if (l < 0)
            l /= 2 * x;
          else {
            l /= 2 * x;
            ++l;
          }
          l = max(l, 0);
        } else {
          x = 1 << cost[i];
          r = (n + m - x * c[i]);
          if (r < 0) ok = false;
          r /= x;
          l = 0;
        }
        if (a[0][i] == -1) r = min(r, 0);
        if (l > r) ok = false;
        min_m = max(min_m, l);
      }
      if (!ok) continue;
      if (min_m <= m) {
        res = m;
        break;
      }
    }
    if (res == -1) return;
    if (get_score(0) > get_score(1)) {
      ans = min(ans, res);
    }
    return;
  }
  for (int i = 0; i < 6; ++i) {
    cost[v] = i;
    dfs(v + 1);
  }
}
int solve() {
  ans = 1000000009ll;
  for (int i = 0; i < 5; ++i) c[i] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 5; ++j)
      if (a[i][j] != -1) ++c[j];
  dfs(0);
  if (ans == 1000000009ll) return -1;
  return ans;
}
void solutionB() {
  for (; cin >> n;) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < 5; ++j) cin >> a[i][j];
    cout << solve() << '\n';
    cerr << endl;
  }
}
