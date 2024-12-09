#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(23049809);
class node {
 public:
  int ch[2], val, key, add, ans, cnt;
} t[200010];
inline void pushnow_add(int p, int v) {
  if (!p) return;
  t[p].add += v;
  t[p].val += v;
}
inline void pushnow_cnt(int p, int v) {
  if (!p) return;
  t[p].cnt += v;
  t[p].ans += v;
}
inline void pushdown(int p) {
  if (t[p].add) {
    pushnow_add((t[p].ch[0]), t[p].add);
    pushnow_add((t[p].ch[1]), t[p].add);
    t[p].add = 0;
  }
  if (t[p].ans) {
    pushnow_cnt((t[p].ch[0]), t[p].ans);
    pushnow_cnt((t[p].ch[1]), t[p].ans);
    t[p].ans = 0;
  }
}
void split(int p, int &x, int &y, int v) {
  if (!p) {
    x = y = 0;
    return;
  }
  pushdown(p);
  if (t[p].val < v)
    x = p, split((t[p].ch[1]), t[x].ch[1], y, v);
  else
    y = p, split((t[p].ch[0]), x, t[y].ch[0], v);
}
inline int merge(int x, int y) {
  if (!x || !y) return x + y;
  pushdown(x);
  pushdown(y);
  if (t[x].key < t[y].key) {
    t[x].ch[1] = merge(t[x].ch[1], y);
    return x;
  } else {
    t[y].ch[0] = merge(x, t[y].ch[0]);
    return y;
  }
}
inline void dfs(int p) {
  if (!p) return;
  pushdown(p);
  dfs((t[p].ch[0]));
  dfs((t[p].ch[1]));
}
int n, m, rt;
inline int cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second != b.second ? a.second > b.second : a.first < b.first;
}
pair<int, int> a[200010];
inline int insert(int x, int y) {
  int t1, t2;
  split(x, t1, t2, t[y].val);
  t1 = merge(t1, y);
  x = merge(t1, t2);
  return x;
}
inline void build(int &x, int p) {
  if (!p) return;
  pushdown(x);
  pushdown(p);
  build(x, (t[p].ch[0]));
  build(x, (t[p].ch[1]));
  (t[p].ch[0]) = (t[p].ch[1]) = 0;
  x = insert(x, p);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].first, &a[i].second);
  sort(a + 1, a + n + 1, cmp);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &t[i].val);
    t[i].key = rnd();
    rt = insert(rt, i);
  }
  for (int i = 1; i <= n; i++) {
    int c = a[i].first;
    int t1, t2, t3, t4;
    split(rt, t1, t2, c);
    pushnow_add(t2, -c);
    pushnow_cnt(t2, 1);
    split(t2, t3, t4, c - 1);
    build(t1, t3);
    rt = merge(t1, t4);
  }
  dfs(rt);
  for (int i = 1; i <= m; i++) printf("%d ", t[i].cnt);
  return 0;
}
