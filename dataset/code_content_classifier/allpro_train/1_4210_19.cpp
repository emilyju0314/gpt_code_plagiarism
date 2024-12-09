#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], b[N], c[N], d[N];
int main() {
  int n, m, ans = 0, minb, maxc, mind, maxa;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cin >> b[i];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> c[i];
    cin >> d[i];
  }
  minb = *min_element(b, b + n);
  maxc = *max_element(c, c + m);
  mind = *min_element(d, d + m);
  maxa = *max_element(a, a + n);
  ans = max(maxc - minb, maxa - mind);
  if (ans > 0)
    cout << ans << endl;
  else
    cout << 0 << endl;
  return 0;
}
