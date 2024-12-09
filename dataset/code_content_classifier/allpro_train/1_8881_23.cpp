#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
const int OO = 1e9;
struct vertex {
  int add;
  int val;
  int pos;
  int tp;
  vertex(int add = 0, int val = 0, int pos = 0, int tp = 0)
      : val(val), add(add), pos(pos), tp(tp) {}
  vertex operator*(const vertex& v) const {
    vertex ret;
    if (tp != 1) {
      ret.val = v.val;
      ret.pos = v.pos;
      ret.tp = v.tp;
    } else if (v.tp != 1) {
      ret.val = val;
      ret.pos = pos;
      ret.tp = tp;
    } else {
      if (val > v.val) {
        ret.val = val;
        ret.pos = pos;
        ret.tp = tp;
      } else {
        ret.val = v.val;
        ret.pos = v.pos;
        ret.tp = v.tp;
      }
    }
    return ret;
  }
};
vertex neutral(0, 0, -1, -1);
struct SegTree {
  int ds;
  vector<vertex> t;
  SegTree(int n) {
    for (ds = 1; ds < n; ds *= 2)
      ;
    t.assign(2 * ds + 1, neutral);
  }
  void push(int v) {
    if (t[v].add) {
      t[v + v].val += t[v].add;
      t[v + v].add += t[v].add;
      t[v + v + 1].val += t[v].add;
      t[v + v + 1].add += t[v].add;
      t[v].add = 0;
    }
  }
  void add(int L, int R, int a, int v, int l, int r) {
    if (R < l || r < L) return;
    if (L <= l && r <= R) {
      t[v].add += a;
      t[v].val += a;
    } else {
      int m = (l + r) / 2;
      push(v);
      add(L, R, a, v + v, l, m);
      add(L, R, a, v + v + 1, m + 1, r);
      t[v] = t[v + v] * t[v + v + 1];
    }
  }
  void set(int x, int tp, int v, int l, int r) {
    if (l == r) {
      t[v].pos = x;
      t[v].tp = tp;
    } else {
      int m = (l + r) / 2;
      push(v);
      if (x <= m) {
        set(x, tp, v + v, l, m);
      } else {
        set(x, tp, v + v + 1, m + 1, r);
      }
      t[v] = t[v + v] * t[v + v + 1];
    }
  }
  vertex query(int L, int R, int v, int l, int r) {
    if (r < L || R < l) return neutral;
    if (L <= l && r <= R) {
      return t[v];
    } else {
      push(v);
      int m = (l + r) / 2;
      return query(L, R, v + v, l, m) * query(L, R, v + v + 1, m + 1, r);
    }
  }
  int go(int v, int l, int r) {
    if (l == r) {
      return t[v].pos;
    } else {
      int m = (l + r) / 2;
      push(v);
      if (t[v + v + 1].tp == 1 && t[v + v + 1].val > 0) {
        return go(v + v + 1, m + 1, r);
      } else {
        return go(v + v, l, m);
      }
    }
  }
  void add(int L, int R, int a) { add(L, R, a, 1, 0, ds - 1); }
  void set(int x, int tp) { set(x, tp, 1, 0, ds - 1); }
  vertex query(int L, int R) { return query(L, R, 1, 0, ds - 1); }
  int go() { return go(1, 0, ds - 1); }
};
int val[N + 1];
void debugtree(SegTree& t) {
  for (int(i) = (0); (i) < (t.ds); (i)++) {
    vertex q = t.query(i, i);
    printf("%d ", q.val);
  }
  printf("\n");
}
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  SegTree tree(n + 1);
  for (int(i) = (0); (i) < (n); (i)++) {
    int p, tp;
    cin >> p >> tp;
    if (tp == 1) {
      int x;
      cin >> x;
      tree.add(0, p, 1);
      tree.set(p, 1);
      val[p] = x;
    } else {
      tree.add(0, p, -1);
      tree.set(p, 0);
    }
    int q = tree.go();
    if (q == -1) {
      cout << -1 << endl;
    } else {
      cout << val[q] << endl;
      ;
    }
  }
  return 0;
};
