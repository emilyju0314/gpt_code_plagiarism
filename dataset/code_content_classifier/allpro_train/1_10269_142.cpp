#include <bits/stdc++.h>
using namespace std;
const long long Inf = 4e18;
const int maxn = 100005;
inline long long gl() {
  char c = getchar();
  bool f = 1;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') c = getchar(), f = 0;
  long long sum = 0;
  while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
  return f ? sum : -sum;
}
int n;
long long x[maxn], y[maxn], z[maxn];
long long ansx, ansy, ansz;
inline void chkmin(long long &a, long long b) {
  if (a > b) a = b;
}
inline void chkmax(long long &a, long long b) {
  if (a < b) a = b;
}
bool check(long long d) {
  long long mx, mxx, mxy, mxz, mn, mnx, mny, mnz;
  mx = mxx = mxy = mxz = Inf, mn = mnx = mny = mnz = -Inf;
  for (int i = 1; i <= n; i++)
    chkmin(mx, d + x[i] + y[i] + z[i]), chkmin(mxx, d - x[i] + y[i] + z[i]),
        chkmin(mxy, d + x[i] - y[i] + z[i]),
        chkmin(mxz, d + x[i] + y[i] - z[i]),
        chkmax(mn, -d + x[i] + y[i] + z[i]),
        chkmax(mnx, -d - x[i] + y[i] + z[i]),
        chkmax(mny, -d + x[i] - y[i] + z[i]),
        chkmax(mnz, -d + x[i] + y[i] - z[i]);
  for (int i = 0; i < 2; i++) {
    long long l = mn + ((mn & 1) ^ i), r = mx - ((mx & 1) ^ i);
    long long lx = mnx + ((mnx & 1) ^ i), rx = mxx - ((mxx & 1) ^ i);
    long long ly = mny + ((mny & 1) ^ i), ry = mxy - ((mxy & 1) ^ i);
    long long lz = mnz + ((mnz & 1) ^ i), rz = mxz - ((mxz & 1) ^ i);
    if (l > r || lx > rx || ly > ry || lz > rz) continue;
    long long a = lx, b = ly, c = lz;
    if (a + b + c > r) continue;
    if (a + b + c < l) a = rx < l - b - c ? rx : l - b - c;
    if (a + b + c < l) b = ry < l - a - c ? ry : l - a - c;
    if (a + b + c < l) c = rz < l - a - b ? rz : l - a - b;
    if (a + b + c < l) continue;
    return ansx = (b + c) >> 1, ansy = (a + c) >> 1, ansz = (a + b) >> 1, 1;
  }
  return 0;
}
int main() {
  int T = gl();
  while (T--) {
    n = gl();
    for (int i = 1; i <= n; ++i) x[i] = gl(), y[i] = gl(), z[i] = gl();
    long long l = 0, r = Inf, mid;
    while (l < r) {
      mid = (l + r) >> 1;
      if (check(mid))
        r = mid;
      else
        l = mid + 1;
    }
    printf("%lld %lld %lld\n", ansx, ansy, ansz);
  }
  return 0;
}
