#include <bits/stdc++.h>
using namespace std;
int ans, x;
int l[111111], r[111111];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    x += abs(r[i] - l[i]) + 1;
  }
  r[0] = -100000;
  l[n + 1] = 100000;
  while (x % k != 0) {
    x++;
    ans++;
  }
  cout << ans;
  return 0;
  return 0;
}
