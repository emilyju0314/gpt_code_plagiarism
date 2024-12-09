#include <bits/stdc++.h>
using namespace std;
int n, d, d1;
long long k, kpre;
long long a[1001][1001] = {};
int main() {
  cin >> n >> k >> d;
  long long c = 1;
  d1 = d, kpre = k;
  for (int i = 0; i < d; i++) {
    c *= k;
    if (c >= n) {
      c = 0;
      break;
    }
  }
  if (c != 0) return cout << -1 << endl, 0;
  k = kpre;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < d; j++) a[i][j] = a[i - 1][j];
    for (int j = d - 1; j >= 0; j--) {
      a[i][j] = (a[i][j] + 1) % k;
      if (a[i][j]) break;
    }
  }
  for (int i = 0; i < d; i++) {
    for (int j = 1; j <= n; j++) cout << a[j][i] + 1 << " ";
    cout << endl;
  }
}
