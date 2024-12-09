#include <bits/stdc++.h>
#pragma comment(linker, "/stack:64000000")
using namespace std;
template <typename X>
inline X abs(const X& a) {
  return a < 0 ? -a : a;
}
template <typename X>
inline X sqr(const X& a) {
  return a * a;
}
const int INF = INT_MAX / 2;
const long double EPS = 1e-9;
const long double PI = 3.1415926535897932384626433832795;
int n;
inline bool read() { return (scanf("%d", &n) == 1); }
const int LEN = 10;
char buf[LEN];
inline void solve() {
  long long a = 1, b = 1;
  for (int i = 0; i < int(n); i++) {
    assert(scanf("%s", buf) == 1);
    string s = string(buf);
    if (s == "ULDR") {
      a++, b++;
    } else if (s == "UR") {
      a++;
    } else if (s == "UL") {
      b++;
    } else if (s == "DL") {
      a++;
    } else if (s == "DR") {
      b++;
    } else
      throw;
  }
  long long ans = a * b;
  cout << ans << endl;
}
int main() {
  assert(read());
  solve();
  return 0;
}
