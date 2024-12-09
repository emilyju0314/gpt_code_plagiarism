#include <bits/stdc++.h>
using namespace std;
void solve2() {
  long long n, a, b;
  string s, t;
  cin >> n >> a >> b >> s >> t;
  long long d1 = (s[0] != 'l');
  long long d2 = (t[0] != 'l');
  if (a == 0 && d1 == 1) {
    d1 = 0;
  }
  if (b == 0 && d2 == 1) {
    d2 = 0;
  }
  if (a == n - 1 && d1 == 0) {
    d1 = 1;
  }
  if (b == n - 1 && d2 == 0) {
    d2 = 1;
  }
  if (a == b && d1 == d2) {
    if (d1 == 0) {
      cout << n - 1;
    } else {
      cout << 0;
    }
    cout << '\n';
    return;
  }
  if (abs(a - b) % 2 != (a < b)) {
    cout << n - 1;
  } else {
    cout << 0;
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  mt19937 rnd(239);
  long long t;
  cin >> t;
  while (t--) {
    solve2();
  }
  return 0;
}
