#include <bits/stdc++.h>
using namespace std;
const int inf = 2147483647;
const int N = 500001;
int _max(int x, int y) { return x > y ? x : y; }
int _min(int x, int y) { return x < y ? x : y; }
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x * f;
}
void put(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) put(x / 10);
  putchar(x % 10 + '0');
}
struct edge {
  int x, y, next;
} e[N];
int len, last[N];
int st[N], ll[N], rr[N];
long long f[N], s[N], ans[N], uu[N];
int rt, mx[N], son[N], top[N], dep[N], tot[N];
int id, bak[N], hh[N];
queue<int> q;
void ins(int x, int y) {
  e[++len].x = x, e[len].y = y;
  e[len].next = last[x], last[x] = len;
}
void dfs1(int x) {
  tot[x] = 1;
  for (int k = last[x]; k; k = e[k].next) {
    int y = e[k].y;
    dep[y] = dep[x] + 1;
    dfs1(y), tot[x] += tot[y];
    if (mx[y] + 1 > mx[x]) mx[x] = mx[y] + 1, son[x] = y;
  }
}
void dfs2(int x, int tp) {
  top[x] = tp, st[x] = ++id, uu[x] += tot[x] - 1;
  if (son[x]) uu[son[x]] = uu[x], dfs2(son[x], tp);
  for (int k = last[x]; k; k = e[k].next) {
    int y = e[k].y;
    if (y != son[x]) uu[y] = uu[x], dfs2(y, y);
  }
}
void bfs() {
  q.push(rt);
  id = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    hh[x] = ++id, bak[id] = x;
    for (int k = last[x]; k; k = e[k].next) {
      int y = e[k].y;
      q.push(y);
    }
  }
}
void treedp(int x) {
  int z = dep[x] - dep[top[x]];
  if (son[x]) treedp(son[x]);
  for (int k = last[x]; k; k = e[k].next) {
    int y = e[k].y;
    if (y != son[x]) {
      treedp(y);
      for (int i = 1; i <= _min(mx[y] + 1, mx[x] - 1); i++) {
        s[ll[st[x] + i]] -= (long long)(z + 1) * f[st[x] + i + 1];
        s[rr[st[x] + i] + 1] += (long long)(z + 1) * f[st[x] + i + 1];
      }
      for (int i = mx[y] + 1; i >= 1; i--) {
        f[st[x] + i] += f[st[y] + i - 1];
        ll[st[x] + i] = _min(ll[st[x] + i], ll[st[y] + i - 1]);
        rr[st[x] + i] = _max(rr[st[x] + i], rr[st[y] + i - 1]);
        if (i < mx[x]) {
          s[ll[st[x] + i]] += (long long)(z + 1) * f[st[x] + i + 1];
          s[rr[st[x] + i] + 1] -= (long long)(z + 1) * f[st[x] + i + 1];
        }
      }
    }
  }
  f[st[x]]++, ll[st[x]] = rr[st[x]] = hh[x];
  if (son[x]) {
    f[st[x]] += f[st[x] + 1];
    s[ll[st[x]]] += (long long)z * f[st[x] + 1],
        s[rr[st[x]] + 1] -= (long long)z * f[st[x] + 1];
  }
}
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) {
    int fa = read();
    if (!fa)
      rt = i;
    else
      ins(fa, i);
  }
  dfs1(rt), dfs2(rt, rt), bfs();
  treedp(rt);
  for (int i = 1; i <= n; i++) s[i] += s[i - 1];
  for (int i = 1; i <= n; i++) ans[bak[i]] = s[i];
  for (int i = 1; i <= n; i++) put((uu[i] - tot[i] + 1) - ans[i]), puts("");
  return 0;
}
