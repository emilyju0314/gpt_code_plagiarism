#include <bits/stdc++.h>
using namespace std;
char _buf[100000], *_p1 = _buf, *_p2 = _buf;
inline int gi() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return (f == 1) ? x : -x;
}
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
const int maxn = 1005;
int T, a[maxn], n;
set<int> s;
inline void init() { s.clear(); }
inline void input() { n = gi(); }
inline void solve() {
  bool ok = 0;
  for (int i = 1; i <= n; ++i) {
    a[i] = gi();
    if (s.count(a[i])) ok = 1;
    s.insert(a[i]);
  }
  if (ok) {
    printf("YES\n");
    return;
  } else
    printf("NO\n");
}
int main() {
  T = gi();
  while (T--) {
    init();
    input();
    solve();
  }
  return 0;
}
