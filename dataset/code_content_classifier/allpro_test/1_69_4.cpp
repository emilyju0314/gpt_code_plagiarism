#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
struct Fib {
  long long a, b;
  Fib operator+(const Fib& o) const {
    return {(a + o.a) % MOD, (b + o.b) % MOD};
  }
};
struct FibOp {
  long long a, b, c, d;
  FibOp operator()(const FibOp& o) const {
    FibOp res = {a * o.a + b * o.c, a * o.b + b * o.d, c * o.a + d * o.c,
                 c * o.b + d * o.d};
    res.a %= MOD;
    ;
    res.b %= MOD;
    ;
    res.c %= MOD;
    ;
    res.d %= MOD;
    ;
    return res;
  }
  Fib operator()(const Fib& f) const {
    Fib res = {a * f.a + b * f.b, c * f.a + d * f.b};
    res.a %= MOD;
    ;
    res.b %= MOD;
    ;
    return res;
  }
};
const long long K = 32;
FibOp pwr[K];
FibOp negpwr[K];
Fib zero = {0, 1};
void setup() {
  pwr[0] = {1, 1, 1, 0};
  negpwr[0] = {0, 1, 1, MOD - 1};
  for (int i = 1; i < K; ++i) {
    pwr[i] = pwr[i - 1](pwr[i - 1]);
    negpwr[i] = negpwr[i - 1](negpwr[i - 1]);
  }
}
Fib FibMult(Fib f, long long cnt, FibOp p[K]) {
  for (int r = K - 1; r >= 0; --r) {
    if (cnt & (1LL << r)) {
      f = p[r](f);
    }
  }
  return f;
}
Fib FibMult(Fib f, long long cnt) {
  return (cnt >= 0 ? FibMult(f, cnt, pwr) : FibMult(f, -cnt, negpwr));
}
struct Node {
  long long lo[2] = {0, 0};
  long long hi[2] = {0, 0};
  long long add[2] = {0, 0};
  long long sz = 1;
  Fib f;
  void apply(long long a[2]) {
    for (int i = 0; i < 2; ++i) {
      add[i] += a[i];
      lo[i] += a[i];
      hi[i] += a[i];
    }
    f = FibMult(f, a[0] + a[1]);
  }
};
struct Segtree {
  vector<Node> t;
  int n, h;
  Segtree(int sz) {
    h = 32 - __builtin_clz(sz);
    n = 1 << h;
    t = vector<Node>(n << 1);
    for (int i = n - 1; i > 0; --i) {
      t[i].sz = t[i * 2].sz + t[i * 2 + 1].sz;
    }
  }
  void push(int x) {
    if (!t[x].add[0] && !t[x].add[1]) {
      return;
    }
    assert(x < n);
    t[x << 1].apply(t[x].add);
    t[x << 1 | 1].apply(t[x].add);
    t[x].add[0] = 0;
    t[x].add[1] = 0;
  }
  void pull(int x) {
    for (int i = 0; i < 2; ++i) {
      t[x].lo[i] = min(t[x * 2].lo[i], t[x * 2 + 1].lo[i]);
      t[x].hi[i] = max(t[x * 2].hi[i], t[x * 2 + 1].hi[i]);
    }
    t[x].f = t[x << 1].f + t[x << 1 | 1].f;
    t[x].apply(t[x].add);
  }
  void set_init(int x, int k, int va) {
    x += n;
    t[x].lo[k] = t[x].hi[k] = va;
    t[x].f = FibMult(zero, t[x].lo[0] + t[x].lo[1]);
    for (x /= 2; x; x /= 2) {
      pull(x);
    }
  }
  long long query(int l, int r, int x, int lv, int rv) {
    if (r <= lv || rv <= l) {
      return 0;
    }
    if (l <= lv && rv <= r) {
      return t[x].f.a;
    }
    push(x);
    int mv = (lv + rv) / 2;
    long long ans = 0;
    ans += query(l, r, x * 2, lv, mv);
    ans += query(l, r, x * 2 + 1, mv, rv);
    return ans % MOD;
  }
  long long query(int l, int r) { return query(l, r, 1, 0, n); }
  void add(int l, int r, int k, long long va, int x, int lv, int rv) {
    if (r <= lv || rv <= l) {
      return;
    }
    if (l <= lv && rv <= r) {
      long long a[2] = {0, 0};
      a[k] = va;
      t[x].apply(a);
      return;
    }
    push(x);
    int mv = (lv + rv) / 2;
    add(l, r, k, va, x * 2, lv, mv);
    add(l, r, k, va, x * 2 + 1, mv, rv);
    pull(x);
  }
  void add(int l, int r, int k, long long va) { add(l, r, k, va, 1, 0, n); }
  void minupdate(int l, int r, int k, long long va, int x, int lv, int rv) {
    if (r <= lv || rv <= l) {
      return;
    }
    if (t[x].hi[k] <= va) {
      return;
    }
    if (l <= lv && rv <= r && t[x].lo[k] == t[x].hi[k]) {
      long long a[2] = {0, 0};
      a[k] = va - t[x].lo[k];
      t[x].apply(a);
      return;
    }
    push(x);
    int mv = (lv + rv) / 2;
    minupdate(l, r, k, va, x * 2, lv, mv);
    minupdate(l, r, k, va, x * 2 + 1, mv, rv);
    pull(x);
  }
  void minupdate(int l, int r, int k, long long va) {
    return minupdate(l, r, k, va, 1, 0, n);
  }
  void maxupdate(int l, int r, int k, long long va, int x, int lv, int rv) {
    if (r <= lv || rv <= l) {
      return;
    }
    if (t[x].lo[k] >= va) {
      return;
    }
    if (l <= lv && rv <= r && t[x].lo[k] == t[x].hi[k]) {
      long long a[2] = {0, 0};
      a[k] = va - t[x].lo[k];
      t[x].apply(a);
      return;
    }
    push(x);
    int mv = (lv + rv) / 2;
    maxupdate(l, r, k, va, x * 2, lv, mv);
    maxupdate(l, r, k, va, x * 2 + 1, mv, rv);
    pull(x);
  }
  void maxupdate(int l, int r, int k, long long va) {
    return maxupdate(l, r, k, va, 1, 0, n);
  }
};
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  setup();
  int n, q;
  cin >> n >> q;
  Segtree st(n + 10);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    st.set_init(i, 0, x);
  }
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    st.set_init(i, 1, x);
  }
  for (int _i = 0; _i < q; ++_i) {
    int type;
    cin >> type;
    if (type == 1) {
      int k, l, r, x;
      cin >> k >> l >> r >> x;
      --k;
      st.minupdate(l, r + 1, k, x);
    } else if (type == 2) {
      int k, l, r, x;
      cin >> k >> l >> r >> x;
      --k;
      st.maxupdate(l, r + 1, k, x);
    } else if (type == 3) {
      int k, l, r, x;
      cin >> k >> l >> r >> x;
      --k;
      st.add(l, r + 1, k, x);
    } else if (type == 4) {
      int l, r;
      cin >> l >> r;
      cout << st.query(l, r + 1) << "\n";
    }
  }
  return 0;
}
