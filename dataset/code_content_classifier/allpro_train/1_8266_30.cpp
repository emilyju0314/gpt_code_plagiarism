#include <bits/stdc++.h>
using namespace std;
long long n, m, a[100010], b[100010], aa, bb, ans, fans;
int main() {
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    aa += a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    bb += b[i];
  }
  sort(b, b + n);
  int i = 0;
  while (i < n - 1) {
    if (b[i] <= aa) {
      ans += b[i];
    } else
      ans += aa;
    i++;
  }
  ans += aa;
  fans = ans;
  sort(a, a + m);
  i = 0;
  ans = 0;
  while (i < m - 1) {
    if (a[i] <= bb) {
      ans += a[i];
    } else
      ans += bb;
    i++;
  }
  ans += bb;
  fans = min(fans, ans);
  cout << fans << endl;
}
