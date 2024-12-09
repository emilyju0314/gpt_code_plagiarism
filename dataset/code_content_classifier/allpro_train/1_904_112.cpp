#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, y;
  cin >> n >> x >> m >> y;
  if (n > m) swap(m, n);
  x = abs(x - y);
  long long tot = 1 + m - min(m, max(0, n - x)) + n - min(n, max(0, m - x));
  for (register int i = (1); i < (int)(n + 1); ++i) {
    if (i <= x - m) continue;
    if (i == 1) {
      tot += 2;
      if (x - m > -1) tot--;
      continue;
    }
    int mn = i <= x ? x - i + 1 : i - x;
    int mx = min(m, max(x + i, i - x));
    int amt = 2 * (mx - mn + 1) - 1;
    if (x - m <= -i) amt--;
    if (x == x + 1) amt--;
    tot += amt;
  }
  cout << tot << endl;
  return 0;
}
