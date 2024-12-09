#include <bits/stdc++.h>
const long long mod = (long long)1e9 + 7;
const int maxn = (int)1e5 + 1;
long long inf = 1LL << 60;
using namespace std;
inline void read(int &n) {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = 10 * x + ch - '0';
    ch = getchar();
  }
  n = x * f;
}
inline void read(long long &n) {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = 10ll * x + ch - '0';
    ch = getchar();
  }
  n = x * f;
}
inline long long comp(long long x) { return (x + 1) * (x + 2) / 2; }
int main() {
  ios_base::sync_with_stdio(0);
  long long a, b, c, l;
  cin >> a >> b >> c >> l;
  long long ans = (l + 1) * (l + 2) * (l + 3) / 6;
  for (int i = 0; i < l + 1; i++) {
    if (a + i >= b + c) ans -= comp(min(a + i - b - c, l - i));
    if (b + i >= a + c) ans -= comp(min(b + i - a - c, l - i));
    if (c + i >= a + b) ans -= comp(min(c + i - a - b, l - i));
  }
  cout << ans;
  return 0;
}
