#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long double PI = acos(-1.0L);
const long long MOD = 998244353LL;
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
struct LazySegmentTree {
  const T inf = numeric_limits<T>::max() / 2;
  int N, h;
  vector<T> node1, node2, lazy;
  LazySegmentTree() = default;
  LazySegmentTree(vector<T> &v) { init(v); }
  void init(vector<T> &v) {
    int sz = v.size();
    N = 1;
    h = 0;
    while (N < sz) {
      N *= 2;
      h++;
    }
    node1.assign(2 * N, inf);
    node2.assign(2 * N, -inf);
    lazy.assign(2 * N, 0);
    for (int i = 0; i < sz; i++) node1[i + N] = node2[i + N] = v[i];
    for (int i = N - 1; i >= 1; i--) {
      node1[i] = min(node1[i << 1 | 0], node1[i << 1 | 1]);
      node2[i] = max(node2[i << 1 | 0], node2[i << 1 | 1]);
    }
  }
  void eval(int k) {
    if (lazy[k] != 0) {
      node1[k] += lazy[k];
      node2[k] += lazy[k];
      if (k < N) {
        lazy[k << 1 | 0] += lazy[k];
        lazy[k << 1 | 1] += lazy[k];
      }
      lazy[k] = 0;
    }
  }
  void update(int l, int r, T val) {
    l += N;
    r += N - 1;
    for (int i = h; i > 0; i--) {
      eval(l >> i);
      eval(r >> i);
    }
    int a = l;
    int b = r++;
    while (l < r) {
      if (l & 1) lazy[l++] += val;
      if (r & 1) lazy[--r] += val;
      l >>= 1;
      r >>= 1;
    }
    while (a >>= 1, b >>= 1, a) {
      if (lazy[a] == 0) {
        eval(a << 1 | 0);
        eval(a << 1 | 1);
        node1[a] = min(node1[a << 1 | 0], node1[a << 1 | 1]);
        node2[a] = max(node2[a << 1 | 0], node2[a << 1 | 1]);
      }
      if (lazy[b] == 0) {
        eval(b << 1 | 0);
        eval(b << 1 | 1);
        node1[b] = min(node1[b << 1 | 0], node1[b << 1 | 1]);
        node2[b] = max(node2[b << 1 | 0], node2[b << 1 | 1]);
      }
    }
  }
  T getmin(int l, int r) {
    T res = inf;
    l += N;
    r += N - 1;
    for (int i = h; i > 0; i--) {
      eval(l >> i);
      eval(r >> i);
    }
    r++;
    while (l < r) {
      if (l & 1) {
        eval(l);
        chmin(res, node1[l++]);
      }
      l >>= 1;
      if (r & 1) {
        eval(--r);
        chmin(res, node1[r]);
      }
      r >>= 1;
    }
    return res;
  }
  T getmax(int l, int r) {
    T res = -inf;
    l += N;
    r += N - 1;
    for (int i = h; i > 0; i--) {
      eval(l >> i);
      eval(r >> i);
    }
    r++;
    while (l < r) {
      if (l & 1) {
        eval(l);
        chmax(res, node2[l++]);
      }
      l >>= 1;
      if (r & 1) {
        eval(--r);
        chmax(res, node2[r]);
      }
      r >>= 1;
    }
    return res;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<int> A(N + 5);
  LazySegmentTree<int> sg(A);
  int cur = 0;
  for (int i = 0; i < (int)(N); i++) {
    if (S[i] == '(') {
      sg.update(cur, N + 5, 1 - A[cur]);
      A[cur] = 1;
    } else if (S[i] == ')') {
      sg.update(cur, N + 5, -1 - A[cur]);
      A[cur] = -1;
    } else if (S[i] == 'R')
      cur++;
    else if (S[i] == 'L') {
      if (cur > 0) cur--;
    } else {
      sg.update(cur, N + 5, -A[cur]);
      A[cur] = 0;
    }
    if (sg.getmin(N + 3, N + 4) != 0 || sg.getmin(0, N + 5) < 0)
      cout << -1 << " ";
    else
      cout << sg.getmax(0, N + 5) << " ";
  }
  cout << endl;
}
