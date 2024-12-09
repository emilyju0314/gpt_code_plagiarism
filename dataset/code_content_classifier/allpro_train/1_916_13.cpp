#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
int N, M, K, tp;
namespace SegmentTree {
struct SegmentTreeNode {
  int l, r, size, cov, sum;
} tree[1000010 << 2];
inline void Update(int now) {
  tree[now].sum = tree[now << 1].sum + tree[now << 1 | 1].sum;
  tree[now].sum %= 1000000007;
}
inline void BuildTree(int now, int l, int r) {
  tree[now].l = l;
  tree[now].r = r;
  tree[now].size = r - l + 1;
  tree[now].cov = -1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  BuildTree(now << 1, l, mid);
  BuildTree(now << 1 | 1, mid + 1, r);
  Update(now);
}
inline void cover(int now, int D) {
  tree[now].cov = D;
  tree[now].sum = (long long)tree[now].size * D % 1000000007;
}
inline void PushDown(int now) {
  if (tree[now].l == tree[now].r) return;
  if (tree[now].cov != -1)
    cover(now << 1, tree[now].cov), cover(now << 1 | 1, tree[now].cov),
        tree[now].cov = -1;
}
inline void Cover(int now, int L, int R, int D) {
  if (R < L) return;
  int l = tree[now].l, r = tree[now].r;
  PushDown(now);
  if (L <= l && R >= r) {
    cover(now, D);
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid) Cover(now << 1, L, R, D);
  if (R > mid) Cover(now << 1 | 1, L, R, D);
  Update(now);
}
inline void Modify(int now, int pos, int D) {
  int l = tree[now].l, r = tree[now].r;
  PushDown(now);
  if (l == r) {
    cover(now, D);
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid)
    Modify(now << 1, pos, D);
  else
    Modify(now << 1 | 1, pos, D);
  Update(now);
}
inline int Query(int now, int L, int R) {
  if (R < L) return 0;
  int l = tree[now].l, r = tree[now].r;
  PushDown(now);
  if (L <= l && R >= r) return tree[now].sum;
  int mid = (l + r) >> 1, re = 0;
  if (L <= mid) (re += Query(now << 1, L, R)) %= 1000000007;
  if (R > mid) (re += Query(now << 1 | 1, L, R)) %= 1000000007;
  return re;
}
}  // namespace SegmentTree
struct LineNode {
  int x, y1, y2, f;
} Line[1000010 << 1];
bool cmp(LineNode A, LineNode B) {
  return A.x == B.x ? A.y1 == B.y1 ? A.y2 > B.y2 : A.y1 > B.y1 : A.x < B.x;
}
set<pair<int, int> > mp;
set<pair<int, int> >::iterator is;
pair<int, int> loc;
int main() {
  N = read(), M = read(), K = read();
  for (int x1, x2, y1, y2, i = 1; i <= K; i++)
    x1 = read(), y1 = read(), x2 = read(), y2 = read(), Line[++tp].x = x1,
    Line[tp].y1 = y1, Line[tp].y2 = y2, Line[tp].f = 1, Line[++tp].x = x2 + 1,
    Line[tp].y1 = y1, Line[tp].y2 = y2, Line[tp].f = 0;
  SegmentTree::BuildTree(1, 1, M);
  SegmentTree::Modify(1, 1, 1);
  sort(Line + 1, Line + tp + 1, cmp);
  int X = 1;
  for (int i = 1; Line[i].x == 1; X++, i++)
    if (Line[i].f) mp.insert(make_pair(Line[i].y1, Line[i].y2));
  mp.insert(make_pair(0, 0));
  for (int i = 2; i <= N; i++) {
    for (int j = X, tmp; Line[j].x == i; j++)
      if (Line[j].f)
        if (Line[j].y2 < M)
          loc = (*--mp.lower_bound(make_pair(Line[j].y2 + 2, 0))),
          tmp = SegmentTree::Query(1, loc.second + 1, Line[j].y2 + 1),
          SegmentTree::Modify(1, Line[j].y2 + 1, tmp);
    for (int j = X; Line[j].x == i; j++)
      if (!Line[j].f) mp.erase(make_pair(Line[j].y1, Line[j].y2));
    for (int j = X; Line[j].x == i; X++, j++)
      if (Line[j].f)
        mp.insert(make_pair(Line[j].y1, Line[j].y2)),
            SegmentTree::Cover(1, Line[j].y1, Line[j].y2, 0);
  }
  loc = *(--mp.end());
  printf("%d\n", SegmentTree::Query(1, loc.first + 1, M) % 1000000007);
  return 0;
}
