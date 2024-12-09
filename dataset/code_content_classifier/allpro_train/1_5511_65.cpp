#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, k, x, val;
  long long int res = 0;
  cin >> n >> k >> x;
  for (i = 0; i < (n - k); i++) {
    cin >> val;
    res += val;
  }
  for (i = 0; i < k; i++) {
    cin >> val;
    if (val > x) {
      res += x;
    } else {
      res += val;
    }
  }
  cout << res << "\n";
  return 0;
}
