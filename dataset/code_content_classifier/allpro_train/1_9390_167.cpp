#include <bits/stdc++.h>
using namespace std;
int a[10000001], n, d = 100000007, i, k, ans = -1;
void inp() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (i = 1; i < n; i++) d = min(d, a[i + 1] - a[i]);
  for (i = 1; i < n; i++) {
    if (a[i + 1] - a[i] > d) {
      k++;
      if (a[i + 1] - a[i] == 2 * d) ans = a[i] + d;
    }
  }
  if (n == 1)
    cout << -1;
  else if (k > 1)
    cout << 0;
  else if (k == 1) {
    if (ans == -1)
      cout << 0;
    else
      cout << 1 << endl << ans;
  } else {
    if (d == 0)
      cout << 1 << endl << a[1];
    else if (n == 2 && (a[2] - a[1]) % 2 == 0)
      cout << 3 << endl
           << a[1] - d << " " << a[1] + (a[2] - a[1]) / 2 << " " << a[n] + d;
    else
      cout << 2 << endl << a[1] - d << " " << a[n] + d;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  for (long long int i = 0; i < T; i++) {
    inp();
  }
  return 0;
}
