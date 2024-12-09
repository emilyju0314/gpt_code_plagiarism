#include <bits/stdc++.h>
using namespace std;
int xx[4] = {1, -1, 0, 0};
int yy[4] = {0, 0, 1, -1};
const double eps = 1e-9;
const int maxn = 2e6 + 5000;
const long long mod = 1e9 + 7;
const int INF(0x3f3f3f3f);
const long long INFL(0x3f3f3f3f3f3f3f3fll);
inline int sign(double a) { return a < -eps ? -1 : a > eps; }
long long mul(long long a, long long b, long long c) {
  long long res = 1;
  while (b) {
    if (b & 1) res *= a, res %= c;
    a *= a, a %= c, b >>= 1;
  }
  return res;
}
long long phi(long long x) {
  long long res = x;
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) res = res / i * (i - 1);
    while (x % i == 0) x /= i;
  }
  if (x > 1) res = res / x * (x - 1);
  return res;
}
template <typename A, typename B>
inline bool chmin(A& a, B b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename A, typename B>
inline bool chmax(A& a, B b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename A, typename B>
inline long long add(A x, B y) {
  if (x + y < 0) return x + y + mod;
  return x + y >= mod ? x + y - mod : x + y;
}
template <typename A, typename B>
inline void add2(A& x, B y) {
  if (x + y < 0)
    x = x + y + mod;
  else
    x = (x + y >= mod ? x + y - mod : x + y);
}
template <typename A, typename B>
inline long long mul1(A x, B y) {
  return 1ll * x * y % mod;
}
template <typename A, typename B>
inline void mul2(A& x, B y) {
  x = (1ll * x * y % mod + mod) % mod;
}
template <typename A>
inline void debug(A a) {
  cout << a << '\n';
}
template <typename A>
inline long long sqr(A x) {
  return 1ll * x * x;
}
template <typename A>
A inv(A x) {
  return mul(x, mod - 2);
}
template <typename A>
void bugl(A a[], int l, int r) {
  for (int i = l; i <= r; i++) cout << a[i] << " ";
  cout << endl;
}
template <typename A>
void bug(A a[], int l, int r) {
  for (int i = l; i <= r; i++) cout << a[i] << " ";
  cout << endl;
}
template <class T>
void wt(const T& x) {
  cout << x << endl;
}
template <class T>
void wt(const T& x, char c) {
  cout << x << c;
}
template <class T>
void wt(const T& x, const string& s) {
  cout << x << s;
}
template <class T>
void wt(const T& x, int rnd) {
  cout << fixed << setprecision(rnd) << x << endl;
}
inline long long lowbit(long long x) { return (x & (-x)); }
inline void debug() { cout << "###!!!" << endl; }
inline long long read() {
  char c = getchar();
  long long x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = 1ll * x * 10 + c - '0', c = getchar();
  return x * f;
}
long long n, k;
long long a[maxn];
long long f[1 << 16][5];
pair<int, int> g[maxn];
int main() {
  int t;
  while (cin >> n >> t) {
    for (int i = 0; i < n; i++) cin >> g[i].first >> g[i].second, g[i].second--;
    f[0][3] = 1;
    for (int i = 0; i < (1 << n); i++) {
      cerr << ("i") << " = " << (i) << endl;
      ;
      for (int j = 0; j < 4; j++) {
        for (int k = 0; k < n; k++) {
          if (g[k].second != j && (i & (1 << k)) == 0)
            f[i | (1 << k)][g[k].second] += f[i][j],
                f[i | (1 << k)][g[k].second] %= mod;
        }
      }
    }
    long long ans = 0;
    for (int i = 0; i < (1 << n); i++) {
      long long sum = 0;
      for (int j = 0; j < n; j++) {
        if (((1 << j) & i)) sum += g[j].first;
      }
      cout << endl;
      if (sum == t) {
        for (int k = 0; k < 4; k++) ans += f[i][k];
        ans %= mod;
      }
    }
    wt(ans);
  }
  return 0;
}
