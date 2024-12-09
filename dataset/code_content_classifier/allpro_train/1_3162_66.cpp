#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct node {
  int op, t, x;
} p[maxn];
int t[maxn];
map<int, int> mp;
map<pair<int, int>, int> Tree;
void PushUp(int rt, int val) {
  if (!Tree.count(make_pair(rt << 1, val))) {
    Tree[make_pair(rt << 1, val)] = 0;
  }
  if (!Tree.count(make_pair(rt << 1 | 1, val))) {
    Tree[make_pair(rt << 1 | 1, val)] = 0;
  }
  Tree[make_pair(rt, val)] =
      Tree[make_pair(rt << 1, val)] + Tree[make_pair(rt << 1 | 1, val)];
}
void update(int p, int x, int val, int l, int r, int rt) {
  if (l == r && l == p) {
    Tree[make_pair(rt, x)] += val;
    ;
    return;
  }
  int m = (l + r) >> 1;
  if (p <= m)
    update(p, x, val, l, m, rt << 1);
  else
    update(p, x, val, m + 1, r, rt << 1 | 1);
  PushUp(rt, x);
}
int query(int p, int x, int l, int r, int rt) {
  if (r <= p) {
    return Tree[make_pair(rt, x)];
  }
  int m = (l + r) >> 1;
  int ret = 0;
  if (p <= m) ret += query(p, x, l, m, rt << 1);
  if (p > m)
    ret += query(p, x, l, m, rt << 1) + query(p, x, m + 1, r, rt << 1 | 1);
  return ret;
}
int main() {
  int n, k = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &p[i].op, &p[i].t, &p[i].x);
    t[i] = p[i].t;
  }
  sort(t, t + n);
  for (int i = 0; i < n; i++) {
    if (!mp.count(t[i])) {
      mp[t[i]] = k++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (p[i].op == 1) {
      update(mp[p[i].t], p[i].x, 1, 0, k, 1);
    } else if (p[i].op == 2) {
      update(mp[p[i].t], p[i].x, -1, 0, k, 1);
    } else {
      printf("%d\n", query(mp[p[i].t], p[i].x, 0, k, 1));
    }
  }
}
