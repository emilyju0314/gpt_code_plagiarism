#include <bits/stdc++.h>
using namespace std;
template <typename tn>
inline void read(tn &a) {
  tn x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  a = x * f;
}
struct line {
  int l, r, v, id;
} a[400500], b[400500];
int n, m, ans_i, ans_j;
long long ans = 0;
bool cmp1(line p, line q) { return p.l < q.l; }
void solve1() {
  sort(a + 1, a + n + 1, cmp1);
  sort(b + 1, b + m + 1, cmp1);
  int pos = 1, Max_rgt = 0, Max_i;
  for (int i = 1; i <= m; i++) {
    while (a[pos].l <= b[i].l && pos <= n) {
      if (Max_rgt < a[pos].r) Max_rgt = a[pos].r, Max_i = pos;
      pos++;
    }
    int l = b[i].l, r = min(Max_rgt, b[i].r);
    long long tmp = (long long)(r - l) * b[i].v;
    if (tmp > ans) ans = tmp, ans_i = a[Max_i].id, ans_j = b[i].id;
  }
}
bool cmp2(line p, line q) { return p.r > q.r; }
void solve2() {
  sort(a + 1, a + n + 1, cmp2);
  sort(b + 1, b + m + 1, cmp2);
  int pos = 1, Min_lft = 1e9, Min_i;
  for (int i = 1; i <= m; i++) {
    while (a[pos].r >= b[i].r && pos <= n) {
      if (Min_lft > a[pos].l) Min_lft = a[pos].l, Min_i = pos;
      pos++;
    }
    int l = max(Min_lft, b[i].l), r = b[i].r;
    long long tmp = (long long)(r - l) * b[i].v;
    if (tmp > ans) ans = tmp, ans_i = a[Min_i].id, ans_j = b[i].id;
  }
}
struct node {
  int ans, id;
};
node Max(node p, node q) {
  if (p.ans > q.ans) return p;
  return q;
}
struct Segment_tree {
  struct Sgt_point {
    int lc, rc, max, id;
  } tree[400500 * 20];
  int cnt, root;
  void init() { cnt = 0; }
  void push_up(int k, int son1, int son2) {
    node p = {tree[son1].max, tree[son1].id},
         q = {tree[son2].max, tree[son2].id};
    node tmp = Max(p, q);
    tree[k].max = tmp.ans, tree[k].id = tmp.id;
  }
  void modify(int &pos, int l, int r, int P, int x, int id) {
    if (!pos) pos = ++cnt;
    if (l == r) {
      if (tree[pos].max < x) tree[pos].max = x, tree[pos].id = id;
      return;
    }
    int mid = (l + r) / 2;
    if (P <= mid)
      modify(tree[pos].lc, l, mid, P, x, id);
    else
      modify(tree[pos].rc, mid + 1, r, P, x, id);
    push_up(pos, tree[pos].lc, tree[pos].rc);
  }
  void modify(int P, int x, int id) { modify(root, 0, 1e9, P, x, id); }
  node query(int pos, int l, int r, int L, int R) {
    if (!pos) {
      node p = {0, 0};
      return p;
    }
    if (L <= l && R >= r) return (node){tree[pos].max, tree[pos].id};
    int mid = (l + r) / 2;
    node ans = {0, 0};
    if (L <= mid) ans = query(tree[pos].lc, l, mid, L, R);
    if (R >= mid) ans = Max(ans, query(tree[pos].rc, mid + 1, r, L, R));
    return ans;
  }
  node query(int L, int R) { return query(root, 0, 1e9, L, R); }
} Sgt;
bool cmp3(line p, line q) { return p.r < q.r; }
void solve3() {
  Sgt.init();
  sort(a + 1, a + n + 1, cmp3);
  sort(b + 1, b + m + 1, cmp3);
  int pos = 1;
  for (int i = 1; i <= m; i++) {
    while (a[pos].r <= b[i].r && pos <= n)
      Sgt.modify(a[pos].l, a[pos].r - a[pos].l, pos), pos++;
    node p = Sgt.query(b[i].l, b[i].r);
    long long tmp = (long long)p.ans * b[i].v;
    if (tmp > ans) ans = tmp, ans_i = a[p.id].id, ans_j = b[i].id;
  }
}
int main() {
  read(n);
  read(m);
  for (int i = 1; i <= n; i++) read(a[i].l), read(a[i].r), a[i].id = i;
  for (int i = 1; i <= m; i++)
    read(b[i].l), read(b[i].r), read(b[i].v), b[i].id = i;
  solve1();
  solve2();
  solve3();
  cout << ans << endl;
  if (ans) cout << ans_i << ' ' << ans_j << endl;
  return 0;
}
