#include <bits/stdc++.h>
using namespace std;
const int MAXINT = numeric_limits<int>::max();
struct ans_t {
  int depth, shift;
  ans_t(int d, int s) : depth(d), shift(s) {}
};
class Solver {
 public:
  Solver(vector<int> const& a) : _a(a.size(), 0), _n(a.size()), _s(0) {
    int m = a[0], s = 0;
    for (int i = 0; i < _n; ++i) {
      if (a[i] < m) {
        m = a[i];
        s = i;
      }
    }
    _s = s + 1;
    for (int i = 0; i < _n; ++i) _a[i] = a[(i + _s) % _n];
    build_rmq();
  }
  ans_t solve() {
    int a = 0, b = _n;
    while (a + 1 < b) {
      int c = (a + b) >> 1;
      if (depth(0, c) <= depth(c, _n - 1))
        a = c;
      else
        b = c;
    }
    int bestd = test_shift(a), bests = a;
    if (a + 1 < _n) {
      int d = test_shift(a + 1);
      if (d < bestd) {
        bestd = d;
        bests = a + 1;
      }
    }
    return ans_t(bestd, (_s + bests) % _a.size());
  }

 private:
  void build_rmq() {
    if (!_rmq.empty()) return;
    int s = 1;
    _rmq.emplace_back(_n);
    for (int i = 0; i < _n; ++i) _rmq[0][i] = i;
    for (int a = 0; 2 * s <= _n; ++a, s <<= 1) {
      int n = _n - 2 * s;
      _rmq.emplace_back(n + 1);
      for (int i = 0; i <= n; ++i) {
        int m0 = _rmq[a][i], m1 = _rmq[a][i + s];
        _rmq[a + 1][i] = (_a[m1] < _a[m0]) ? m1 : m0;
      }
    }
  }
  int min_idx(int i, int j) {
    int a = 31 - __builtin_clz(j - i);
    int m0 = _rmq[a][i], m1 = _rmq[a][j - (1 << a)];
    return (_a[m1] < _a[m0]) ? m1 : m0;
  }
  int depth(int i, int j) {
    queue<segment_t> q;
    int r = 0;
    if (i < j) q.emplace(i, j, 1);
    while (!q.empty()) {
      const auto x = q.front();
      q.pop();
      r = max(r, x.depth);
      int mid = min_idx(x.begin, x.end);
      if (x.begin < mid) q.emplace(x.begin, mid, x.depth + 1);
      if (mid + 1 < x.end) q.emplace(mid + 1, x.end, x.depth + 1);
    }
    return r;
  }
  int test_shift(int s) { return 1 + max(depth(0, s), depth(s, _n - 1)); }

 private:
  vector<int> _a;
  vector<vector<int>> _rmq;
  int _n, _s;
  struct segment_t {
    int begin, end, depth;
    segment_t(int b, int e, int d) : begin(b), end(e), depth(d) {}
  };
};
int main() {
  int n, s;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) cin >> a[i];
  ans_t r = Solver(a).solve();
  cout << r.depth << " " << r.shift << endl;
}
