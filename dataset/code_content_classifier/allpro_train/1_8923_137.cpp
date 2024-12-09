#include <bits/stdc++.h>
using namespace std;
const double PI = atan(1.0) * 4;
const long long int INF = 100000000000000003;
const int32_t LOG = 21;
long long int a[100005];
long long int ans_ind = -1;
vector<long long int> start[100005];
vector<long long int> ending[100005];
long long int l[305], r[305];
vector<long long int> v;
class Segment {
  long long int n, *seg1, *seg2, *lazy;

 public:
  Segment(long long int n, long long int size) {
    seg1 = new long long int[size];
    seg2 = new long long int[size];
    lazy = new long long int[size];
    fill(lazy, lazy + size, 0);
    this->n = n;
  }
  inline void build(long long int v, long long int tl, long long int tr) {
    if (tl == tr)
      seg1[v] = seg2[v] = a[tl];
    else {
      long long int tm = (tl + tr) / 2;
      build(v * 2, tl, tm);
      build(v * 2 + 1, tm + 1, tr);
      seg1[v] = max(seg1[v * 2], seg1[v * 2 + 1]);
      seg2[v] = min(seg2[v * 2], seg2[v * 2 + 1]);
    }
  }
  inline void push(long long int v) {
    seg1[v * 2] += lazy[v];
    seg2[v * 2] += lazy[v];
    seg1[v * 2 + 1] += lazy[v];
    seg2[v * 2 + 1] += lazy[v];
    lazy[v * 2] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
  }
  inline void update(long long int v, long long int tl, long long int tr,
                     long long int l, long long int r, long long int inc) {
    if (l > r) return;
    if (l == tl && r == tr) {
      seg1[v] += inc;
      seg2[v] += inc;
      lazy[v] += inc;
    } else {
      push(v);
      long long int tm = (tl + tr) / 2;
      update(v * 2, tl, tm, l, min(r, tm), inc);
      update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, inc);
      seg1[v] = max(seg1[v * 2], seg1[v * 2 + 1]);
      seg2[v] = min(seg2[v * 2], seg2[v * 2 + 1]);
    }
  }
  pair<long long int, long long int> query(long long int v, long long int tl,
                                           long long int tr, long long int l,
                                           long long int r) {
    if (l > r) return {-INF, INF};
    if (l <= tl && tr <= r) return {seg1[v], seg2[v]};
    push(v);
    long long int tm = (tl + tr) / 2;
    pair<long long int, long long int> q1 = query(v * 2, tl, tm, l, min(r, tm));
    pair<long long int, long long int> q2 =
        query(v * 2, tm + 1, tr, max(l, tm + 1), tr);
    long long int max1 = max(q1.first, q2.first);
    long long int min1 = min(q1.second, q2.second);
    return {max1, min1};
  }
};
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  long long int max1 = -INF;
  long long int min1 = INF;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    max1 = max(max1, a[i]);
    min1 = min(min1, a[i]);
  }
  Segment seg_tree(n, 400005);
  seg_tree.build(1, 0, n - 1);
  for (long long int i = 0; i < m; i++) {
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
    start[l[i]].push_back(r[i]);
    ending[r[i]].push_back(l[i]);
    seg_tree.update(1, 0, n - 1, l[i], r[i], -1);
  }
  long long int ans = max1 - min1;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < start[i].size(); j++) {
      seg_tree.update(1, 0, n - 1, i, start[i][j], 1);
    }
    pair<long long int, long long int> res =
        seg_tree.query(1, 0, n - 1, 0, n - 1);
    long long int temp = max(res.first, a[i]) - min(res.second, a[i]);
    if (ans < temp) {
      ans = temp;
      ans_ind = i;
    }
    for (long long int j = 0; j < ending[i].size(); j++) {
      seg_tree.update(1, 0, n - 1, ending[i][j], i, -1);
    }
  }
  if (ans_ind == -1) {
    cout << ans << endl;
    cout << 0 << endl;
    return 0;
  }
  for (long long int i = 0; i < m; i++) {
    if (r[i] < ans_ind || ans_ind < l[i]) v.push_back(i + 1);
  }
  cout << ans << endl;
  cout << v.size() << endl;
  for (long long int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
  return 0;
}
