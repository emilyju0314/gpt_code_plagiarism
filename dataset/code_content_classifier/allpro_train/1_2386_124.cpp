#include <bits/stdc++.h>
using namespace std;
template <class T>
using vv = vector<vector<T>>;
template <class T>
ostream &operator<<(ostream &os, const vector<T> &t) {
  os << "{";
  for (int(i) = 0; (i) < (t.size()); ++(i)) {
    os << t[i] << ",";
  }
  os << "}" << endl;
  return os;
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &t) {
  return os << "(" << t.first << "," << t.second << ")";
}
const long long MOD = 1e9 + 9;
const int N = (1 << 17), r = 11451;
struct Seg {
  long long h, q, r;
  Seg(int v = 0) {
    h = v;
    q = 0;
    r = (v ? ::r : 1);
  }
  void comp(const Seg &ope) { q = ope.q; }
  void clear() { q = 0; }
  static Seg Ope(int v = 0) {
    Seg re;
    re.q = v;
    return re;
  }
  static Seg e;
};
Seg Seg::e = Seg();
ostream &operator<<(ostream &os, const Seg &t) {
  return os << "(" << t.h << "," << t.q << "," << t.r << ")";
}
Seg seg[2 * N + 10];
Seg operator+(const Seg l, const Seg r) {
  Seg re;
  re.h = (l.h * r.r % MOD + r.h) % MOD;
  re.r = l.r * r.r % MOD;
  return re;
}
vector<long long> ser(N);
inline void lazy_eval(int k, int a, int b) {
  if (!seg[k].q) return;
  seg[k].h = seg[k].q * ser[b - a - 1] % MOD;
  if (2 * k <= 2 * N + 5) {
    seg[2 * k + 1].comp(seg[k]);
    seg[2 * k + 2].comp(seg[k]);
  }
  seg[k].clear();
}
inline void update_node(int k) { seg[k] = seg[2 * k + 1] + seg[2 * k + 2]; }
void update(int l, int r, Seg ope, int k = 0, int a = 0, int b = N) {
  lazy_eval(k, a, b);
  if (b <= l || r <= a) return;
  if (l <= a && b <= r) {
    seg[k].comp(ope);
    lazy_eval(k, a, b);
    return;
  }
  int m = (a + b) / 2;
  update(l, r, ope, 2 * k + 1, a, m);
  update(l, r, ope, 2 * k + 2, m, b);
  update_node(k);
}
Seg get(int l, int r, int k = 0, int a = 0, int b = N) {
  lazy_eval(k, a, b);
  if (b <= l || r <= a) return Seg::e;
  if (l <= a && b <= r) {
    return seg[k];
  }
  int m = (a + b) / 2;
  Seg vl = get(l, r, 2 * k + 1, a, m);
  Seg vr = get(l, r, 2 * k + 2, m, b);
  update_node(k);
  return vl + vr;
}
int main() {
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(0);
  ser[0] = 1;
  for (int(i) = 0; (i) < (N - 1); ++(i))
    ser[i + 1] = (1 + ser[i] * r % MOD) % MOD;
  int n, m, t;
  cin >> n >> m >> t;
  string str;
  cin >> str;
  int a, l, r, x;
  for (int(i) = 0; (i) < (n); ++(i)) seg[(1 << 17) - 1 + i] = Seg(str[i]);
  for (int(i) = ((1 << 17) - 1) - 1; (i) >= 0; --(i)) update_node(i);
  for (int(i) = 0; (i) < (t + m); ++(i)) {
    cin >> a >> l >> r >> x;
    --l;
    if (a == 1) {
      update(l, r, Seg::Ope(x + '0'));
    } else {
      cout << (get(l, r - x).h == get(l + x, r).h ? "YES" : "NO") << endl;
    }
  }
  return 0;
}
