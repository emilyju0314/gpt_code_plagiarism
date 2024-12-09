#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long a, b, c, p, q, r;
  cin >> a >> b >> c;
  p = ((a - c + b) / 2);
  q = ((a + c - b) / 2);
  r = ((b + c - a) / 2);
  if (p >= 0 && q >= 0 && r >= 0) {
    if ((p + q) == a && (q + r) == c && (p + r) == b) {
      cout << p << " " << r << " " << q;
    } else {
      cout << "Impossible";
    }
  } else if (p < 0 || q < 0 || r < 0) {
    cout << "Impossible";
  }
  return 0;
}
