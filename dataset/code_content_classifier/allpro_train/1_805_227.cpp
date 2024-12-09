#include <bits/stdc++.h>
using namespace std;
const int N = 2020;
long long par[N], c[N];
long long getpar(int x) {
  if (x == par[x]) return x;
  return par[x] = getpar(par[x]);
}
bool mrg(int x, int y) {
  x = getpar(x);
  y = getpar(y);
  if (x == y) return 1;
  c[x] += c[y];
  par[y] = x;
  return 1;
}
int main() {
  int n, m, x;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    par[i] = i;
    c[i] = 1;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if (getpar(x) != getpar(y)) mrg(x, y);
  }
  cin >> x;
  for (int i = 0; i < x; i++) {
    int x, y;
    cin >> x >> y;
    x = getpar(x);
    y = getpar(y);
    if (getpar(x) == getpar(y)) c[x] = -1;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, c[getpar(i)]);
  cout << ans << endl;
  return 0;
}
