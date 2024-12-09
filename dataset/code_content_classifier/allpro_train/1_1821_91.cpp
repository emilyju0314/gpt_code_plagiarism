#include <bits/stdc++.h>
using namespace std;
unsigned n, a, b, c, d;
unsigned ans;
bitset<100000001> bit;
unsigned f(unsigned x) { return a * x * x * x + b * x * x + c * x + d; }
unsigned Get(unsigned x) {
  unsigned ret = f(x);
  unsigned tmp = 0;
  for (unsigned i = 1; i <= n / x; i *= x) {
    tmp += n / (i * x);
  }
  return ret * tmp;
}
int main() {
  ios::sync_with_stdio(false);
  while (cin >> n >> a >> b >> c >> d) {
    ans = Get(2) + Get(3);
    bit.reset();
    for (unsigned i = 5; i <= n; ++i) {
      if (i % 2 == 0 || i % 3 == 0) continue;
      if (bit[i / 3] == 0) {
        ans += Get(i);
        for (unsigned j = 2 * i; j <= n; j += i) {
          if (j % 2 == 0 || j % 3 == 0) continue;
          bit[j / 3] = 1;
        }
      }
    }
    cout << ans << endl;
  }
}
