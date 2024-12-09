#include <bits/stdc++.h>
using namespace std;
int n, ans;
long long a, b, t, x[500010], y[500010];
char s[500010];
int main() {
  cin >> n >> a >> b >> t;
  scanf("%s", s + 1);
  for (register int i = 1; i <= n; i++)
    if (s[i] == 'w')
      x[i] = b + 1;
    else
      x[i] = 1;
  for (register int i = n; i; i--) y[i] = y[i + 1] + x[i];
  for (register int i = 1; i <= n; i++) x[i] += x[i - 1];
  for (register int i = 1; i <= n; i++) {
    int l = 1, r = n, mid, res = -1;
    if (t - x[i] - (i - 1) * a >= 0) ans = max(ans, i);
    while (l <= r) {
      mid = (l + r) >> 1;
      if (x[i] + y[mid] + (i + n - mid) * a + min(i - 1, n - mid + 1) * a <= t)
        r = mid - 1, res = mid;
      else
        l = mid + 1;
    }
    if (~res) ans = max(ans, n - res + 1 + i);
  }
  cout << min(ans, n) << endl;
  return 0;
}
