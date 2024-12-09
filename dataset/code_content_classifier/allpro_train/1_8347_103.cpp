#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
template <class T>
T _max(T x, T y) {
  return x > y ? x : y;
}
template <class T>
T _min(T x, T y) {
  return x < y ? x : y;
}
template <class T>
T _abs(T x) {
  return (x < 0) ? -x : x;
}
template <class T>
T _mod(T x, T y) {
  return (x > 0) ? x % y : ((x % y) + y) % y;
}
template <class T>
void _swap(T& x, T& y) {
  T t = x;
  x = y;
  y = t;
}
template <class T>
void getmax(T& x, T y) {
  x = (y > x) ? y : x;
}
template <class T>
void getmin(T& x, T y) {
  x = (x < 0 || y < x) ? y : x;
}
int TS, cas = 1;
const int M = 100000 + 5;
int n, a[11];
int vis[11], cnt, tot;
struct ip {
  int a, b, c, d;
  ip(int _a = 0, int _b = 0, int _c = 0, int _d = 0) {
    a = _a, b = _b, c = _c, d = _d;
  }
  void show() { printf("%d.%d.%d.%d\n", a, b, c, d); }
  bool operator<(const ip& t) const {
    if (a != t.a) return a < t.a;
    if (b != t.b) return b < t.b;
    if (c != t.c) return c < t.c;
    return d < t.d;
  }
};
struct node {
  int a[22], len;
  void show() {
    for (int i = 1; i <= len; i++) printf("%d ", a[i]);
    puts("");
  }
} tmp;
vector<ip> ret;
vector<node> pal;
bool check(int& num, int len, int cur, int p) {
  num = 0;
  for (int i = 1; i <= len; i++) num *= 10, num += pal[p].a[cur++];
  if (num > 255 || (num != 0 && pal[p].a[cur - len] == 0)) return false;
  return true;
}
bool isOk(ip t, int len) {
  int cnt = 0;
  do {
    cnt++, t.a /= 10;
  } while (t.a);
  do {
    cnt++, t.b /= 10;
  } while (t.b);
  do {
    cnt++, t.c /= 10;
  } while (t.c);
  do {
    cnt++, t.d /= 10;
  } while (t.d);
  return cnt == len;
}
void addToRet(int p) {
  int i, j, k, l, cur;
  ip t;
  for (i = 1; i <= 3; i++)
    if (pal[p].len - i <= 9) {
      if (pal[p].len - i < 3 || pal[p].len < i + 3) break;
      if (!check(t.a, i, 1, p)) continue;
      for (j = 1; j <= 3; j++)
        if (pal[p].len - i - j <= 6) {
          if (pal[p].len - i - j < 2 || pal[p].len < i + j + 2) break;
          if (!check(t.b, j, i + 1, p)) continue;
          for (k = 1; k <= 3; k++)
            if (pal[p].len - i - j - k <= 3) {
              if (pal[p].len - i - j - k < 1 || pal[p].len < i + j + k + 1)
                break;
              if (!check(t.c, k, i + j + 1, p)) continue;
              l = pal[p].len - i - j - k;
              if (!check(t.d, l, i + j + k + 1, p)) continue;
              if (isOk(t, pal[p].len)) ret.push_back(t);
            }
        }
    }
}
void dfs(int p) {
  int i;
  if (p > tot) {
    if (cnt == n) {
      tmp.len = (tot << 1);
      for (i = tot + 1; i <= tmp.len; i++) tmp.a[i] = tmp.a[tmp.len - i + 1];
      pal.push_back(tmp);
      if (tot + tot - 1 >= 4) {
        tmp.len -= 1;
        for (i = tot + 1; i <= tmp.len; i++) tmp.a[i] = tmp.a[tmp.len - i + 1];
        pal.push_back(tmp);
      }
    }
    return;
  }
  for (i = 1; i <= n; i++) {
    if (!vis[i]) cnt++;
    vis[i]++;
    tmp.a[p] = a[i], dfs(p + 1);
    vis[i]--;
    if (!vis[i]) cnt--;
  }
}
void run() {
  int i, j;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  memset(vis, 0, sizeof(vis)), cnt = 0;
  ret.clear(), pal.clear();
  for (tot = 2; tot <= 6; tot++)
    if (tot >= n) dfs(1);
  for (i = 0; i < pal.size(); i++) addToRet(i);
  printf("%d\n", ret.size());
  for (i = 0; i < ret.size(); i++) ret[i].show();
}
void preSof() {}
int main() {
  preSof();
  while ((~scanf("%d", &n))) run();
  return 0;
}
