#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
const long long mod = 1e9 + 7;
inline long long read() {
  long long p = 0;
  long long f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    p = p * 10 + ch - '0';
    ch = getchar();
  }
  return p * f;
}
long long qpow(long long x, long long k, long long mo) {
  long long s = 1;
  while (k) {
    if (k & 1) s = s * x % mo;
    x = x * x % mo;
    k >>= 1;
  }
  return s;
}
pair<long long, long long> a[N];
set<long long> bo[3][N];
set<long long>::iterator it;
long long nex[5] = {0, 2, 3, 4, 1};
int main() {
  long long n = read();
  long long m = read();
  long long k = read();
  long long u = 1, d = n + 1, l = 0, r = m + 1;
  for (long long i = 1; i <= k; i++) {
    a[i].first = read();
    a[i].second = read();
    bo[1][a[i].first].insert(a[i].second);
    bo[2][a[i].second].insert(a[i].first);
  }
  long long x = 1, y = 1, dir = 1;
  long long s = 1;
  bool fir = 1;
  while (1) {
    if (l > r || u > d) break;
    if (dir == 1) {
      it = bo[1][x].lower_bound(y);
      if (it != bo[1][x].end())
        r = min(r - 1, (*it) - 1);
      else
        r = r - 1;
      if (y > r) break;
      if (!fir && y == r) break;
      fir = 0;
      s += r - y;
      y = r;
      dir = nex[dir];
    } else if (dir == 2) {
      it = bo[2][y].lower_bound(x);
      if (it != bo[2][y].end())
        d = min(d - 1, (*it) - 1);
      else
        d = d - 1;
      if (x >= d) break;
      s += d - x;
      x = d;
      dir = nex[dir];
    } else if (dir == 3) {
      it = bo[1][x].lower_bound(y);
      if (it != bo[1][x].begin()) {
        --it;
        l = max(l + 1, (*it) + 1);
      } else
        l = l + 1;
      if (y <= l) break;
      s += y - l;
      y = l;
      dir = nex[dir];
    } else if (dir == 4) {
      it = bo[2][y].lower_bound(x);
      if (it != bo[2][y].begin()) {
        --it;
        u = max(u + 1, (*it) + 1);
      } else
        u = u + 1;
      if (x <= u) break;
      s += x - u;
      x = u;
      dir = nex[dir];
    }
  }
  if (s == n * m - k)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
