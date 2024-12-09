#include <bits/stdc++.h>
int x[2010], y[2010];
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) x[i] = 0, y[i] = i;
  int c = 0, tot = 0;
  int d = (1 << 29);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      tot++;
      int t = (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]);
      if ((x[j] - x[i]) * (x[j] - x[i]) >= d) break;
      if (d > t) d = t;
    }
  }
  if (tot <= k)
    cout << "no solution" << endl;
  else
    for (int i = 0; i < n; ++i) cout << x[i] << " " << y[i] << endl;
  return 0;
}
