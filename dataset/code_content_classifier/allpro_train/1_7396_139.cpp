#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int s1[N], m1[N], r1[N];
struct Line {
  int t;
  long long a;
  long long b;
  bool operator<(const Line& x) const { return t < x.t; }
};
struct Node {
  vector<Line> vec;
  void init(int l, int r) {
    vec.push_back({0, 0, 0});
    for (int i = l; i < r; i++) {
      vec.push_back({
          r1[i] ? m1[i] / r1[i] + 1 : INT_MAX,
          -r1[i],
          +m1[i],
      });
      vec[0].a += r1[i];
    }
    sort(vec.begin(), vec.end());
    for (int i = 1; i < (int)vec.size(); i++)
      vec[i].b += vec[i - 1].b, vec[i].a += vec[i - 1].a;
  }
  long long query(int x) {
    const auto i = upper_bound(vec.begin(), vec.end(), (Line){x, 0, 0}) - 1;
    return i->a * x + i->b;
  }
};
struct Tree {
  int l;
  int r;
  Tree* L = 0;
  Tree* R = 0;
  int val = 0;
  Node node = Node();
  Tree(int l, int r) : l(l), r(r) {
    if (l != r - 1) {
      int m = (l + r) >> 1;
      L = new Tree(l, m);
      R = new Tree(m, r);
    }
    node.init(l, r);
  }
  void pushdown() {
    if (val) {
      L->val = val;
      R->val = val;
    }
  }
  void modify(int t, int v, int x) {
    if (v <= l || r <= t) return;
    if (t <= l && r <= v && val) {
      val = x;
      return;
    }
    if (l == r - 1) {
      val = x;
      return;
    }
    pushdown();
    L->modify(t, v, x);
    R->modify(t, v, x);
    val = L->val == R->val ? L->val : 0;
  }
  long long query(int t, int v, int x) {
    if (v <= l || r <= t) return 0;
    if (t <= l && r <= v && val) return node.query(x - val);
    if (l == r - 1) return min((long long)m1[l], s1[l] + (long long)r1[l] * x);
    pushdown();
    const auto a = L->query(t, v, x);
    const auto b = R->query(t, v, x);
    return a + b;
  }
};
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d%d%d", s1 + i, m1 + i, r1 + i);
  Tree root(1, n + 1);
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int x, l, r;
    scanf("%d%d%d", &x, &l, &r);
    const auto ans = root.query(l, r + 1, x);
    root.modify(l, r + 1, x);
    printf("%lld\n", ans);
  }
  return 0;
}
