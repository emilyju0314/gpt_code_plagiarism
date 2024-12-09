#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &x, T y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
inline bool chkmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline void read(T &x) {
  char ch = getchar();
  int f = 1;
  x = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
template <typename T, typename... Args>
inline void read(T &x, Args &...args) {
  read(x), read(args...);
}
int n, st[200050], tp, a[200050];
int b[200050], cnt;
pair<int, int> op[200050];
set<int> se;
int main() {
  read(n);
  char s[10];
  int c;
  for (register int i = 1; i <= 2 * n; ++i) {
    scanf("%s", s);
    if (s[0] == '+')
      st[++tp] = i;
    else {
      read(b[++cnt]);
      if (!tp) return cout << "NO\n", 0;
      op[st[tp--]] = make_pair(1, b[cnt]);
      op[i] = make_pair(2, b[cnt]);
    }
  }
  for (register int i = 1; i <= 2 * n; ++i) {
    if (op[i].first == 1)
      se.insert(op[i].second);
    else {
      c = *se.begin(), se.erase(se.begin());
      if (c != op[i].second) return cout << "NO\n", 0;
    }
  }
  cout << "YES\n";
  for (register int i = 1; i <= 2 * n; ++i)
    if (op[i].first == 1) cout << op[i].second << ' ';
  return 0;
}
