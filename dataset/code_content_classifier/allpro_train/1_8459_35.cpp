#include <bits/stdc++.h>
using namespace std;
bool pr[500005];
int prime[500005];
void seive() {
  int i, j, k;
  for (i = 4; i < 500005; i = i + 2) {
    pr[i] = true;
  }
  for (i = 3; i < 500005 / i; i = i + 2) {
    for (j = i * i; j < 500005; j = j + (2 * i)) {
      pr[j] = true;
    }
  }
  prime[0] = 2;
  k = 1;
  for (i = 3; i < 500005; i = i + 2) {
    if (pr[i] == false) {
      prime[k] = i;
      k++;
    }
  }
}
int main() {
  int t, i, j, k, n, fl, res, m, b, ans, x, q, y, co, p;
  int l, r, ab;
  cin >> p >> y;
  int fg = -1;
  for (i = y; i > p; i--) {
    m = i;
    fl = 0;
    for (j = 2; j <= p && j <= m / j; j++) {
      if (m % j == 0) {
        fl = 1;
        break;
      }
    }
    if (fl == 0) {
      fg = m;
      break;
    }
  }
  cout << fg << '\n';
}
