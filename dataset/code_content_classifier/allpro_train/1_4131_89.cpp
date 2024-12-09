#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j, k, l, r, mid, s;
  cin >> n;
  l = 1;
  r = n;
  while (l != r) {
    mid = (l + r) / 2;
    k = n;
    s = 0;
    while (k > 0) {
      s += min(mid, k);
      k -= min(mid, k);
      k -= (k / 10);
    }
    if (s >= (n + 1) / 2)
      r = mid;
    else
      l = mid + 1;
  }
  cout << l;
}
