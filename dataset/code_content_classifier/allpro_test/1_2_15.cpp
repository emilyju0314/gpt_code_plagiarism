#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
const int MOD = 1e9 + 7;
using ll = long long;
const double PI = acos(-1.0);
namespace fft {
struct num {
  double x, y;
  num() { x = y = 0; }
  num(double x, double y) : x(x), y(y) {}
};
inline num operator+(num a, num b) { return num(a.x + b.x, a.y + b.y); }
inline num operator-(num a, num b) { return num(a.x - b.x, a.y - b.y); }
inline num operator*(num a, num b) {
  return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
inline num conj(num a) { return num(a.x, -a.y); }
int base = 1;
vector<num> roots = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};
const double PI = acosl(-1.0);
void ensure_base(int nbase) {
  if (nbase <= base) return;
  rev.resize(1 << nbase);
  for (int i = 0; i < (1 << nbase); i++)
    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
  roots.resize(1 << nbase);
  while (base < nbase) {
    double angle = 2 * PI / (1 << (base + 1));
    for (int i = 1 << (base - 1); i < (1 << base); i++) {
      roots[i << 1] = roots[i];
      double angle_i = angle * (2 * i + 1 - (1 << base));
      roots[(i << 1) + 1] = num(cos(angle_i), sin(angle_i));
    }
    base++;
  }
}
void fft(vector<num> &a, int n = -1) {
  if (n == -1) n = a.size();
  assert((n & (n - 1)) == 0);
  int zeros = __builtin_ctz(n);
  ensure_base(zeros);
  int shift = base - zeros;
  for (int i = 0; i < n; i++)
    if (i < (rev[i] >> shift)) swap(a[i], a[rev[i] >> shift]);
  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; j++) {
        num z = a[i + j + k] * roots[j + k];
        a[i + j + k] = a[i + j] - z;
        a[i + j] = a[i + j] + z;
      }
    }
  }
}
vector<num> fa, fb;
vector<int> multiply(vector<int> &a, vector<int> &b) {
  int need = a.size() + b.size() - 1;
  int nbase = 0;
  while ((1 << nbase) < need) nbase++;
  ensure_base(nbase);
  int sz = 1 << nbase;
  if (sz > (int)fa.size()) fa.resize(sz);
  for (int i = 0; i < sz; i++) {
    int x = (i < (int)a.size() ? a[i] : 0);
    int y = (i < (int)b.size() ? b[i] : 0);
    fa[i] = num(x, y);
  }
  fft(fa, sz);
  num r(0, -0.25 / sz);
  for (int i = 0; i <= (sz >> 1); i++) {
    int j = (sz - i) & (sz - 1);
    num z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
    if (i != j) fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
    fa[i] = z;
  }
  fft(fa, sz);
  vector<int> res(need);
  for (int i = 0; i < need; i++) res[i] = fa[i].x + 0.5;
  return res;
}
vector<int> multiply_mod(vector<int> &a, vector<int> &b, int m, int eq = 0) {
  int need = a.size() + b.size() - 1;
  int nbase = 0;
  while ((1 << nbase) < need) nbase++;
  ensure_base(nbase);
  int sz = 1 << nbase;
  if (sz > (int)fa.size()) fa.resize(sz);
  for (int i = 0; i < (int)a.size(); i++) {
    int x = (a[i] % m + m) % m;
    fa[i] = num(x & ((1 << 15) - 1), x >> 15);
  }
  fill(fa.begin() + a.size(), fa.begin() + sz, num{0, 0});
  fft(fa, sz);
  if (sz > (int)fb.size()) fb.resize(sz);
  if (eq)
    copy(fa.begin(), fa.begin() + sz, fb.begin());
  else {
    for (int i = 0; i < (int)b.size(); i++) {
      int x = (b[i] % m + m) % m;
      fb[i] = num(x & ((1 << 15) - 1), x >> 15);
    }
    fill(fb.begin() + b.size(), fb.begin() + sz, num{0, 0});
    fft(fb, sz);
  }
  double ratio = 0.25 / sz;
  num r2(0, -1), r3(ratio, 0), r4(0, -ratio), r5(0, 1);
  for (int i = 0; i <= (sz >> 1); i++) {
    int j = (sz - i) & (sz - 1);
    num a1 = (fa[i] + conj(fa[j]));
    num a2 = (fa[i] - conj(fa[j])) * r2;
    num b1 = (fb[i] + conj(fb[j])) * r3;
    num b2 = (fb[i] - conj(fb[j])) * r4;
    if (i != j) {
      num c1 = (fa[j] + conj(fa[i]));
      num c2 = (fa[j] - conj(fa[i])) * r2;
      num d1 = (fb[j] + conj(fb[i])) * r3;
      num d2 = (fb[j] - conj(fb[i])) * r4;
      fa[i] = c1 * d1 + c2 * d2 * r5;
      fb[i] = c1 * d2 + c2 * d1;
    }
    fa[j] = a1 * b1 + a2 * b2 * r5;
    fb[j] = a1 * b2 + a2 * b1;
  }
  fft(fa, sz);
  fft(fb, sz);
  vector<int> res(need);
  for (int i = 0; i < need; i++) {
    ll aa = fa[i].x + 0.5;
    ll bb = fb[i].x + 0.5;
    ll cc = fa[i].y + 0.5;
    res[i] = (aa + ((bb % m) << 15) + ((cc % m) << 30)) % m;
  }
  return res;
}
vector<int> square_mod(vector<int> &a, int m) {
  return multiply_mod(a, a, m, 1);
}
};  // namespace fft
const int maxn = 4e5 + 233;
int value[maxn];
int n, m, k;
int pre[maxn];
void add(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
void sub(int &x, int y) {
  x -= y;
  if (x < 0) x += MOD;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i += 1) {
    cin >> value[i];
    value[i] %= k;
  }
  int sum = 0;
  vector<int> a(k), b(k);
  for (int i = 1; i <= n; i += 1) {
    sum = (sum + value[i]) % k;
    a[sum] += 1;
  }
  sum = 0;
  for (int i = n; i >= 1; i -= 1) {
    sum = (sum + value[i]) % k;
    b[sum] += 1;
  }
  auto c = fft::multiply_mod(a, b, MOD);
  for (int i = k; i < c.size(); i += 1) {
    add(c[i % k], c[i]);
  }
  int res = 0;
  for (int i = 0; i <= m - 2; i += 1) {
    int rem = (k - 1ll * sum * i % k) % k;
    add(res, 1ll * m * c[rem] % MOD);
  }
  if (1ll * m * sum % k == 0) {
    sub(res, m - 1);
  }
  int all = 0;
  pre[0] = 1;
  for (int i = n; i >= 1; i -= 1) {
    all = (all + value[i]) % k;
    pre[all] += 1;
  }
  for (int i = 1; i <= n; i += 1) {
    pre[all] -= 1;
    add(res, 1ll * pre[all] * m % MOD);
    all = (all + k - value[i] % k) % k;
  }
  memset(pre, 0, sizeof(pre));
  all = 0;
  for (int i = n; i > 1; i -= 1) {
    all = (all + value[i]) % k;
    pre[all] += 1;
  }
  int cur = 0;
  for (int i = 1; i <= n; i += 1) {
    if (i < n) {
      pre[all] -= 1;
      all = (all + k - value[i + 1] % k) % k;
    }
    cur = (cur + value[i]) % k;
    int rem = (2 * k - 1ll * sum * (m - 1) % k - cur) % k;
    add(res, 1ll * m * pre[rem] % MOD);
  }
  cout << res << "\n";
  return 0;
}
