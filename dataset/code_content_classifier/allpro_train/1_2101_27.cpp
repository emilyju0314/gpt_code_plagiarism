#include <bits/stdc++.h>
using namespace std;
long long next_int;
char in_char;
inline long long GetNextInt() {
  in_char = ' ';
  while ((in_char < '0') | (in_char > '9')) {
    in_char = getchar();
  }
  next_int = 0;
  while ((in_char >= '0') && (in_char <= '9')) {
    next_int *= 10;
    next_int += in_char - 48;
    in_char = getchar();
  }
  return next_int;
}
int n, m;
vector<pair<pair<int, int>, int> > sm;
vector<int> ans;
struct node {
  int l, r;
  int rm;
};
struct SegTree {
  node seg[400011];
  void Create(int root, int l, int r);
  int Query(int root, int l, int r);
  void Update(int root, int i);
} segtree;
inline void Solve() {
  int m, i, j;
  n = GetNextInt();
  m = GetNextInt();
  segtree.Create(1, 1, n);
  sm.resize(m);
  for (i = 0; i < m; i++) {
    sm[i].first.first = GetNextInt();
    sm[i].first.second = GetNextInt();
    sm[i].second = i + 1;
  }
  sort(sm.begin(), sm.end());
  for (i = 0; i < m; i++) {
    j = segtree.Query(1, n - sm[i].first.first + 1, sm[i].first.second);
    if (j != 2000000009) {
      ans.push_back(sm[i].second);
      segtree.Update(1, j);
    }
  }
  printf("%d\n", ans.size());
  for (i = 0; i < ans.size(); i++) {
    printf("%d ", ans[i]);
  }
  return;
}
int main() {
  int t;
  t = 1;
  while (t--) {
    Solve();
  }
  return 0;
}
void SegTree::Create(int root, int l, int r) {
  seg[root].l = l;
  seg[root].r = r;
  seg[root].rm = r;
  if (l == r) {
    return;
  }
  Create(root + root, l, (l + r) / 2);
  Create(root + root + 1, (l + r) / 2 + 1, r);
}
int SegTree::Query(int root, int l, int r) {
  if (l > seg[root].r || r < seg[root].l) {
    return -1;
  }
  if (l == seg[root].l && r == seg[root].r) {
    return seg[root].rm;
  }
  int mi = seg[root + root].r;
  if (l > mi) {
    return Query(root + root + 1, l, r);
  } else if (r <= mi) {
    return Query(root + root, l, r);
  }
  int ret = Query(root + root + 1, mi + 1, r);
  if (ret != 2000000009) {
    return ret;
  }
  return Query(root + root, l, mi);
  ;
}
void SegTree::Update(int root, int i) {
  if (i > seg[root].r || i < seg[root].l) {
    return;
  }
  if (seg[root].l == seg[root].r) {
    seg[root].rm = 2000000009;
    return;
  }
  int mi = seg[root + root].r;
  if (i > mi) {
    Update(root + root + 1, i);
  } else if (i <= mi) {
    Update(root + root, i);
  }
  seg[root].rm = seg[root + root + 1].rm;
  if (seg[root].rm == 2000000009) {
    seg[root].rm = seg[root + root].rm;
  }
  return;
}
