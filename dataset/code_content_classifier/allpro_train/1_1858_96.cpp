#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int i = 0;
  int x = a;
  while (x) {
    i = max(i, x % 10);
    x /= 10;
  }
  x = b;
  while (x) {
    i = max(i, x % 10);
    x /= 10;
  }
  ++i;
  int c = a + b;
  int ans = 0;
  for (int k = i; k < 3000; ++k) {
    int new_a = 0;
    int new_b = 0;
    int x = a;
    int deg = 1;
    while (x) {
      new_a += (x % 10) * deg;
      deg *= k;
      x /= 10;
    }
    x = b;
    deg = 1;
    while (x) {
      new_b += (x % 10) * deg;
      deg *= k;
      x /= 10;
    }
    int new_c = new_a + new_b;
    int cur = 0;
    while (new_c > 0) {
      new_c /= k;
      ++cur;
    }
    ans = max(ans, cur);
  }
  cout << ans << endl;
  return 0;
}
