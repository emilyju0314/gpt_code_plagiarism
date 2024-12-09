#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, l, r, t, c;
  cin >> n >> m;
  vector<int> mass(n, 10000), res(n, 0);
  for (int i = 0; i < m; i++) {
    cin >> l >> r >> t >> c;
    for (int i = l - 1; i < r; i++)
      if (mass[i] > t) {
        mass[i] = t;
        res[i] = c;
      }
  }
  int res1 = 0;
  for (int i = 0; i < n; i++) res1 += res[i];
  cout << res1;
  return 0;
}
