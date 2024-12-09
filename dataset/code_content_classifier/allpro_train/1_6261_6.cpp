#include <bits/stdc++.h>
using namespace std;
int uses[2100][2100] = {}, w[2100] = {}, h[2100] = {}, max_i, max_j;
void dfs(int i, int j) {
  if (0 <= i && i <= max_i && 0 <= j && j <= max_j && uses[i][j] == 0) {
    uses[i][j] = 2;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  char dir[2];
  vector<int> x(n + 1, 0), y(n + 1, 0);
  for (int i = 1, d; i <= n; ++i) {
    scanf("%s%d", dir, &d);
    x[i] = x[i - 1];
    y[i] = y[i - 1];
    if (dir[0] == 'L')
      x[i] -= d;
    else if (dir[0] == 'R')
      x[i] += d;
    else if (dir[0] == 'D')
      y[i] -= d;
    else
      y[i] += d;
  }
  set<int> xx(x.begin(), x.end()), yy(y.begin(), y.end());
  map<int, int> xxx, yyy;
  int i = 1, prev = *xx.begin() - 1;
  for (set<int>::iterator it = xx.begin(); it != xx.end(); ++it) {
    if (*it - prev - 1) w[i++] = *it - prev - 1;
    xxx[*it] = i;
    w[i++] = 1;
    prev = *it;
  }
  max_i = i;
  i = 1, prev = *yy.begin() - 1;
  for (set<int>::iterator it = yy.begin(); it != yy.end(); ++it) {
    if (*it - prev - 1) h[i++] = *it - prev - 1;
    yyy[*it] = i;
    h[i++] = 1;
    prev = *it;
  }
  max_j = i;
  for (int i = 0; i < n; ++i)
    if (x[i] == x[i + 1]) {
      int ci = xxx[x[i]], aj = yyy[y[i]], bj = yyy[y[i + 1]];
      for (int j = min(aj, bj); j <= max(aj, bj); ++j) uses[ci][j] = 1;
    } else {
      int aj = xxx[x[i]], bj = xxx[x[i + 1]], ci = yyy[y[i]];
      for (int j = min(aj, bj); j <= max(aj, bj); ++j) uses[j][ci] = 1;
    }
  dfs(0, 0);
  long long ans = 0;
  for (int i = 0; i <= max_i; ++i) {
    for (int j = 0; j <= max_j; ++j) {
      if (uses[i][j] != 2) ans += 1LL * w[i] * h[j];
    }
  }
  cout << ans << endl;
  return 0;
}
