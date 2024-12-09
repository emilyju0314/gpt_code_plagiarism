#include <bits/stdc++.h>
using namespace std;
 
struct BinaryIndexedTree {
  BinaryIndexedTree(int n) : n(n + 1), v(n + 2, 0), r(1 << (31 - __builtin_clz(n + 1))) {}

  vector<int> v;
  int n, r;

  int sum(int i) {
    ++i;
    int ret = 0;
    while (i) {
      ret += v[i];
      i -= i & -i;
    }
    return ret;
  }

  void add(int i, int x) {
    ++i;
    while (i <= n) {
      v[i] += x;
      i += i & -i;
    }
  }

  int lower_bound(int w) {
    int idx = 0;
    for (int k = r; k > 0; k /= 2) {
      if (idx + k <= n && v[idx + k] < w) {
        w -= v[idx + k];
        idx += k;
      }
    }

    return idx;
  }
};


struct segtree {
  segtree() {}
  segtree(int n, vector<char> v) : n(n) { init(v); }
 
  pair<char, int> id = make_pair('{', -1);
  int n;
  vector<pair<char, int>> node;
 
  void init(vector<char> v) {
    int n_ = n;
    n = 1;
    while (n < n_)
      n *= 2;
 
    node.assign(2 * n - 1, id);
    for (int i = 0; i < v.size(); ++i) {
      int idx = i + n - 1;
      node[idx] = make_pair(v[i], i);
    }
    for (int i = n - 2; i >= 0; --i) {
      node[i] = min(node[2 * i + 1], node[2 * i + 2]);
    }
  }
 
  pair<char, int> find(int a, int b, int k, int l, int r) {
    if (b <= l || r <= a)
      return id;
    if (a <= l && r <= b)
      return node[k];
 
    return min(find(a, b, 2 * k + 1, l, (l + r) / 2),
               find(a, b, 2 * k + 2, (l + r) / 2, r));
  }
 
  pair<char, int> find(int a, int b) { return find(a, b, 0, 0, n); }
 
  void update(int k) {
    k += n - 1;
    node[k] = id;
    while (k) {
      k = (k - 1) / 2;
      node[k] = min(node[2 * k + 1], node[2 * k + 2]);
    }
  }
};
 
int main() {
  string s;
  int k;
 
  cin >> s >> k;
  vector<char> v(s.size());
  for (int i = 0; i < s.size(); ++i)
    v[i] = s[i];
 
  BinaryIndexedTree bit(s.size());
  segtree seg(s.size(), v);
 
  for (int i = 0; i < s.size(); ++i)
    bit.add(i, 1);
 
  string ans;
  for (int i = 0; i < s.size(); ++i) {
    int r = bit.lower_bound(k + 1);
    pair<char, int> c = seg.find(0, r + 1);
    seg.update(c.second);
    bit.add(c.second, -1);
    k -= bit.sum(c.second);
 
    ans.push_back(c.first);
  }
 
  cout << ans << endl;
}