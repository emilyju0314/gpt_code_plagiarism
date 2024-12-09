#include <bits/stdc++.h>
using namespace std;
string s[2010];
int f[2010][2010], h[2010], n, m, tot, i;
int dp(int l, int r) {
  if (l == r) return n;
  int mid = min_element(h + l, h + r) - h, x = dp(l, mid), y = dp(mid + 1, r),
      z = ++tot, i, j;
  for (i = 0; i <= mid - l + 1; i++)
    for (j = 0; j <= r - mid; j++)
      f[z][i + j] = max(f[z][i + j], f[x][i] + f[y][j] + h[mid] * i * j);
  return z;
}
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++) cin >> s[i];
  sort(s + 1, s + n + 1);
  for (i = 1; i < n; i++)
    for (; h[i] < min(s[i].length(), s[i + 1].length()) &&
           s[i][h[i]] == s[i + 1][h[i]];
         h[i]++)
      ;
  cout << f[dp(1, n)][m] << endl;
}
