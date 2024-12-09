#include <bits/stdc++.h>
template <typename C>
int sz(const C &c) {
  return c.size();
}
using namespace std;
int main() {
  iostream::sync_with_stdio(false);
  int tests;
  cin >> tests;
  for (int test = 0; test < tests; ++test) {
    int64_t n;
    cin >> n;
    int64_t k;
    cin >> k;
    int64_t r = 0;
    while (n != 0) {
      int64_t t = n % k;
      if (t == 0) {
        ++r;
        n /= k;
      } else {
        r += t;
        n -= t;
      }
    }
    cout << r << "\n";
  }
}
