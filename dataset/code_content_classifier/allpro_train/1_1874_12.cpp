#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline T1 max(T1 a, T2 b) {
  return a < b ? b : a;
}
template <typename T1, typename T2>
inline T1 min(T1 a, T2 b) {
  return a < b ? a : b;
}
const char lf = '\n';
namespace ae86 {
const int bufl = 1 << 15;
char buf[bufl], *s = buf, *t = buf;
inline int fetch() {
  if (s == t) {
    t = (s = buf) + fread(buf, 1, bufl, stdin);
    if (s == t) return EOF;
  }
  return *s++;
}
inline int ty() {
  int a = 0;
  int b = 1, c = fetch();
  while (!isdigit(c)) b ^= c == '-', c = fetch();
  while (isdigit(c)) a = a * 10 + c - 48, c = fetch();
  return b ? a : -a;
}
}  // namespace ae86
using ae86::ty;
const int _ = 207, __ = 30007;
inline void failure() {
  cout << -1 << lf;
  exit(0);
}
int n, m, loc[_] = {0}, dis[_][__] = {0}, ps[_][__] = {0}, ed[__] = {0},
          las[__] = {0};
vector<pair<int, int>> has[__];
int main() {
  ios::sync_with_stdio(0), cout.tie(nullptr);
  n = ty(), m = ty();
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      dis[i][j] = ty();
      if (!dis[i][j]) loc[i] = j;
    }
    if (!loc[i]) failure();
  }
  for (int i = 2; i <= m; i++) {
    for (int j = 1; j <= n; j++)
      if (dis[1][j] + dis[i][j] == dis[1][loc[i]])
        ps[i][dis[1][j]] = j, ed[j] = 1;
    for (int j = dis[1][loc[i]]; j >= 1; j--) {
      if (!ps[i][j]) failure();
      las[ps[i][j]] = ps[i][j - 1];
    }
  }
  ed[loc[1]] = 1;
  for (int i = 1; i <= n; i++) {
    if (ed[i]) continue;
    int mx = 0, mxloc = loc[1];
    for (int j = 2; j <= m; j++) {
      int a = (dis[1][loc[j]] + dis[1][i] - dis[j][i]) >> 1;
      if (a >= mx) mx = a, mxloc = ps[j][a];
    }
    has[mxloc].emplace_back(dis[1][i], i);
  }
  for (int j = 1; j <= n; j++) {
    sort(has[j].begin(), has[j].end());
    for (int i = 0, pre = dis[1][j], now = j; i < ((int)((has[j]).size()));) {
      pre++;
      if (pre != has[j][i].first) failure();
      while (i < ((int)((has[j]).size())) - 1 && has[j][i + 1].first == pre)
        las[has[j][i].second] = now, i++;
      las[has[j][i].second] = now, now = has[j][i].second, i++;
    }
  }
  for (int i = 1; i <= n; i++)
    if (las[i]) cout << las[i] << ' ' << i << lf;
  return 0;
}
