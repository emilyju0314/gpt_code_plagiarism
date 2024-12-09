#include <bits/stdc++.h>
using namespace std;
const int mxn = 5e2 + 10;
const int modl = 1e9 + 7;
long long nm, n, m, p, t, ans, q;
int wx[4] = {1, 0, 0, -1}, wy[4] = {0, 1, -1, 0};
int a[mxn][mxn];
char sc;
string s;
struct ss {
  int x, y;
};
struct cmp {
  bool operator()(ss aa, ss bb) { return a[aa.x][aa.y] < a[bb.x][bb.y]; }
};
long long getw(long long c) {
  long long l = 0, r = 1e5 + 1;
  while (r - l > 1) {
    long long mid = (l + r) / 2;
    if (((mid) * (mid) * (mid)) > c)
      r = mid;
    else
      l = mid;
  }
  return l;
}
void ww(long long c, long long w) {
  if (!c || !w) {
    if (p > ans) ans = p, q = t;
    return;
  }
  while (((c) * (c) * (c)) > w) c--;
  {
    p++, t += ((c) * (c) * (c));
    ww(c, w - ((c) * (c) * (c)));
    p--, t -= ((c) * (c) * (c));
  }
  if (c > 1) {
    p++, t += ((c - 1) * (c - 1) * (c - 1));
    ww(c - 1, min(w, ((c) * (c) * (c)) - 1) - ((c - 1) * (c - 1) * (c - 1)));
    p--, t -= ((c - 1) * (c - 1) * (c - 1));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> n) {
    ww(getw(n), n);
    cout << ans << " " << q;
  }
  return 0;
}
