#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
namespace mypoly {
const int MOD = 998244353;
const int g = 3;
int qmul(int x, int y) { return 1ll * x * y - 1ll * x * y / MOD * MOD; }
int qadd(int x, int y) { return x + y >= MOD ? x + y - MOD : x + y; }
int G[21][(1 << 20) + 1], R[21][(1 << 20) + 1], inver[(1 << 20) + 1];
int quick(int A, int B) {
  int res = 1;
  while (B) {
    if (B & 1) res = qmul(res, A);
    A = qmul(A, A);
    B >>= 1;
  }
  return res;
}
int inv(int x) { return quick(x, MOD - 2); }
struct POLY {
  int len;
  int rev[1 << 20];
  POLY() {
    for (int i = 1; i <= (1 << 20); ++i) inver[i] = inv(i);
    for (int i = 1; i <= 20; ++i) {
      G[i][0] = 1;
      R[i][0] = 1;
      int tmp2 = inv(quick(g, (MOD - 1) >> i));
      int tmp = quick(g, (MOD - 1) >> i);
      for (int j = 1; j <= (1 << i); ++j) {
        G[i][j] = qmul(G[i][j - 1], tmp);
        R[i][j] = qmul(R[i][j - 1], tmp2);
      }
    }
  }
  void butterfly(vector<int>& v) {
    for (int i = 0; i < len; ++i) {
      rev[i] = rev[i >> 1] >> 1;
      if (i & 1) rev[i] |= len >> 1;
    }
    for (int i = 0; i < len; ++i)
      if (rev[i] > i) swap(v[i], v[rev[i]]);
  }
  vector<int> ntt(vector<int> v) {
    butterfly(v);
    vector<int> nex;
    int lg = 1;
    for (int l = 2; l <= len; l <<= 1, ++lg) {
      nex.clear();
      nex.resize(len);
      for (int j = 0; j < len; j += l) {
        for (int k = 0; k < l / 2; ++k) {
          int A, B;
          A = v[j + k];
          B = v[j + l / 2 + k];
          B = qmul(B, G[lg][k]);
          nex[j + k] = qadd(A, B);
          nex[j + k + l / 2] = qadd(A, MOD - B);
        }
      }
      v = nex;
    }
    return v;
  }
  vector<int> intt(vector<int> v) {
    butterfly(v);
    vector<int> nex;
    int lg = 1;
    for (int l = 2; l <= len; l <<= 1, ++lg) {
      nex.clear();
      nex.resize(len);
      for (int j = 0; j < len; j += l) {
        for (int k = 0; k < l / 2; ++k) {
          int A, B;
          A = v[j + k];
          B = v[j + l / 2 + k];
          B = qmul(R[lg][k], B);
          nex[j + k] = qadd(A, B);
          nex[j + k + l / 2] = qadd(A, MOD - B);
        }
      }
      v = nex;
    }
    return v;
  }
  void getlen(int x) {
    len = 1;
    while (len < x) {
      len <<= 1;
    }
  }
  vector<int> mul(vector<int> A, vector<int> B) {
    if (A.size() + B.size() <= 25) {
      vector<int> ret(A.size() + B.size() - 1);
      for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < B.size(); ++j)
          ret[i + j] = qadd(ret[i + j], qmul(A[i], B[j]));
      return ret;
    }
    getlen(A.size() + B.size());
    A.resize(len);
    B.resize(len);
    A = ntt(A);
    B = ntt(B);
    for (int i = 0; i < len; ++i) A[i] = qmul(A[i], B[i]);
    A = intt(A);
    int iv = inver[len];
    for (int i = 0; i < len; ++i) {
      A[i] = qmul(A[i], iv);
    }
    while (!A.empty() && A.back() == 0) A.pop_back();
    return A;
  }
  vector<int> inverse(vector<int> A, int n) {
    vector<int> ret(n);
    if (n == 1) {
      ret[0] = quick(A[0], MOD - 2);
    } else {
      vector<int> oth = inverse(A, (n + 1) >> 1);
      ret = oth;
      ret.resize(n);
      for (int i = 0; i < n; ++i) ret[i] = (ret[i] + ret[i]) % MOD;
      getlen((oth.size() << 1) + A.size());
      oth.resize(len);
      A.resize(len);
      oth = ntt(oth);
      A = ntt(A);
      for (int i = 0; i < len; ++i) oth[i] = qmul(qmul(oth[i], oth[i]), A[i]);
      oth = intt(oth);
      oth.resize(n);
      int iv = inver[len];
      for (int i = 0; i < n; ++i) {
        oth[i] = qmul(oth[i], iv);
      }
      for (int i = 0; i < n; ++i) ret[i] = qadd(ret[i], MOD - oth[i]);
    }
    return ret;
  }
} poly;
vector<int> operator*(vector<int> A, vector<int> B) { return poly.mul(A, B); }
vector<int> operator+(vector<int> A, vector<int> B) {
  int Sz = max(A.size(), B.size());
  A.resize(Sz);
  for (int i = 0; i < B.size(); ++i) A[i] = qadd(A[i], B[i]);
  return A;
}
vector<int> operator-(vector<int> A, vector<int> B) {
  int Sz = max(A.size(), B.size());
  A.resize(Sz);
  for (int i = 0; i < B.size(); ++i) A[i] = qadd(A[i], MOD - B[i]);
  return A;
}
vector<int> operator/(vector<int> A, vector<int> B) {
  return A * poly.inverse(B, A.size() - B.size() + 1);
}
vector<int> operator%(vector<int> A, vector<int> B) {
  while (A.size() != 1 && A.back() == 0) A.pop_back();
  while (B.size() != 1 && B.back() == 0) B.pop_back();
  if (B.size() > A.size()) return A;
  vector<int> rem, mod;
  int n, m;
  n = A.size() - 1;
  m = B.size() - 1;
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  rem = A / B;
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  rem.resize(n - m + 1);
  reverse(rem.begin(), rem.end());
  mod = A - rem * B;
  mod.resize(m);
  return mod;
}
vector<int> der(vector<int> A) {
  while (A.size() != 1 && A.back() == 0) A.pop_back();
  vector<int> ret(A.size() - 1);
  for (int i = 0; i < ret.size(); ++i) ret[i] = 1ll * (i + 1) * A[i + 1] % MOD;
  if (ret.empty()) return vector<int>(1, 0);
  return ret;
}
class MC {
  vector<vector<int> > RAM;
  vector<vector<int> > SIN;
  vector<int> Lc;
  vector<int> Rc;
  vector<int> ret;
  vector<int> x_;
  void fendge1(int l, int r, int& cnt) {
    if (l == r - 1) {
      Lc.push_back(0);
      Rc.push_back(0);
      RAM.push_back(SIN[l]);
      return;
    }
    RAM.push_back(vector<int>(0));
    Lc.push_back(0);
    Rc.push_back(0);
    int now = cnt;
    int mid = (l + r) >> 1;
    int L = ++cnt;
    fendge1(l, mid, cnt);
    int R = ++cnt;
    fendge1(mid, r, cnt);
    Lc[now] = L;
    Rc[now] = R;
    RAM[now] = RAM[L] * RAM[R];
  }
  void fendge2(int l, int r, int cnt, vector<int> p) {
    p = p % RAM[cnt];
    if (r - l <= 300) {
      for (int i = l; i <= r - 1; ++i) {
        int T = 1;
        for (int j = 0; j < p.size(); ++j) {
          ret[i] = qadd(ret[i], qmul(T, p[j]));
          T = qmul(T, x_[i]);
        }
      }
      return;
    }
    int mid = (l + r) >> 1;
    fendge2(l, mid, Lc[cnt], p);
    fendge2(mid, r, Rc[cnt], p);
  }

