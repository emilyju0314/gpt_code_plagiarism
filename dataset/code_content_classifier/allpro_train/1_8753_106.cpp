#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e+5;
int main() {
  int n, x, sum;
  cin >> n >> x;
  int pre = 0;
  if (x >= (1 << n)) {
    sum = (1 << n) - 1;
    cout << sum << endl;
    for (int i = 0; i < (1 << n) - 1; i++) {
      if (i) cout << " ";
      cout << (i ^ (i + 1));
    }
    cout << endl;
    return 0;
  } else {
    sum = (1 << (n - 1)) - 1;
    cout << sum << endl;
    int start = 0;
    int ans;
    int pre = 0;
    while (1) {
      pre++;
      if ((x >> pre) <= 0) break;
    }
    for (int i = 0; i < (1 << n) - 1 && start < sum; i++) {
      ans = i ^ (i + 1);
      if (ans < (1 << pre) && ans >= (1 << (pre - 1))) {
        if (start) cout << " ";
        cout << (ans << 1) + 1;
        start++;
        continue;
      }
      if (start) cout << " ";
      start++;
      if (ans > x)
        cout << (ans << 1) + 1;
      else
        cout << ans;
    }
  }
  return 0;
}
