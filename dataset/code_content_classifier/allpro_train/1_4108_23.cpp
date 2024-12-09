#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int MAXM = 100023;
const int MAXN = 100023;
struct BSTNode {
  pair<int, int> l, r;
  BSTNode *lc, *rc;
  int minID;
  BSTNode() : l(-1, -1), r(-1, -1), lc(NULL), rc(NULL), minID(INF) {}
} base[MAXM * 50 + 1], *top = base;
typedef BSTNode *bt;
struct Point {
  int x, first, second;
  Point() : x(0), first(0), second(0) {}
  Point(int x, int first, int second) : x(x), first(first), second(second) {}
  pair<int, int> v() const { return pair<int, int>(first, second); }
  inline bool operator<(const Point &rhs) const {
    if (x != rhs.x) return x < rhs.x;
    if (first != rhs.first) return first < rhs.first;
    return second < rhs.second;
  }
} p[MAXN];
int pX[MAXN];
inline bool cmpByV(const Point &a, const Point &b) { return a.v() < b.v(); }
inline bt newNode(const pair<int, int> &v) {
  top->l = top->r = v;
  top->lc = top->rc = NULL;
  top->minID = v.second;
  return top++;
}
inline bt newNode(const pair<int, int> &l, const pair<int, int> &r,
                  const bt &lc, const bt &rc) {
  assert(lc != NULL && rc != NULL);
  top->l = l;
  top->r = r;
  top->lc = lc;
  top->rc = rc;
  top->minID = min(lc->minID, rc->minID);
  return top++;
}
inline bt buildBST(int l, int r) {
  if (l > r) return NULL;
  if (l == r) return newNode(p[l].v());
  int m((l + r) >> 1);
  return newNode(p[l].v(), p[r].v(), buildBST(l, m), buildBST(m + 1, r));
}
inline int qMinBST(bt t, int yl, int yr) {
  if (!t || yr < t->l.first || t->r.first < yl) return INF;
  if (yl <= t->l.first && t->r.first <= yr) return t->minID;
  return min(qMinBST(t->lc, yl, yr), qMinBST(t->rc, yl, yr));
}
inline void deleteBST(bt t, pair<int, int> v) {
  if (!(t->l <= v && v <= t->r)) return;
  if (t->lc == NULL) {
    assert(t->l == v);
    t->minID = INF;
    return;
  }
  deleteBST(t->lc, v);
  deleteBST(t->rc, v);
  t->minID = min(t->lc->minID, t->rc->minID);
}
struct SegNode {
  bt root;
} seg[MAXN << 2];
int N, M;
inline void buildSeg(int t, int xl, int xr) {
  int pl = lower_bound(pX + 1, pX + M + 1, xl) - pX;
  int pr = upper_bound(pX + 1, pX + M + 1, xr) - pX - 1;
  if (xl == xr) {
    sort(p + pl, p + pr + 1, cmpByV);
    seg[t].root = buildBST(pl, pr);
    return;
  }
  int m((xl + xr) >> 1);
  buildSeg(((t) << 1), xl, m);
  buildSeg((((t) << 1) + 1), m + 1, xr);
  sort(p + pl, p + pr + 1, cmpByV);
  seg[t].root = buildBST(pl, pr);
}
int xl, xr, yl, yr;
inline int qMinSeg(int t, int nl, int nr) {
  if (nr < xl || xr < nl) return INF;
  if (xl <= nl && nr <= xr) return qMinBST(seg[t].root, yl, yr);
  int m((nl + nr) >> 1);
  return min(qMinSeg(((t) << 1), nl, m), qMinSeg((((t) << 1) + 1), m + 1, nr));
}
int x, first, second;
inline void deleteSeg(int t, int nl, int nr) {
  if (!(nl <= x && x <= nr)) return;
  deleteBST(seg[t].root, pair<int, int>(first, second));
  if (nl == nr) return;
  int m((nl + nr) >> 1);
  deleteSeg(((t) << 1), nl, m);
  deleteSeg((((t) << 1) + 1), m + 1, nr);
}
int X0[MAXN], X1[MAXN], Y0[MAXN], Y1[MAXN], Z[MAXN];
int order[MAXN];
int valueX[MAXN], totX = 0;
inline bool cmpByZ(const int &a, const int &b) { return Z[a] < Z[b]; }
int main() {
  static int X[MAXM], Y[MAXM];
  scanf("%d", &N);
  for (int i(1); i <= (N); ++i)
    scanf("%d %d %d %d %d", X0 + i, X1 + i, Y0 + i, Y1 + i, Z + i);
  for (int i(1); i <= (N); ++i) order[i] = i;
  sort(order + 1, order + N + 1, cmpByZ);
  scanf("%d", &M);
  for (int i(1); i <= (M); ++i) {
    scanf("%d %d", X + i, Y + i);
    valueX[++totX] = X[i];
    p[i] = Point(X[i], Y[i], i);
  }
  sort(p + 1, p + M + 1);
  sort(valueX + 1, valueX + totX + 1);
  totX = unique(valueX + 1, valueX + totX + 1) - (valueX + 1);
  for (int i(1); i <= (M); ++i) {
    p[i].x = pX[i] =
        lower_bound(valueX + 1, valueX + totX + 1, p[i].x) - valueX;
  }
  buildSeg(1, 1, totX);
  static int res[MAXN];
  memset(res, 0, sizeof(res));
  for (int _(1); _ <= (N); ++_) {
    int i = order[_];
    xl = lower_bound(valueX + 1, valueX + totX + 1, X0[i]) - valueX;
    xr = upper_bound(valueX + 1, valueX + totX + 1, X1[i]) - valueX - 1;
    yl = Y0[i];
    yr = Y1[i];
    if (xl > xr) continue;
    int ans = qMinSeg(1, 1, totX);
    if (ans == INF) continue;
    res[ans] = i;
    x = lower_bound(valueX + 1, valueX + totX + 1, X[ans]) - valueX;
    first = Y[ans];
    second = ans;
    deleteSeg(1, 1, totX);
  }
  for (int i(1); i <= (M); ++i) printf("%d\n", res[i]);
  return 0;
}
