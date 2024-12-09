#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
using namespace std;
namespace ywy {
inline int get() {
  int n = 0;
  char c;
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9') break;
    if (c == '-') goto s;
  }
  n = c - '0';
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9')
      n = n * 10 + c - '0';
    else
      return (n);
  }
s:
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9')
      n = n * 10 - c + '0';
    else
      return (n);
  }
}
vector<int> vec[200001];
int v[2001][2001], lx[4] = {1, -1, 0, 0}, ly[4] = {0, 0, 1, -1};
int ch[200001][2], fa[200001], stk[200001];
unsigned char bj[200001];
typedef struct _n {
  int minn;
  int cnt;
  friend _n operator+(const _n &a, const _n &b) {
    _n c;
    c.minn = min(a.minn, b.minn);
    c.cnt = 0;
    if (a.minn == c.minn) c.cnt = a.cnt;
    if (b.minn == c.minn) c.cnt += b.cnt;
    return (c);
  }
} node;
node data[1000001];
int adds[1000001];
inline void down(int tree) {
  if (bj[tree])
    bj[tree] = 0, bj[ch[tree][0]] ^= 1, bj[ch[tree][1]] ^= 1,
    swap(ch[tree][0], ch[tree][1]);
}
inline void pushdown(int tree) {
  if (!adds[tree]) return;
  adds[(tree << 1)] += adds[tree];
  adds[((tree << 1) | 1)] += adds[tree];
  data[(tree << 1)].minn += adds[tree];
  data[((tree << 1) | 1)].minn += adds[tree];
  adds[tree] = 0;
}
inline void xuan(int me) {
  int tree = fa[me], cjr = fa[tree];
  down(cjr);
  down(tree);
  down(me);
  int op = (me == ch[fa[me]][1]), ls = ch[me][op ^ 1];
  ch[tree][op] = ls;
  fa[ls] = tree;
  ch[me][op ^ 1] = tree;
  if (!(tree != ch[fa[tree]][0] && tree != ch[fa[tree]][1]))
    ch[cjr][(tree == ch[fa[tree]][1])] = me;
  fa[tree] = me;
  fa[me] = cjr;
}
inline void splay(int tree) {
  if ((tree != ch[fa[tree]][0] && tree != ch[fa[tree]][1])) {
    down(tree);
    return;
  }
  int sp = 0, tmp = tree;
  while (!(tmp != ch[fa[tmp]][0] && tmp != ch[fa[tmp]][1]))
    stk[sp] = tmp, sp++, tmp = fa[tmp];
  down(tmp);
  while (sp) sp--, down(stk[sp]);
  while (!(tree != ch[fa[tree]][0] && tree != ch[fa[tree]][1])) {
    int cjr = fa[tree];
    if (!(cjr != ch[fa[cjr]][0] && cjr != ch[fa[cjr]][1]))
      xuan(((cjr == ch[fa[cjr]][1]) == (tree == ch[fa[tree]][1])) ? cjr : tree);
    xuan(tree);
  }
}
inline void access(int tree) {
  splay(tree);
  down(tree);
  ch[tree][1] = 0;
  while (fa[tree]) {
    int cjr = fa[tree];
    splay(cjr);
    down(cjr);
    ch[cjr][1] = tree;
    splay(tree);
  }
}
inline void makeroot(int tree) {
  access(tree);
  splay(tree);
  bj[tree] ^= 1;
}
inline int findroot(int tree) {
  access(tree);
  splay(tree);
  down(tree);
  while (ch[tree][0]) tree = ch[tree][0], down(tree);
  splay(tree);
  return (tree);
}
inline void link(int a, int b) {
  makeroot(a);
  fa[a] = b;
}
inline void cut(int a, int b) {
  makeroot(a);
  access(b);
  splay(a);
  down(a);
  fa[b] = ch[a][1] = 0;
}
node query(int rl, int rr, int l, int r, int tree) {
  if (rl == l && rr == r) return (data[tree]);
  int mid = (l + r) >> 1;
  pushdown(tree);
  if (rl > mid) return (query(rl, rr, mid + 1, r, ((tree << 1) | 1)));
  if (rr <= mid) return (query(rl, rr, l, mid, (tree << 1)));
  return (query(rl, mid, l, mid, (tree << 1)) +
          query(mid + 1, rr, mid + 1, r, ((tree << 1) | 1)));
}
void add(int rl, int rr, int l, int r, int tree, int x) {
  if (rl == l && rr == r) {
    adds[tree] += x;
    data[tree].minn += x;
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(tree);
  if (rl > mid)
    add(rl, rr, mid + 1, r, ((tree << 1) | 1), x);
  else {
    if (rr <= mid)
      add(rl, rr, l, mid, (tree << 1), x);
    else {
      add(rl, mid, l, mid, (tree << 1), x);
      add(mid + 1, rr, mid + 1, r, ((tree << 1) | 1), x);
    }
  }
  data[tree] = data[(tree << 1)] + data[((tree << 1) | 1)];
}
int links[200001];
void build(int l, int r, int tree) {
  if (l == r) {
    data[tree].minn = 0;
    data[tree].cnt = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, (tree << 1));
  build(mid + 1, r, ((tree << 1) | 1));
  data[tree] = data[(tree << 1)] + data[((tree << 1) | 1)];
}
void ywymain() {
  int n = get(), m = get();
  for (register int i = 1; i <= n; i++) {
    for (register int j = 1; j <= m; j++) v[i][j] = get();
  }
  for (register int i = 1; i <= n; i++) {
    for (register int j = 1; j <= m; j++) {
      for (register int k = 0; k < 4; k++) {
        int ix = j + lx[k], iy = i + ly[k];
        if (ix < 1 || iy < 1 || ix > m || iy > n) continue;
        if (v[i][j] > v[iy][ix])
          vec[v[i][j]].push_back(v[iy][ix]), vec[v[iy][ix]].push_back(v[i][j]);
      }
    }
  }
  n *= m;
  build(1, n, 1);
  add(1, n, 1, n, 1, 1);
  int ptr = 1;
  long long ans = 0;
  for (register int i = 1; i <= n; i++) {
    while (ptr < n) {
      int sp = 0;
      for (register int j = 0; j < vec[ptr + 1].size(); j++) {
        if (vec[ptr + 1][j] < i || vec[ptr + 1][j] > ptr + 1) continue;
        makeroot(ptr + 1);
        if (findroot(vec[ptr + 1][j]) == ptr + 1) {
          while (sp) sp--, cut(ptr + 1, links[sp]);
          goto s;
        }
        link(ptr + 1, vec[ptr + 1][j]);
        links[sp] = vec[ptr + 1][j], sp++;
      }
      ptr++;
      for (register int j = 0; j < vec[ptr].size(); j++) {
        if (vec[ptr][j] >= i && vec[ptr][j] < ptr) add(ptr, n, 1, n, 1, -1);
      }
      add(ptr, n, 1, n, 1, 1);
    }
  s:;
    node cjr = query(i, ptr, 1, n, 1);
    if (cjr.minn == 1) ans += cjr.cnt;
    add(i, n, 1, n, 1, -1);
    for (register int j = 0; j < vec[i].size(); j++) {
      if (vec[i][j] >= i && vec[i][j] <= ptr) {
        add(vec[i][j], n, 1, n, 1, 1);
        cut(i, vec[i][j]);
      }
    }
  }
  cout << ans << endl;
}
}  // namespace ywy
int main() {
  ywy::ywymain();
  return (0);
}
