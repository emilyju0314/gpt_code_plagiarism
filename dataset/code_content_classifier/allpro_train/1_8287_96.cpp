#include <bits/stdc++.h>
using namespace std;
long long a[100000 + 100], b[100000 + 100];
int main() {
  long long ans = 0, n, x, y;
  x = 0, y = 0;
  long long m;
  scanf("%I64d %I64d", &n, &m);
  for (long long ii = 1; ii <= n; ii++) scanf("%I64d", &a[ii]);
  for (long long ii = 1; ii <= m; ii++) scanf("%I64d", &b[ii]);
  long long i = 1, j = 1;
  while (i <= n || j <= m) {
    if (x == 0 && i <= n) x += a[i++];
    if (y == 0 && j <= m) y += b[j++];
    if (x == y && x != 0) ans++, x = y = 0;
    if (i <= n && x < y) x += a[i++];
    if (j <= m && y < x) y += b[j++];
  }
  if (x == y && x != 0) ans++;
  cout << ans << endl;
  return 0;
}
