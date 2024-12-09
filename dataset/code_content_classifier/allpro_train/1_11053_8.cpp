#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-result"
using namespace std;
template <class T>
inline bool chkmax(T &a, const T &b) {
  return b > a ? a = b, true : false;
}
template <class T>
inline bool chkmin(T &a, const T &b) {
  return b < a ? a = b, true : false;
}
template <class T, class F = less<T>>
void sort_uniq(vector<T> &v, F f = F()) {
  sort(begin(v), end(v), f);
  v.resize(unique(begin(v), end(v)) - begin(v));
}
template <class T>
using MaxHeap = priority_queue<T>;
template <class T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
struct SegTreeRangeAsk {
  int n;
  vector<T> dat;
  template <typename F>
  void init(int id, int l, int r, F f) {
    if (l == r) {
      dat[id] = f(l);
      return;
    }
    int m = (l + r) / 2;
    init(id * 2, l, m, f);
    init(id * 2 + 1, m + 1, r, f);
    dat[id] = dat[id * 2] + dat[id * 2 + 1];
  }
  template <typename F>
  void init(int _n, F f) {
    n = _n;
    dat.resize(4 * (n + 1));
    init(1, 1, n, f);
  }
  void init(int _n, T *a) {
    init(_n, [a](int i) { return a[i]; });
  }
  void init(int _n, T val) {
    init(_n, [val](int) { return val; });
  }
  T ask(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return dat[id];
    int m = (l + r) / 2;
    if (qr <= m) return ask(id * 2, l, m, ql, qr);
    if (ql > m) return ask(id * 2 + 1, m + 1, r, ql, qr);
    T tl = ask(id * 2, l, m, ql, qr);
    T tr = ask(id * 2 + 1, m + 1, r, ql, qr);
    return tl + tr;
  }
  T ask(int l, int r) {
    assert(l <= r);
    return ask(1, 1, n, l, r);
  }
  void chg(int id, int l, int r, int qx, T qv) {
    if (l == r) {
      dat[id] = qv;
      return;
    }
    int m = (l + r) / 2;
    if (qx <= m)
      chg(id * 2, l, m, qx, qv);
    else
      chg(id * 2 + 1, m + 1, r, qx, qv);
    dat[id] = dat[id * 2] + dat[id * 2 + 1];
  }
  void chg(int qx, T qv) {
    assert(1 <= qx && qx <= n);
    chg(1, 1, n, qx, qv);
  }
};
int lcp(const string &a, const string &b) {
  int l = 0;
  while (l < ((int)(a).size()) && l < ((int)(b).size()) && a[l] == b[l]) l++;
  return l;
}
struct Max {
  int x;
  Max operator+(const Max &other) { return {max(x, other.x)}; }
};
SegTreeRangeAsk<Max> seg_len;
const int L = 64;
struct Lcp {
  int l, r, cl[L], cm[L], cr[L];
  int len() const { return r - l + 1; }
  int eval() const {
    int mx = 0;
    for (int i = 0; i < int(L); i++)
      if (cm[i]) chkmax(mx, (i + 1) * (cm[i] + 1));
    return mx;
  }
};
Lcp operator+(const Lcp &a, const Lcp &b) {
  Lcp c;
  c.l = a.l;
  c.r = b.r;
  int na = a.len(), nb = b.len();
  for (int i = 0; i < int(L); i++) {
    c.cl[i] = (a.cl[i] < na ? a.cl[i] : na + b.cl[i]);
    c.cr[i] = (b.cr[i] < nb ? b.cr[i] : nb + a.cr[i]);
    c.cm[i] = max({a.cm[i], b.cm[i], a.cr[i] + b.cl[i]});
  }
  return c;
}
SegTreeRangeAsk<Lcp> seg_lcp;
const int N = 1e5 + 10;
int n, m, h[N];
string s[N];
Max gen_max(int i) { return Max{((int)(s[i]).size())}; }
Lcp gen_lcp(int p) {
  Lcp x;
  x.l = x.r = p;
  for (int i = 0; i < int(L); i++) x.cl[i] = x.cm[i] = x.cr[i] = (i < h[p]);
  return x;
}
set<int> ls;
int solve_ls(int l, int r) {
  vector<int> v;
  auto it = ls.lower_bound(l);
  while (it != ls.end() && *it <= r) v.push_back(*it++);
  vector<int> a;
  for (int i = 0; i < int(((int)(v).size())); i++) {
    if (i > 0 && v[i] != v[i - 1] + 1) a.push_back(0);
    a.push_back(h[v[i]]);
  }
  a.push_back(0);
  int ans = 0;
  vector<int> stk;
  for (int i = 0; i < int(((int)(a).size())); i++) {
    while (!stk.empty() && a[stk.back()] >= a[i]) {
      int x = stk.back();
      stk.pop_back();
      int lb = stk.empty() ? 0 : stk.back() + 1;
      int rb = i - 1;
      int now = a[x] * (rb - lb + 2);
      chkmax(ans, now);
    }
    stk.push_back(i);
  }
  return ans;
}
void solve_1() {
  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r;
      cin >> l >> r;
      cout << ((int)(s[1]).size()) << '\n';
    } else if (op == 2) {
      int x;
      cin >> x;
      cin >> s[x];
    } else
      assert(0);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = (1); i <= int(n); i++) cin >> s[i];
  if (n == 1) {
    solve_1();
    return 0;
  }
  for (int i = (1); i <= int(n - 1); i++) h[i] = lcp(s[i], s[i + 1]);
  seg_len.init(n, gen_max);
  seg_lcp.init(n - 1, gen_lcp);
  for (int i = (1); i <= int(n - 1); i++)
    if (h[i] > L) ls.insert(i);
  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r;
      cin >> l >> r;
      int ans = 0;
      auto qlen = seg_len.ask(l, r);
      chkmax(ans, qlen.x);
      ;
      if (l < r) {
        auto qlcp = seg_lcp.ask(l, r - 1);
        chkmax(ans, qlcp.eval());
        auto qls = solve_ls(l, r - 1);
        chkmax(ans, qls);
        ;
      }
      cout << ans << '\n';
    } else if (op == 2) {
      int x;
      cin >> x;
      cin >> s[x];
      seg_len.chg(x, gen_max(x));
      if (x - 1 >= 1) {
        h[x - 1] = lcp(s[x - 1], s[x]);
        seg_lcp.chg(x - 1, gen_lcp(x - 1));
        if (h[x - 1] <= L)
          ls.erase(x - 1);
        else
          ls.insert(x - 1);
      }
      if (x + 1 <= n) {
        h[x] = lcp(s[x], s[x + 1]);
        seg_lcp.chg(x, gen_lcp(x));
        if (h[x] <= L)
          ls.erase(x);
        else
          ls.insert(x);
      }
    } else
      assert(0);
  }
  return 0;
}
