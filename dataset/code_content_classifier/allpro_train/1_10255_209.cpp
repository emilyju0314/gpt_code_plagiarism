#include <bits/stdc++.h>
using namespace std;
long long a[300001], n, i, j, k, top, t, c[300001], cut[300001], maxs, s;
int main() {
  cin >> n;
  maxs = -9999999999;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n - 1; i++) {
    memset(c, 0, sizeof(c));
    j = n;
    t = n - 2;
    while (a[j] != a[i]) j--;
    if (i == j) continue;
    s = a[i] + a[j];
    c[i] = 1;
    c[j] = 1;
    for (k = i + 1; k <= j - 1; k++) {
      if (a[k] >= 0) {
        t--;
        s += a[k];
        c[k] = 1;
      }
    }
    if (s > maxs) {
      top = t;
      maxs = s;
      for (k = 1; k <= n; k++) cut[k] = c[k];
    }
  }
  j = 1;
  cout << maxs << ' ' << top << endl;
  while (cut[j] != 0) j++;
  if (j > n) return 0;
  cout << j;
  for (i = j + 1; i <= n; i++)
    if (cut[i] == 0) cout << ' ' << i;
  return 0;
}