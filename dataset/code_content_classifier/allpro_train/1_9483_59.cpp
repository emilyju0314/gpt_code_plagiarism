#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} debug1;
template <typename T1, typename T2>
inline ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
inline ostream& operator<<(ostream& os, const vector<T>& v) {
  bool first = true;
  os << "[";
  for (typename vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
    if (!first) os << ", ";
    os << *ii;
    first = false;
  }
  return os << "]";
}
const int NN = 112345;
const int inf = ((1 << 30) - 1);
int seg[3 * NN], lazy[3 * NN];
void pushup(int node) { seg[node] = (seg[2 * node] & seg[2 * node + 1]); }
void pushdown(int node, int st, int en) {
  if (!lazy[node]) return;
  seg[node] = (seg[node] | lazy[node]);
  if (st != en) {
    lazy[2 * node] = lazy[2 * node] | lazy[node];
    lazy[2 * node + 1] = lazy[2 * node + 1] | lazy[node];
  }
  lazy[node] = 0;
}
void update(int node, int st, int en, int L, int R, int vv) {
  pushdown(node, st, en);
  if (st > R or en < L) return;
  if (st >= L and en <= R) {
    lazy[node] = (lazy[node] | vv);
    pushdown(node, st, en);
    ;
    return;
  }
  int mid = (st + en) / 2;
  update(2 * node, st, mid, L, R, vv);
  update(2 * node + 1, mid + 1, en, L, R, vv);
  pushup(node);
}
int query(int node, int st, int en, int L, int R) {
  pushdown(node, st, en);
  if (st > R or en < L) return ((1 << 30) - 1);
  if (st >= L and en <= R) {
    ;
    return seg[node];
  }
  int mid = (st + en) / 2;
  int ans = ((1 << 30) - 1);
  ans = ans & query(2 * node, st, mid, L, R);
  ans = ans & query(2 * node + 1, mid + 1, en, L, R);
  return ans;
}
pair<int, pair<int, int> > q[NN];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i)
    cin >> q[i].second.first >> q[i].second.second >> q[i].first;
  for (int i = 0; i < m; ++i)
    update(1, 0, n - 1, q[i].second.first - 1, q[i].second.second - 1,
           q[i].first);
  for (int i = 0; i < m; ++i) {
    int num = query(1, 0, n - 1, q[i].second.first - 1, q[i].second.second - 1);
    ;
    if (num != q[i].first) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    int num = query(1, 0, n - 1, i, i);
    cout << num << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  solve();
  return 0;
}
