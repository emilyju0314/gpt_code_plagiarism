#include <bits/stdc++.h>
using namespace std;
const int inf = 21474836;
const int maxn = 2005;
const int F = 10;
map<string, int> d[maxn][10];
int start[maxn], dest[maxn];
int n;
int dp(int i, int j, string s) {
  if (d[i][j].count(s)) return d[i][j][s];
  d[i][j][s] = inf;
  string os = s;
  int val = 0;
  for (int k = 0; k < 4; k++) {
    int flo = s[k] - '0';
    if (flo == j) val++, s[k] = '0';
  }
  int pos = i + 1;
  for (int k = 0; k < 4; k++) {
    int flo = s[k] - '0';
    if (pos <= n && flo == 0 && start[pos] == j)
      s[k] = '0' + dest[pos], ++pos, ++val;
  }
  if (i == n && s == (string) "0000") {
    return d[i][j][os] = 0;
  }
  sort(s.begin(), s.end());
  for (int k = 3; k >= 0; k--) {
    if (s[k] - '0' != 0)
      d[i][j][os] =
          min(d[i][j][os], dp(pos - 1, s[k] - '0', s) + abs(j - (s[k] - '0')));
    else if (pos - 1 < n) {
      d[i][j][os] =
          min(d[i][j][os], dp(pos - 1, start[pos], s) + abs(j - start[pos]));
      break;
    }
  }
  return d[i][j][os];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &start[i], &dest[i]);
  }
  cout << dp(0, 1, "0000") + 2 * n;
  return 0;
}
