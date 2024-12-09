#include <bits/stdc++.h>
using namespace std;
int dx[] = {+1, -1, +0, +0};
int dy[] = {+0, +0, +1, -1};
int KingX[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int KingY[] = {-1, +1, +0, +0, +1, +1, -1, -1};
int KnightX[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int KnightY[] = {-1, 1, -2, 2, -2, 2, -1, 1};
template <class T>
inline T bigmod(T b, T p, T M) {
  T ret = 1;
  for (; p > 0; p >>= 1) {
    if (p & 1) ret = (ret * b) % M;
    b = (b * b) % M;
  }
  return (T)ret;
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  return a * b / gcd<T>(a, b);
}
template <class T>
inline T power(T b, T p) {
  unsigned long long int x = 1;
  while (p--) x *= b;
  return x;
}
const long long int mod = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int x, y, n;
    cin >> x >> y >> n;
    long long int d = n / x;
    long long int ans = d * x + y;
    if (ans <= n)
      cout << ans << endl;
    else
      cout << ans - x << endl;
  }
  return 0;
}