 public:
  vector<int> init(vector<int> p, vector<int> x) {
    x_ = x;
    Lc.clear();
    Rc.clear();
    RAM.clear();
    SIN.clear();
    ret.clear();
    ret.resize(x.size());
    for (int i = 0; i < x.size(); ++i) {
      SIN.push_back(vector<int>{(MOD - x[i]), 1});
    }
    int cnt = 0;
    fendge1(0, x.size(), cnt);
    fendge2(0, x.size(), 0, p);
    return ret;
  }
} mc;
vector<int> multiple_calculation(vector<int> p, vector<int> x) {
  return mc.init(p, x);
}
class ITP {
  vector<int> u;
  vector<int> v;
  vector<int> fm;
  vector<int> fendge(int l, int r) {
    if (l == r - 1) {
      return vector<int>{(MOD - u[l]), 1};
    }
    int mid = (l + r) >> 1;
    return fendge(l, mid) * fendge(mid, r);
  }
  pair<vector<int>, vector<int> > fendge2(int l, int r) {
    if (l == r - 1) {
      return {vector<int>{(MOD - u[l]), 1}, vector<int>{fm[l]}};
    }
    int mid = (l + r) >> 1;
    pair<vector<int>, vector<int> > L, R;
    L = fendge2(l, mid);
    R = fendge2(mid, r);
    return {L.first * R.first, L.first * R.second + R.first * L.second};
  }

