#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T& x) {
  x = 0;
  char temp = getchar();
  bool f = false;
  while (!isdigit(temp)) {
    if (temp == '-') f = true;
    temp = getchar();
  }
  while (isdigit(temp)) {
    x = (x << 1) + (x << 3) + temp - '0';
    temp = getchar();
  }
  if (f) x = -x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
const int MAXN = 2e5 + 5;
int n, m, q;
long long a[MAXN], b[MAXN];
struct Edge {
  int to, next;
  long long val;
} edge[MAXN];
int head[MAXN], cnt;
inline void AddEdge(int u, int v, long long w) {
  edge[++cnt] = (Edge){v, head[u], w}, head[u] = cnt;
}
struct Node {
  long long minn, tag;
  inline void Update(long long val) { minn += val, tag += val; }
} t[MAXN << 2];
inline int ls(int id) { return id << 1; }
inline int rs(int id) { return id << 1 | 1; }
inline void Pushup(int id) { t[id].minn = min(t[ls(id)].minn, t[rs(id)].minn); }
inline void Pushdown(int id) {
  if (t[id].tag)
    t[ls(id)].Update(t[id].tag), t[rs(id)].Update(t[id].tag), t[id].tag = 0;
}
void Build(int id, int l, int r) {
  if (l == r) return t[id].minn = b[l], void();
  int mid = l + r >> 1;
  Build(ls(id), l, mid), Build(rs(id), mid + 1, r);
  Pushup(id);
}
void Modify(int id, int l, int r, int L, int R, long long val) {
  if (L <= l && r <= R) return t[id].Update(val), void();
  Pushdown(id);
  int mid = l + r >> 1;
  if (L <= mid) Modify(ls(id), l, mid, L, R, val);
  if (R > mid) Modify(rs(id), mid + 1, r, L, R, val);
  Pushup(id);
}
long long match[MAXN];
multiset<long long> s;
int main() {
  read(n), read(m), read(q);
  for (register int i = 2; i <= n; i++) read(a[i]), read(b[1 + i]);
  for (register int i = 1, u, v, w; i <= m; i++)
    read(u), read(v), read(w), AddEdge(u, v + 1, w);
  Build(1, 1, n + 1);
  for (register int x = 2; x <= n + 1; x++) {
    for (register int i = head[x - 1]; i; i = edge[i].next)
      Modify(1, 1, n + 1, 1, edge[i].to, edge[i].val);
    s.insert(a[x] + (match[x] = t[1].minn));
  }
  print(*s.begin()), puts("");
  for (register int i = 1; i <= q; i++) {
    int x, val;
    read(x), read(val);
    x++;
    s.erase(s.find(a[x] + match[x]));
    a[x] = val, s.insert(a[x] + match[x]);
    print(*s.begin()), puts("");
  }
  return 0;
}
