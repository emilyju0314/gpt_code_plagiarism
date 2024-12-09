#include <bits/stdc++.h>
using namespace std;
const int maxN = 100100;
const int maxQ = 200200;
const int maxK = 200200;
const int INF = (int)1e9;
struct segmentTree {
  vector<int> segMin;
  int segN, n;
  segmentTree(int n) : n(n) {
    for (segN = 2; segN < n; segN <<= 1)
      ;
    segMin.assign(segN << 1, -1);
  }
  inline void update(int pos, int v) {
    segMin[pos + segN] = v;
    for (int x = (pos + segN) >> 1; x > 0; x >>= 1) {
      segMin[x] = min(segMin[x << 1], segMin[(x << 1) | 1]);
    }
  }
  inline int getMin(int l, int r) {
    int ret = INF;
    for (l += segN, r += segN; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) ret = min(ret, segMin[l++]);
      if (~r & 1) ret = min(ret, segMin[r--]);
    }
    return ret;
  }
};
struct Query {
  int x1, x2, y1, y2;
  int idx;
  bool operator<(const Query& o) const {
    if (x1 != o.x1) return x1 < o.x1;
    return x2 < o.x2;
  }
} queries[maxQ];
int safe[maxQ];
pair<int, int> pos[maxK];
int n, m, k, q;
void solveX() {
  sort(pos, pos + k,
       [](pair<int, int> x, pair<int, int> y) { return x.first < y.first; });
  sort(queries, queries + q, [](Query x, Query y) { return x.x2 < y.x2; });
  int ptr = 0;
  segmentTree st(maxN);
  for (int i = 0; i < (q); ++i) {
    while (ptr < k and pos[ptr].first <= queries[i].x2) {
      st.update(pos[ptr].second, pos[ptr].first);
      ++ptr;
    }
    int minIdx = st.getMin(queries[i].y1, queries[i].y2);
    if (queries[i].x1 <= minIdx) {
      safe[queries[i].idx] = true;
    }
  }
}
void solveY() {
  sort(pos, pos + k,
       [](pair<int, int> x, pair<int, int> y) { return x.second < y.second; });
  sort(queries, queries + q, [](Query x, Query y) { return x.y2 < y.y2; });
  int ptr = 0;
  segmentTree st(maxN);
  for (int i = 0; i < (q); ++i) {
    while (ptr < k and pos[ptr].second <= queries[i].y2) {
      st.update(pos[ptr].first, pos[ptr].second);
      ++ptr;
    }
    int minIdx = st.getMin(queries[i].x1, queries[i].x2);
    if (queries[i].y1 <= minIdx) {
      safe[queries[i].idx] = true;
    }
  }
}
inline void rotate(int& x, int& y) {
  int nx = m - 1 - y;
  int ny = x;
  x = nx, y = ny;
}
int main() {
  scanf("%d", &n), scanf("%d", &m), scanf("%d", &k), scanf("%d", &q);
  for (int i = 0; i < (k); ++i) {
    scanf("%d", &pos[i].first), scanf("%d", &pos[i].second);
    --pos[i].first;
    --pos[i].second;
  }
  for (int i = 0; i < (q); ++i) {
    scanf("%d", &queries[i].x1), scanf("%d", &queries[i].y1);
    --queries[i].x1, --queries[i].y1;
    scanf("%d", &queries[i].x2), scanf("%d", &queries[i].y2);
    --queries[i].x2, --queries[i].y2;
    queries[i].idx = i;
  }
  memset(safe, false, sizeof(safe));
  solveX();
  solveY();
  for (int i = 0; i < (q); ++i) {
    puts(safe[i] ? "YES" : "NO");
  }
  return 0;
}