 public:
  vector<int> solve(vector<pair<int, int> > x) {
    u.clear();
    v.clear();
    int n = x.size();
    for (auto it : x) u.push_back(it.first), v.push_back(it.second);
    vector<int> g = fendge(0, u.size());
    fm = multiple_calculation(der(g), u);
    for (int i = 0; i < n; ++i) {
      fm[i] = qmul(v[i], inv(fm[i]));
    }
    return fendge2(0, n).second;
  }
} itp;
vector<int> interpolation(vector<pair<int, int> > x) { return itp.solve(x); }
}  // namespace mypoly
using namespace mypoly;
const int MAXN = 5e4 + 1;
void add(int& A, int B) {
  A += B;
  if (A >= MOD) A -= MOD;
}
int n;
pair<int, vector<int> > solve(int n, int m) {
  if (m == 1) {
    vector<int> ret(n + 1, 1);
    ret[0] = 0;
    return make_pair(1, ret);
  }
  pair<int, vector<int> > small = solve(n, m / 2);
  int smallcyc = small.first;
  vector<int> smallline = small.second;
  smallline[1] = (m + 1) / 2;
  int anscyc = 0;
  if (n % 2 == 0) add(anscyc, 2ll * smallcyc % MOD);
  vector<int> odd(n + 1, 0);
  for (int i = 1; i <= n; ++i)
    if (i & 1) odd[i] = smallline[i];
  vector<int> orodd = odd;
  odd[0] = 1;
  for (int i = 1; i <= n; ++i) odd[i] = (MOD - odd[i]) % MOD;
  odd = poly.inverse(odd, n + 1);
  for (int i = 1; i <= n; ++i) orodd[i] = 1ll * i * orodd[i] % MOD;
  add(anscyc, (odd * orodd)[n]);
  vector<int> ansline(n + 1, 0);
  vector<int> even(n + 1, 0);
  for (int i = 1; i <= n; ++i)
    if (i % 2 == 0) even[i] = smallline[i];
  for (int i = 1; i <= n; ++i) add(ansline[i], odd[i]);
  vector<int> tmp = even * odd;
  for (int i = 1; i <= n; ++i) add(ansline[i], 2ll * tmp[i] % MOD);
  tmp = even * tmp;
  for (int i = 1; i <= n; ++i) add(ansline[i], tmp[i]);
  for (int i = 1; i <= n; ++i)
    if (i & 1) add(ansline[i], smallline[i]);
  return make_pair(anscyc, ansline);
}
int main() {
  int m;
  cin >> n >> m;
  cout << solve(n, m).first << endl;
  return 0;
}
