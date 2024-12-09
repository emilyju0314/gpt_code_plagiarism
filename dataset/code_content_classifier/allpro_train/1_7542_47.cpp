#include <bits/stdc++.h>
using namespace std;
template <typename T, typename V>
ostream &operator<<(ostream &os, const pair<T, V> pai) {
  return os << '(' << pai.first << ' ' << pai.second << ')';
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> v) {
  cout << '[';
  for (auto p : v) cout << p << ",";
  cout << "]";
  return os;
}
template <typename T, typename V>
ostream &operator<<(ostream &os, const set<T, V> v) {
  cout << "{";
  for (auto p : v) cout << p << ",";
  cout << "}";
  return os;
}
template <typename T, typename V>
ostream &operator<<(ostream &os, const map<T, V> v) {
  cout << "{";
  for (auto p : v) cout << p << ",";
  cout << "}";
  return os;
}
template <typename T>
void get_max(T &a, T b) {
  a = max(a, b);
}
template <typename T>
void get_min(T &a, T b) {
  a = min(a, b);
}
namespace SEG {
struct node {
  int state;
  int lcnt, rcnt, lrcnt;
  int lmax, rmax, lrmax;
  int totval;
};
ostream &operator<<(ostream &os, node a) {
  os << a.state << ' ';
  os << '(' << a.lcnt << ' ' << a.rcnt << ' ' << a.lrcnt << ") ";
  os << '(' << a.lmax << ' ' << a.rmax << ' ' << a.lrmax << ") ";
  os << a.totval;
  return os;
}
const int N = 1 << 18;
node tree[N << 1];
int lazy[N << 1];
node operator+(node a, node b) {
  if (a.state == 0 and b.state == 0) {
    return {0, 0, 0, a.lrcnt + b.lrcnt, 0, 0, max(a.lrmax, b.lrmax), 0};
  } else if (a.state == 0) {
    return {1,
            a.lrcnt + b.lcnt,
            b.rcnt,
            a.lrcnt + b.lrcnt,
            max(a.lrmax, b.lmax),
            b.rmax,
            max(a.lrmax, b.lrmax),
            b.totval};
  } else if (b.state == 0) {
    return {1,
            a.lcnt,
            a.rcnt + b.lrcnt,
            a.lrcnt + b.lrcnt,
            a.lmax,
            max(a.rmax, b.lrmax),
            max(a.lrmax, b.lrmax),
            a.totval};
  } else {
    return {1,
            a.lcnt,
            b.rcnt,
            a.lrcnt + b.lrcnt,
            a.lmax,
            b.rmax,
            max(a.lrmax, b.lrmax),
            a.totval + b.totval + a.rcnt + b.lcnt - max(a.rmax, b.lmax)};
  }
}
void init(int tN) {
  for (int i = 0, _i = (tN); i < _i; i++)
    tree[i + N] = {0, 0, 0, 1, 0, 0, 0, 0};
  for (int i = (N)-1, _i = (0); i >= _i; i--)
    tree[i] = tree[i << 1] + tree[i << 1 | 1];
}
void update(int p) {
  if (p < N)
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
  else
    tree[p] = {1, 0, 1, 1, 0, tree[p].lrmax, tree[p].lrmax, 0};
  if (lazy[p]) {
    tree[p] = {0, 0, 0, tree[p].lrcnt, 0, 0, tree[p].lrmax, 0};
  }
}
void update(int p, int v) {
  tree[p += N] = {0, 0, 0, 1, 0, 0, v, 0};
  while (p) update(p), p >>= 1;
}
void update(int l, int r, int v) {
  if (l > r) return;
  int sl = l += N, sr = r += N;
  while (l <= r) {
    if (l & 1) lazy[l] += v, update(l++);
    if (~r & 1) lazy[r] += v, update(r--);
    l >>= 1;
    r >>= 1;
  }
  while (sl) update(sl), sl >>= 1;
  while (sr) update(sr), sr >>= 1;
}
int query() {
  if (tree[1].state == 0) {
    return tree[1].lrcnt - tree[1].lrmax;
  } else {
    return tree[1].totval + tree[1].lcnt + tree[1].rcnt - tree[1].lmax -
           tree[1].rmax;
  }
}
}  // namespace SEG
int N, Q;
int A[200000];
int L[200001], R[200001];
set<int> occu[200001];
int main(void) {
  iostream::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> Q;
  SEG::init(N);
  for (int i = 0, _i = (N); i < _i; i++) {
    int t;
    cin >> t;
    A[i] = t;
    occu[t].insert(i);
  }
  for (int i = 0, _i = (200001); i < _i; i++)
    if (((int)(occu[i]).size()) > 0) {
      L[i] = *occu[i].begin();
      R[i] = *occu[i].rbegin();
      SEG::update(L[i], ((int)(occu[i]).size()));
      SEG::update(L[i] + 1, R[i], 1);
    }
  cout << SEG::query() << '\n';
  for (int i = 0, _i = (Q); i < _i; i++) {
    int p, v;
    cin >> p >> v;
    p--;
    int pv = A[p];
    SEG::update(L[pv] + 1, R[pv], -1);
    SEG::update(L[pv], 0);
    occu[pv].erase(p);
    if (((int)(occu[pv]).size()) > 0) {
      L[pv] = *occu[pv].begin();
      R[pv] = *occu[pv].rbegin();
      SEG::update(L[pv] + 1, R[pv], 1);
      SEG::update(L[pv], ((int)(occu[pv]).size()));
    }
    if (((int)(occu[v]).size()) > 0) {
      SEG::update(L[v] + 1, R[v], -1);
      SEG::update(L[v], 0);
    }
    occu[v].insert(p);
    L[v] = *occu[v].begin();
    R[v] = *occu[v].rbegin();
    SEG::update(L[v] + 1, R[v], 1);
    SEG::update(L[v], ((int)(occu[v]).size()));
    A[p] = v;
    cout << SEG::query() << '\n';
  }
}
