#include <bits/stdc++.h>
using namespace std;
template <typename T>
int sz(const T& t) {
  return int(t.size());
}
template <typename T>
void setmax(T& a, T b) {
  if (b > a) a = b;
}
template <typename T>
void setmin(T& a, T b) {
  if (b < a) a = b;
}
template <int MOD_>
struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");

 private:
  using ll = long long;
  int v;
  static int minv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
  }

 public:
  modnum() : v(0) {}
  modnum(ll v_) : v(int(v_ % MOD)) {
    if (v < 0) v += MOD;
  }
  explicit operator int() const { return v; }
  friend std::ostream& operator<<(std::ostream& out, const modnum& n) {
    return out << int(n);
  }
  friend std::istream& operator>>(std::istream& in, modnum& n) {
    ll v_;
    in >> v_;
    n = modnum(v_);
    return in;
  }
  friend bool operator==(const modnum& a, const modnum& b) {
    return a.v == b.v;
  }
  friend bool operator!=(const modnum& a, const modnum& b) {
    return a.v != b.v;
  }
  modnum inv() const {
    modnum res;
    res.v = minv(v, MOD);
    return res;
  }
  friend modnum inv(const modnum& m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD - v : 0;
    return res;
  }
  friend modnum neg(const modnum& m) { return m.neg(); }
  modnum operator-() const { return neg(); }
  modnum operator+() const { return modnum(*this); }
  modnum& operator++() {
    v++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum& operator--() {
    if (v == 0) v = MOD;
    v--;
    return *this;
  }
  modnum& operator+=(const modnum& o) {
    v += o.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modnum& operator-=(const modnum& o) {
    v -= o.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modnum& operator*=(const modnum& o) {
    v = int(ll(v) * ll(o.v) % MOD);
    return *this;
  }
  modnum& operator/=(const modnum& o) { return *this *= o.inv(); }
  friend modnum operator++(modnum& a, int) {
    modnum r = a;
    ++a;
    return r;
  }
  friend modnum operator--(modnum& a, int) {
    modnum r = a;
    --a;
    return r;
  }
  friend modnum operator+(const modnum& a, const modnum& b) {
    return modnum(a) += b;
  }
  friend modnum operator-(const modnum& a, const modnum& b) {
    return modnum(a) -= b;
  }
  friend modnum operator*(const modnum& a, const modnum& b) {
    return modnum(a) *= b;
  }
  friend modnum operator/(const modnum& a, const modnum& b) {
    return modnum(a) /= b;
  }
};
template <typename T>
T pow(T a, long long b) {
  assert(b >= 0);
  T r = 1;
  while (b) {
    if (b & 1) r *= a;
    b >>= 1;
    a *= a;
  }
  return r;
}
using ll = long long;
const int S = 1 << 17;
ll lazy[2 * S];
ll seg[2 * S];
void updateNode(int i) {
  seg[i] = lazy[i] * (1 << (__builtin_clz(i) - __builtin_clz(S)));
  if (i < S) seg[i] += seg[2 * i] + seg[2 * i + 1];
}
void propogateNode(int i) {
  if (i < S) {
    lazy[2 * i] += lazy[i];
    lazy[2 * i + 1] += lazy[i];
    updateNode(2 * i);
    updateNode(2 * i + 1);
    lazy[i] = 0;
  }
}
void propogateAll(int i) {
  if (!i) return;
  propogateAll(i / 2);
  propogateNode(i);
}
void update(int l, int r, ll v) {
  for (int a = S + l, b = S + r; a < b; a /= 2, b /= 2) {
    if (a & 1) {
      lazy[a] += v;
      updateNode(a);
      a++;
    }
    if (b & 1) {
      --b;
      lazy[b] += v;
      updateNode(b);
    }
  }
  for (int a = S + l; a; a /= 2) updateNode(a);
  for (int b = S + r - 1; b; b /= 2) updateNode(b);
}
ll query(int l, int r) {
  propogateAll(S + l);
  propogateAll(S + r - 1);
  ll ans = 0;
  for (int a = S + l, b = S + r; a < b; a /= 2, b /= 2) {
    if (a & 1) ans += seg[a++];
    if (b & 1) ans += seg[--b];
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int N, M;
  cin >> N >> M;
  map<pair<int, int>, int> colors;
  for (int i = 0; i < N; i++) {
    colors[{i, i + 1}] = i + 1;
  }
  for (int q = 0; q < M; q++) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      l--;
      while (true) {
        auto it = colors.lower_bound({r, -1});
        if (it == colors.begin()) break;
        --it;
        if (it->first.second <= l) {
          break;
        }
        int curL = it->first.first;
        int curR = it->first.second;
        int curV = it->second;
        colors.erase(it);
        if (curR > r) {
          colors[{r, curR}] = curV;
          curR = r;
        }
        if (curL < l) {
          colors[{curL, l}] = curV;
          curL = l;
        }
        update(curL, curR, abs(x - curV));
      }
      colors[{l, r}] = x;
    } else if (t == 2) {
      int l, r;
      cin >> l >> r;
      l--;
      cout << query(l, r) << '\n';
    }
  }
  return 0;
}
