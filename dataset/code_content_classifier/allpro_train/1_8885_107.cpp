#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, t, c;
  cin >> n >> k >> t;
  if (t <= k) {
    cout << t;
  } else if ((t > k) && (t <= n)) {
    cout << k;
  } else {
    cout << (k - (t - n));
  }
  return 0;
}
