#include <bits/stdc++.h>
using namespace std;
const int BUF = 400005;
const int INF = 1 << 30;
enum TYPE {
  HORIZONTAL_BAR_BEGIN = 0,
  VERTICAL_BAR = 1,
  HORIZONTAL_BAR_END = 2
};
class Event {
 public:
  int x, y1, y2, type, barId;
  Event() {}
  Event(int x, int y1, int y2, int type, int barId)
      : x(x), y1(y1), y2(y2), type(type), barId(barId) {}
  bool operator<(const Event &e) const {
    if (x != e.x) return x < e.x;
    return type < e.type;
  }
};
class Range {
 public:
  int bottom, top, id;
  Range() {}
  Range(int b, int t, int i) : bottom(b), top(t), id(i) {}
  bool operator<(const Range &r) const {
    if (bottom != r.bottom) return bottom < r.bottom;
    if (top != r.top) return top < r.top;
    return id < r.id;
  }
};
class Group {
 public:
  int g[BUF];
  long long sum[BUF];
  Group() {}
  void build(int n) {
    for (int i = 0; i < n; i++) {
      g[i] = i;
      sum[i] = 0;
    }
  }
  int findGroup(int n) { return (n == g[n] ? n : g[n] = findGroup(g[n])); }
  long long findSum(int n) { return sum[findGroup(n)]; }
  void mergeGroup(int a, int b) { g[findGroup(a)] = findGroup(b); }
  void mergeSum(int a, int b) {
    long long A = sum[findGroup(a)];
    long long B = sum[findGroup(b)];
    sum[findGroup(a)] += B;
    sum[findGroup(b)] += A;
  }
  void addSum(int a, int delta) { sum[findGroup(a)] += delta; }
};
class SegTree {
 public:
  int v[BUF * 4];
  int idxMax[BUF * 4];
  int idxMin[BUF * 4];
  SegTree() {
    memset(v, 0, sizeof(v));
    memset(idxMax, -1, sizeof(idxMax));
    memset(idxMin, -1, sizeof(idxMin));
  }
  int getMax(int node, int L, int R, int LQ, int RQ) {
    if (R < LQ || RQ < L) return -1;
    if (LQ <= L && R <= RQ) return idxMax[node];
    int s = getMax(node * 2 + 1, L, (L + R) / 2, LQ, RQ);
    int t = getMax(node * 2 + 2, (L + R) / 2 + 1, R, LQ, RQ);
    return max(s, t);
  }
  int getMin(int node, int L, int R, int LQ, int RQ) {
    if (R < LQ || RQ < L) return -1;
    if (LQ <= L && R <= RQ) return idxMin[node];
    int s = getMin(node * 2 + 1, L, (L + R) / 2, LQ, RQ);
    int t = getMin(node * 2 + 2, (L + R) / 2 + 1, R, LQ, RQ);
    if (s == -1) return t;
    if (t == -1) return s;
    return min(s, t);
  }
  int getSum(int node, int L, int R, int LQ, int RQ) {
    if (R < LQ || RQ < L) return 0;
    if (LQ <= L && R <= RQ) return v[node];
    int s = getSum(node * 2 + 1, L, (L + R) / 2, LQ, RQ);
    int t = getSum(node * 2 + 2, (L + R) / 2 + 1, R, LQ, RQ);
    return s + t;
  }
  void update(int node, int L, int R, int Q, int delta) {
    if (R < Q || Q < L) return;
    if (L == R) {
      v[node] += delta;
      idxMax[node] = idxMin[node] = (v[node] > 0 ? L : -1);
      return;
    }
    update(node * 2 + 1, L, (L + R) / 2, Q, delta);
    update(node * 2 + 2, (L + R) / 2 + 1, R, Q, delta);
    v[node] = v[node * 2 + 1] + v[node * 2 + 2];
    idxMax[node] = max(idxMax[node * 2 + 1], idxMax[node * 2 + 2]);
    if (idxMin[node * 2 + 1] == -1)
      idxMin[node] = idxMin[node * 2 + 2];
    else if (idxMin[node * 2 + 2] == -1)
      idxMin[node] = idxMin[node * 2 + 1];
    else
      idxMin[node] = min(idxMin[node * 2 + 1], idxMin[node * 2 + 2]);
  }
};
class Bar {
 public:
  int x1, y1, x2, y2;
  Bar() {}
  Bar(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};
int nBar;
Bar bar[BUF];
void read() {
  scanf("%d", &nBar);
  for (int i = 0; i < nBar; ++i) {
    Bar &b = bar[i];
    scanf("%d%d%d%d", &b.x1, &b.y1, &b.x2, &b.y2);
  }
}
void work() {
  map<int, int> y2val;
  map<int, int> val2y;
  set<int> ySet;
  for (int i = 0; i < nBar; ++i) {
    ySet.insert(bar[i].y1);
    ySet.insert(bar[i].y2);
  }
  for (set<int>::iterator it = ySet.begin(); it != ySet.end(); ++it) {
    int sz = y2val.size();
    y2val[*it] = sz;
    val2y[sz] = *it;
  }
  int ySz = ySet.size();
  vector<Event> event;
  for (int i = 0; i < nBar; ++i) {
    Bar &b = bar[i];
    if (b.x1 == b.x2) {
      event.push_back(Event(b.x1, y2val[b.y1], y2val[b.y2], VERTICAL_BAR, i));
    } else {
      event.push_back(
          Event(b.x1, y2val[b.y1], y2val[b.y1], HORIZONTAL_BAR_BEGIN, i));
      event.push_back(
          Event(b.x2, y2val[b.y1], y2val[b.y1], HORIZONTAL_BAR_END, i));
    }
  }
  sort(event.begin(), event.end());
  static Group group;
  group.build(nBar);
  static SegTree segtree;
  set<Range> S;
  for (int i = 0; i < event.size(); ++i) {
    Event &e = event[i];
    if (e.type == HORIZONTAL_BAR_BEGIN) {
      group.addSum(e.barId, abs(bar[e.barId].x1 - bar[e.barId].x2));
      set<Range>::iterator it = S.upper_bound(Range(e.y1, INF, INF));
      if (it != S.begin()) --it;
      if (it == S.end() || !(it->bottom < e.y1 && e.y1 < it->top)) {
        S.insert(Range(e.y1, e.y1, e.barId));
      } else {
        Range r = *it;
        int rIdx = segtree.getMax(0, 0, ySz - 1, r.bottom, e.y1);
        int lIdx = segtree.getMin(0, 0, ySz - 1, e.y1, r.top);
        S.erase(it);
        S.insert(Range(r.bottom, rIdx, r.id));
        S.insert(Range(lIdx, r.top, r.id));
        S.insert(Range(e.y1, e.y1, e.barId));
      }
      segtree.update(0, 0, ySz - 1, e.y1, 1);
    }
    if (e.type == VERTICAL_BAR) {
      set<Range>::iterator it = S.upper_bound(Range(e.y1, INF, INF));
      if (it != S.begin()) --it;
      Range newRange(INF, -INF, -1);
      int nCycle = 0;
      while (it != S.end() && it->bottom <= e.y2) {
        int minY = max(it->bottom, e.y1);
        int maxY = min(it->top, e.y2);
        if (minY > maxY) {
          ++it;
          continue;
        }
        int nCross = segtree.getSum(0, 0, ySz - 1, minY, maxY);
        if (nCross == 0) {
          ++it;
          continue;
        }
        nCycle += 1 - nCross;
        if (newRange.id == -1) {
          newRange.id = it->id;
        } else if (group.findGroup(it->id) != group.findGroup(newRange.id)) {
          group.mergeSum(newRange.id, it->id);
          group.mergeGroup(newRange.id, it->id);
        } else {
          group.addSum(newRange.id, -1);
        }
        newRange.bottom = min(newRange.bottom, it->bottom);
        newRange.top = max(newRange.top, it->top);
        S.erase(it++);
      }
      if (newRange.id != -1) {
        S.insert(newRange);
        group.addSum(newRange.id, abs(val2y[e.y2] - val2y[e.y1]));
        group.addSum(newRange.id, nCycle);
      }
    }
    if (e.type == HORIZONTAL_BAR_END) {
      set<Range>::iterator it = S.upper_bound(Range(e.y1, INF, INF));
      assert(it != S.begin());
      --it;
      Range nexRange = *it;
      segtree.update(0, 0, ySz - 1, e.y1, -1);
      if (nexRange.bottom == e.y1) {
        S.erase(it);
        int idx = segtree.getMin(0, 0, ySz - 1, e.y1, nexRange.top);
        if (idx != -1) {
          nexRange.bottom = idx;
          S.insert(nexRange);
        }
      } else if (nexRange.top == e.y1) {
        S.erase(it);
        int idx = segtree.getMax(0, 0, ySz - 1, nexRange.bottom, e.y1);
        if (idx != -1) {
          nexRange.top = idx;
          S.insert(nexRange);
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < nBar; ++i)
    ans = max(ans, llabs(bar[i].x1 - bar[i].x2) + llabs(bar[i].y1 - bar[i].y2));
  for (int i = 0; i < nBar; ++i) {
    ans = max(ans, group.findSum(i));
  }
  cout << ans << endl;
}
int main() {
  read();
  work();
  return 0;
}
