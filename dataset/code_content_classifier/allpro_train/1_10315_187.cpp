#include <bits/stdc++.h>
using namespace std;
int n, m, r, i, a[103], b[103], maxx = -1, minn = 999999, poz, poz1, sol;
int main() {
  cin >> n >> m >> r;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (i = 1; i <= m; i++) {
    cin >> b[i];
  }
  for (i = 1; i <= n; i++) {
    if (a[i] < minn) {
      minn = a[i];
      poz = i;
    }
  }
  for (i = 1; i <= m; i++) {
    if (b[i] > maxx) {
      maxx = b[i];
      poz1 = i;
    }
  }
  if (maxx <= minn) {
    cout << r;
  } else {
    sol = r / minn;
    sol = sol * maxx + r % minn;
    cout << sol;
  }
  return 0;
}
