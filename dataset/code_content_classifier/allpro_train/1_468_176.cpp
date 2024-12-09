#include <bits/stdc++.h>
using namespace std;
int a[2111111];
int main() {
  int n, x, y, ans, A;
  cin >> n >> x >> y;
  int cnt = 0;
  long long cntx = 0, cnty = 0;
  a[0] = 0;
  while (cntx < x || cnty < y) {
    if ((cntx + 1) * y < (cnty + 1) * x) {
      cnt++;
      cntx++;
      a[cnt] = 1;
    } else if ((cntx + 1) * y > (cnty + 1) * x) {
      cnt++;
      cnty++;
      a[cnt] = 2;
    } else {
      cnt++;
      cntx++;
      a[cnt] = 0;
      cnt++;
      cnty++;
      a[cnt] = 0;
    }
  }
  while (n--) {
    cin >> A;
    A %= (x + y);
    ans = a[A];
    if (ans == 0)
      puts("Both");
    else if (ans == 1)
      puts("Vanya");
    else
      puts("Vova");
  }
  return 0;
}
