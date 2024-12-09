#include <bits/stdc++.h>
using namespace std;
long long t, n;
int main(void) {
  cin >> t;
  for (; t; --t) {
    cin >> n;
    long long sol = 0;
    for (int i = 1; i <= 9; ++i) {
      long long x = i;
      while (x <= n) {
        ++sol;
        x = x * (long long)10 + (long long)i;
      }
    }
    cout << sol << "\n";
  }
  return 0;
}
