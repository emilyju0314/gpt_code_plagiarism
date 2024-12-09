#include <bits/stdc++.h>
using namespace std;
int n, k, x, d[1111111], l[1111111], r[1111111];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    r[i] = min(i + k, n);
    l[i] = max(i - k, 1);
    if (x == 0) {
      d[i] = r[i] - l[i] + 1;
    } else {
      if (r[x] >= l[i]) {
        d[i] = d[x] + (r[i] - l[i] + 1) - (r[x] - l[i] + 1);
      } else {
        d[i] = d[x] + r[i] - l[i] + 1;
      }
    }
    cout << d[i] << ' ';
  }
}
