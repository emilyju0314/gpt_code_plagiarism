#include <bits/stdc++.h>
using namespace std;
const int mx = 3e5 + 10;
struct Cloud {
  int l, r, c;
  Cloud(int x = 0, int y = 0, int z = 0) { l = x, r = y, c = z; }
};
struct Node {
  int p, opt, id;
  Node(int x = 0, int y = 0, int z = 0) { p = x, opt = y, id = z; }
};
struct Tq {
  int k, id;
  Tq(int x = 0, int y = 0) { k = x, id = y; }
};
struct Tnode {
  int lc, rc;
  int Max, mp;
  Tnode() { lc = rc = Max = mp = 0; }
};
Tnode node[mx * 4];
int tp = 1;
int newnode() { return tp++; }
int build(int l, int r) {
  if (l > r) return 0;
  int x = newnode();
  Tnode &t = node[x];
  if (l == r) {
    t.Max = 0;
    t.mp = l;
    return x;
  }
  int mid = (l + r) >> 1;
  t.lc = build(l, mid);
  t.rc = build(mid + 1, r);
  t.Max = max(node[t.lc].Max, node[t.rc].Max);
  return x;
}
void insert(int x, int xl, int xr, int l, int r, int v) {
  if (!x) return;
  Tnode &t = node[x];
  if (xl == l && xr == r) {
    t.Max = v;
    t.mp = l;
    return;
  }
  int mid = (xl + xr) >> 1;
  if (t.lc && l <= mid) insert(t.lc, xl, mid, l, min(mid, r), v);
  if (t.rc && r > mid) insert(t.rc, mid + 1, xr, max(l, mid + 1), r, v);
  if (node[t.lc].Max > node[t.rc].Max)
    t.Max = node[t.lc].Max, t.mp = node[t.lc].mp;
  else
    t.Max = node[t.rc].Max, t.mp = node[t.rc].mp;
  return;
}
Tnode ask(int x, int xl, int xr, int l, int r) {
  if (!x || l > r) return Tnode();
  Tnode &t = node[x];
  if (xl == l && xr == r) return t;
  int mid = (xl + xr) >> 1;
  Tnode ans1, ans2;
  if (t.lc && l <= mid) ans1 = ask(t.lc, xl, mid, l, min(mid, r));
  if (t.rc && r > mid) ans2 = ask(t.rc, mid + 1, xr, max(l, mid + 1), r);
  if (ans1.Max > ans2.Max) return ans1;
  return ans2;
}
int n, C, m;
Cloud c[mx];
Node a[mx * 2];
Tq q[mx];
int len[mx * 2], cho[mx * 2];
inline int read() {
  char ch = 0;
  int w = 0, x = 0;
  while (!isdigit(ch)) w |= (ch == '-'), ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return w ? -x : x;
}
bool cmp1(Cloud x, Cloud y) { return x.c < y.c; }
bool cmp2(Node x, Node y) { return x.p < y.p; }
bool cmp3(Tq x, Tq y) { return x.k < y.k; }
void init() {
  n = read(), C = read();
  for (int i = 1; i <= n; i++)
    c[i].l = read(), c[i].r = read(), c[i].c = read();
  m = read();
  for (int i = 0; i < m; i++) q[i] = Tq(read(), i);
  sort(c + 1, c + n + 1, cmp1);
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    a[++cnt] = Node(c[i].l, 1, i), a[++cnt] = Node(c[i].r, -1, i);
  a[++cnt] = Node(2000000001, 1, n + 1);
  sort(a + 1, a + n + n + 1, cmp2);
  sort(q, q + m, cmp3);
}
int find(int v) {
  int l = 0, r = n + 1, mid;
  while (l + 1 < r) {
    mid = (l + r) >> 1;
    if (c[mid].c <= v)
      l = mid;
    else
      r = mid;
  }
  return l;
}
multiset<int> st;
multiset<int>::iterator it;
map<int, int> mp[mx];
int ans[mx];
int calc(int x, int y) {
  if (x == y) return len[x];
  if (x > y) swap(x, y);
  return len[x] + len[y] + mp[x][y];
}
void task() {
  build(1, n);
  int free = 0, delta = 0;
  for (int i = 1, pos = 0, tim = 0; i <= n * 2 + 1; i++) {
    int ln = a[i].p - tim;
    tim = a[i].p;
    if (st.size() == 0)
      free += ln;
    else if (st.size() == 1) {
      int x = *st.begin();
      len[x] += ln, cho[x] += ln;
      if (C >= c[x].c) {
        int l = 1, r = find(C - c[x].c), val = len[x];
        val = max(val, calc(x, ask(1, 1, n, l, r).mp));
        cho[x] = max(cho[x], val);
        delta = max(delta, cho[x]);
      }
      insert(1, 1, n, x, x, len[x]);
    } else if (st.size() == 2) {
      int x, y;
      it = st.begin();
      x = *it;
      it++;
      y = *it;
      mp[x][y] += ln;
      if (c[x].c + c[y].c <= C) {
        int tmp = calc(x, y);
        cho[x] = max(cho[x], tmp);
        cho[y] = max(cho[y], tmp);
        delta = max(delta, tmp);
      }
    }
    while (pos < m && free + delta >= q[pos].k)
      ans[q[pos].id] = tim - (free + delta - q[pos].k), pos++;
    if (a[i].opt == 1)
      st.insert(a[i].id);
    else
      st.erase(a[i].id);
  }
  for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
}
int main() {
  init();
  task();
  return 0;
}
