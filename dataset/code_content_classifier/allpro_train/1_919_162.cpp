#include <bits/stdc++.h>
using namespace std;
const int MaxExp = 50;
map<int, bool> M1, M2;
long long b1, q, l, m, biggestExp, ans;
int main() {
  cin >> b1 >> q >> l >> m;
  for (int i = 1; i <= m; ++i) {
    int val;
    cin >> val;
    M1[val] = true;
  }
  int exp = 0;
  for (long long pow = 1; exp < 50 and abs(b1 * pow) <= l; ++exp, pow *= q) {
    long long nr = b1 * pow;
    if (M1[nr] == false) {
      ++ans;
    }
  }
  if (b1 != 0 and q == 0 and M1[0]) {
    if (M1[b1]) {
      cout << 0 << '\n';
    } else {
      cout << min(ans, 1LL) << '\n';
    }
    return 0;
  }
  if (exp == 50 and ans) {
    cout << "inf\n";
  } else {
    cout << ans << '\n';
  }
  return 0;
}
