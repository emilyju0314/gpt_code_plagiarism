#include <bits/stdc++.h>
using namespace std;
const char lf = '\n';
template <typename T1, typename T2>
inline T1 max(T1 a, T2 b) {
  return a < b ? b : a;
}
template <typename T1, typename T2>
inline T1 min(T1 a, T2 b) {
  return a < b ? a : b;
}
template <typename T1, typename T2>
inline T1 gmax(T1 &a, T2 b) {
  return a = a < b ? b : a;
}
template <typename T1, typename T2>
inline T1 gmin(T1 &a, T2 b) {
  return a = a < b ? a : b;
}
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
  int a = 0, b = 1, c = fetch();
  while (!isdigit(c)) b ^= c == '-', c = fetch();
  while (isdigit(c)) a = a * 10 + (c - 48), c = fetch();
  return b ? a : -a;
}
}  // namespace ae86
using ae86::ty;
const int _ = 53, __ = _ << 1, mo = 1000000007;
template <typename T1, typename T2>
inline T1 ad(T1 &a, T2 b) {
  return a = a + b >= mo ? a + b - mo : a + b;
}
template <typename T1, typename T2>
inline T1 dl(T1 &a, T2 b) {
  return a = a >= b ? a - b : a - b + mo;
}
template <typename T1, typename T2>
inline T1 add(T1 a, T2 b) {
  return a + b >= mo ? a + b - mo : a + b;
}
template <typename T1, typename T2>
inline T1 del(T1 a, T2 b) {
  return a >= b ? a - b : a - b + mo;
}
int n, nn, m, e[_][_] = {0};
vector<int> hav[_][_];
int pusheen(deque<int> &q, deque<int>::iterator x, int dir) {
  int got = 1;
  if (dir < 0) {
    while (x != q.begin() && ((int)((q).size())) <= nn) {
      auto pre = prev(x);
      got &= e[*pre][*x],
          q.insert(q.begin(), hav[*pre][*x].begin(), hav[*pre][*x].end());
      x = pre;
    }
  } else {
    while (next(x) != q.end() && ((int)((q).size())) <= nn) {
      auto nex = next(x);
      got &= e[*x][*nex],
          q.insert(q.end(), hav[*x][*nex].begin(), hav[*x][*nex].end());
      x = nex;
    }
  }
  if (((int)((q).size())) > nn) got = 0;
  return got;
}
long long f[2][_][__] = {0};
vector<int> trans[2][2][_][_];
int main() {
  ios::sync_with_stdio(0), cout.tie(nullptr);
  n = ty(), m = ty(), nn = n + n;
  for (int i = 1, a, b; i <= m; i++) {
    a = ty(), b = ty(), e[a][b] = 1, hav[a][b].resize(ty());
    for (auto &j : hav[a][b]) j = ty();
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (!hav[i][j].empty() && hav[i][j].back() == i) {
        deque<int> temp(hav[i][j].begin(), hav[i][j].end());
        if (pusheen(temp, prev(temp.end()), -1))
          trans[0][0][temp.front()][j].emplace_back(((int)((temp).size())));
      }
  int got = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      auto x = hav[i][j].end();
      for (auto ps = hav[i][j].begin(); ps != hav[i][j].end(); ps++) {
        if (next(ps) == hav[i][j].end()) break;
        if (*ps == i && *next(ps) == j) {
          x = ps;
          break;
        }
      }
      if (x == hav[i][j].end()) continue;
      if (next(x) == hav[i][j].end()) continue;
      deque<int> temp(hav[i][j].begin(), hav[i][j].end());
      auto a = temp.begin() + (x - hav[i][j].begin());
      if (pusheen(temp, a, -1) && pusheen(temp, a + 1, 1)) {
        trans[0][1][temp.front()][temp.back()].emplace_back(
            ((int)((temp).size())) - 1);
        if (!got) {
          got = 1, cout << ((int)((temp).size())) << lf;
          for (auto p : temp) cout << p << ' ';
          cout << lf;
        }
      }
    }
  if (!got) cout << 0 << lf << lf;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (e[i][j] && hav[i][j].empty()) trans[1][0][i][j].emplace_back(1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (!hav[i][j].empty() && hav[i][j].front() == j) {
        deque<int> temp(hav[i][j].begin(), hav[i][j].end());
        if (pusheen(temp, temp.begin(), 1))
          trans[1][1][i][temp.back()].emplace_back(((int)((temp).size())));
      }
  for (int i = 1; i <= n; i++) f[0][i][0] = 1;
  for (int len = 0; len < nn; len++) {
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= n; j++) {
        if (!f[i][j][len]) continue;
        for (int a = 0; a < 2; a++)
          for (int b = 1; b <= n; b++)
            for (auto x : trans[i][a][j][b])
              if (x + len <= nn) ad(f[a][b][x + len], f[i][j][len]);
      }
  }
  for (int i = 1; i <= nn; i++) {
    long long ans = 0;
    for (int j = 1; j <= n; j++) ad(ans, f[1][j][i]);
  }
  return 0;
}
