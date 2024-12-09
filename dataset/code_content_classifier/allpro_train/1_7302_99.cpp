#include <bits/stdc++.h>
using namespace std;
int main() {
  int mdisc = 1000000, x, m, discount[100004], n, price[100004], i, cost = 0, j,
      k;
  cin >> m;
  for (i = 0; i < m; i++) {
    cin >> discount[i];
    if (mdisc > discount[i]) mdisc = discount[i];
  }
  cin >> n;
  for (i = 0; i < n; i++) cin >> price[i];
  sort(price, price + n);
  while (n) {
    if (mdisc > n && n) {
      for (j = n - 1; j >= 0; j--) cost += price[j];
      n = 0;
    } else {
      x = n;
      for (j = n - 1; j >= n - mdisc; j--, x--) cost += price[j];
      n = x;
      for (k = j; k >= j - 1 && k >= 0; k--) n--;
    }
  }
  cout << cost;
  return 0;
}
