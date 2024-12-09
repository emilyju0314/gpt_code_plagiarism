#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-O2")
template <typename tp>
void in(tp &dig) {
  char ch = getchar();
  dig = 0;
  long long flag = 0;
  while (!isdigit(ch)) {
    if (ch == '-') flag = 1;
    ch = getchar();
  }
  while (isdigit(ch)) dig = dig * 10 + ch - '0', ch = getchar();
  if (flag) dig = -dig;
}
template <typename T>
void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
void chkmin(T &x, T y) {
  x = min(x, y);
}
const int LIM = 5e5 + 5, MOD = 1e9 + 7;
long long n, m, t, x, y, z, l, r, last = 0;
map<int, int> mem;
int cnt = 1;
void in(int i) {
  for (int j = 0; j < i; j++) cout << "   ";
}
int xr[LIM] = {0}, par[LIM];
int getpar(int u) {
  if (par[u] == u) return u;
  z = getpar(par[u]);
  xr[u] = xr[par[u]] ^ xr[u];
  return (par[u] = z);
}
void dbgxr() {
  for (auto &i : mem) {
    in(2);
    cout << i.second << "  " << xr[i.second] << " " << par[i.second] << "      "
         << i.first << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  for (int i = 0; i < LIM; i++) par[i] = i;
  for (int i = 0; i < q; i++) {
    cin >> t >> x >> y;
    x = x ^ last;
    y = y ^ last;
    if (x > y) swap(x, y);
    y++;
    if (mem.count(x) == 0) mem[x] = cnt, cnt++;
    if (mem.count(y) == 0) mem[y] = cnt, cnt++;
    x = mem[x];
    y = mem[y];
    l = getpar(x);
    r = getpar(y);
    if (t == 1) {
      cin >> m;
      m ^= last;
      if (l == r) continue;
      par[r] = l;
      m = m ^ xr[x] ^ xr[y];
      xr[r] = m;
    } else {
      if (l != r) {
        last = 1;
        cout << -1 << "\n";
        continue;
      }
      cout << (xr[x] ^ xr[y]) << "\n";
      last = (xr[x] ^ xr[y]);
    }
  }
  return 0;
}
