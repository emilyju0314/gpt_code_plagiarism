#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 110000;
template <typename T>
inline bool scan_d(T& ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF) return 0;
  while (c != '-' && (c < '0' || c > '9')) {
    if ((c = getchar()) == EOF) return 0;
  }
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return 1;
}
template <typename T>
void print(T x) {
  static char s[33], *s1;
  s1 = s;
  if (!x) *s1++ = '0';
  if (x < 0) putchar('-'), x = -x;
  while (x) *s1++ = (x % 10 + '0'), x /= 10;
  while (s1-- != s) putchar(*s1);
}
template <typename T>
void println(T x) {
  print(x);
  putchar('\n');
}
int norm(int x) {
  if (x < 0) {
    x += MOD;
  }
  if (x >= MOD) {
    x -= MOD;
  }
  return x;
}
template <class T>
T power(T a, int b) {
  T res = 1;
  for (; b; b >>= 1, a *= a) {
    if (b & 1) {
      res *= a;
    }
  }
  return res;
}
struct mint {
  int x;
  mint(int x = 0) : x(norm(x)) {}
  int val() const { return x; }
  mint operator-() const { return mint(norm(MOD - x)); }
  mint inv() const { return power(*this, MOD - 2); }
  mint& operator*=(const mint& rv) {
    x = (long long)x * rv.x % MOD;
    return *this;
  }
  mint& operator+=(const mint& rv) {
    x = norm(x + rv.x);
    return *this;
  }
  mint& operator-=(const mint& rv) {
    x = norm(x - rv.x);
    return *this;
  }
  mint& operator/=(const mint& rv) { return *this *= rv.inv(); }
  friend mint operator*(const mint& lv, const mint& rv) {
    mint res = lv;
    res *= rv;
    return res;
  }
  friend mint operator+(const mint& lv, const mint& rv) {
    mint res = lv;
    res += rv;
    return res;
  }
  friend mint operator-(const mint& lv, const mint& rv) {
    mint res = lv;
    res -= rv;
    return res;
  }
  friend mint operator/(const mint& lv, const mint& rv) {
    mint res = lv;
    res /= rv;
    return res;
  }
};
struct TPoint {
  int v, x, y;
};
int n;
int a[N];
vector<TPoint> b[2];
vector<long long> dp[2];
void fmain() {
  scan_d(n);
  for (int i = (1); i < (n + 1); ++i) scan_d(a[i]);
  mint res = 0;
  int las = 0, cur = 0;
  for (int i = (1); i < (n + 1); ++i) {
    las = cur, cur ^= 1;
    b[cur].clear();
    for (int j = (1); j < (a[i] + 1); ++j) {
      if (j * j > a[i]) break;
      int v = j, x = a[i] / j, y = a[i] / j;
      if (a[i] % j != 0) y++;
      b[cur].push_back({v, x, y});
    }
    vector<TPoint> bb;
    for (int j = (0); j < (a[i] + 1); ++j) {
      if (j * j > a[i]) break;
      int v = (a[i] + j) / (j + 1), x = (j + 1), y = (j + 1);
      if (a[i] % (j + 1) != 0) x--;
      bb.push_back({v, x, y});
    }
    for (int j = (bb.size()) - 1; j >= (0); --j)
      if (bb[j].v > b[cur].back().v) b[cur].push_back(bb[j]);
    dp[cur].resize(b[cur].size());
    if (i == 1) {
      for (int j = (0); j < (dp[cur].size()); ++j) dp[cur][j] = b[cur][j].v - 1;
    } else {
      int k = 0;
      for (int j = (0); j < (dp[cur].size()); ++j) {
        while (b[las][k].y > b[cur][j].x) k++;
        dp[cur][j] = dp[las][k] + (long long)i * (b[cur][j].v - 1);
      }
    }
    res += (int)(dp[cur][0] % MOD);
  }
  println(res.val());
}
int main() {
  int T;
  scan_d(T);
  for (int t = (0); t < (T); ++t) {
    fmain();
  }
  return 0;
}
