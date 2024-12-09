#include <bits/stdc++.h>
using namespace std;
int prost(int n) {
  int res = 1e9;
  for (int i = 2; i <= n / i;) {
    if (n % i == 0) {
      res = max(res, i);
      if (res == 1e9) {
        res = i;
      }
      n /= i;
    } else {
      i++;
    }
  }
  return n;
}
int main() {
  ios::sync_with_stdio(false);
  int x2;
  cin >> x2;
  int res = 1e9;
  int x = prost(x2);
  for (int i = 1; i < x; i++) {
    int x1 = x2 - i;
    int xx = prost(x1);
    if (x1 == xx) {
      res = min(res, x1);
    } else {
      res = min(res, x1 - xx + 1);
    }
  }
  cout << res;
  return 0;
}
