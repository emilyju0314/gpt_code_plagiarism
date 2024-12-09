#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  ~debug() { cerr << endl; }
  template <class c>
  typename enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) {
    cerr << boolalpha << i;
    return *this;
  }
  template <class c>
  typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class c, class b>
  debug& operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c>
  debug& operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it;
    return *this << "]";
  }
};
long double eps = (long double)1 / 1e6;
const long double pi = 3.14159265359;
long long inf = 1e18, mod1 = 1e9 + 7;
long long sqr(long long a) { return a * a; }
long long qb(long long a) { return a * a * a; }
template <typename T>
bool umax(T& a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
bool umin(T& a, T b) {
  return b < a ? a = b, 1 : 0;
}
bool is_prime(long long val) {
  for (long long i = 2; i <= sqrt(val); i++)
    if (val % i == 0) return 0;
  return 1;
}
long long gcd(long long a, long long b) { return !a ? b : gcd(b % a, a); }
long long binpow(long long a, long long b, long long mod) {
  return b ? (b % 2 ? (a * (sqr(binpow(a, b / 2, mod)) % mod)) % mod
                    : sqr(binpow(a, b / 2, mod)) % mod)
           : 1;
}
long long binmult(long long a, long long b, long long mod) {
  return b ? (b % 2 ? (2 * binmult(a, b / 2, mod) + a) % mod
                    : (2 * binmult(a, b / 2, mod)) % mod)
           : 0;
}
const long long RR = 1e4;
const long long tx[8] = {1, -1, 2, -2, -1, -2};
const long long ty[8] = {-2, -2, -1, -1, 2, 1};
const char rev_to[4] = {'E', 'W', 'N', 'S'};
const int M = 1e9 + 7;
const int N = 1e5 + 1;
const int ppp = 73;
const int pr = 3;
const int block = 600;
const int OPEN = 1;
const int CLOSE = 0;
auto rnd = bind(uniform_int_distribution<int>(1, 5969699), mt19937(time(0)));
void bad() {
  cout << "IMPOSSIBLE";
  exit(0);
}
int mn(int mask, int mask1, int mask2, int mask3, int mask4, int a, int b,
       int c, int d, int e, int first) {
  if ((1ll << 0) & mask1) {
    int g = min(a, first);
    a -= g;
    first -= g;
  }
  if ((1ll << 1) & mask1) {
    int g = min(b, d);
    b -= g;
    d -= g;
  }
  if ((1ll << 2) & mask1) {
    int g = min(c, e);
    c -= g;
    e -= g;
  }
  if ((1ll << 0) & mask) {
    int g = min(a, d);
    a -= g;
    d -= g;
  }
  if ((1ll << 0) & mask2) {
    int g = min(a, first);
    a -= g;
    first -= g;
  }
  if ((1ll << 1) & mask2) {
    int g = min(b, d);
    b -= g;
    d -= g;
  }
  if ((1ll << 2) & mask2) {
    int g = min(c, e);
    c -= g;
    e -= g;
  }
  if ((1ll << 1) & mask) {
    int g = min(b, e);
    b -= g;
    e -= g;
  }
  if ((1ll << 0) & mask3) {
    int g = min(a, first);
    a -= g;
    first -= g;
  }
  if ((1ll << 1) & mask3) {
    int g = min(b, d);
    b -= g;
    d -= g;
  }
  if ((1ll << 2) & mask3) {
    int g = min(c, e);
    c -= g;
    e -= g;
  }
  if ((1ll << 2) & mask) {
    int g = min(c, first);
    c -= g;
    first -= g;
  }
  if ((1ll << 0) & mask4) {
    int g = min(a, first);
    a -= g;
    first -= g;
  }
  if ((1ll << 1) & mask4) {
    int g = min(b, d);
    b -= g;
    d -= g;
  }
  if ((1ll << 2) & mask4) {
    int g = min(c, e);
    c -= g;
    e -= g;
  }
  return a + b + c;
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  int n, a, b, c, d, e, first;
  cin >> n >> a >> b >> c >> d >> e >> first;
  int a1 = min(a, e) + min(b, first) + min(c, d);
  int a2 = 2e9;
  for (int mask = 0; mask < (1ll << 3); mask++) {
    for (int mask1 = 0; mask1 < (1ll << 3); mask1++) {
      for (int mask2 = 0; mask2 < (1ll << 3); mask2++) {
        for (int mask3 = 0; mask3 < (1ll << 3); mask3++) {
          for (int mask4 = 0; mask4 < (1ll << 3); mask4++) {
            umin(a2,
                 mn(mask, mask1, mask2, mask3, mask4, a, b, c, d, e, first));
          }
        }
      }
    }
  }
  cout << a2 << ' ' << a1;
  return 0;
}
