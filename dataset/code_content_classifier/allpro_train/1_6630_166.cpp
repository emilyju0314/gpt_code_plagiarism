#include <bits/stdc++.h>
using namespace std;
long long n, t, u = 240, v = 0, li[15], l, r;
int main() {
  cin >> n >> t;
  u -= t;
  l = 0;
  r = n;
  for (int i = 1; i < n + 1; i++) {
    li[i] = i * 5 + li[i - 1];
  }
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (li[m] > u)
      r = m;
    else if (li[m] < u)
      l = m;
    else {
      cout << m;
      return 0;
    }
  }
  if (li[r] <= u) {
    cout << r;
  } else
    cout << l;
}
