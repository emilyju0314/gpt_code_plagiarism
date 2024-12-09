#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll pow(ll a, ll b, ll p) {
  ll ans = 1;
  a %= p;
  while (b) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans;
}
ll inv1(ll a, ll p) { return pow(a, p - 2, p); }
void ex_gcd(ll a, ll b, ll &d, ll &x, ll &y) {
  if (!b) {
    d = a, x = 1, y = 0;
    return;
  }
  ex_gcd(b, a % b, d, y, x);
  y -= x * (a / b);
}
ll inv2(ll a, ll p) {
  ll d, x, y;
  ex_gcd(a, p, d, x, y);
  return d == 1 ? (x % p + p) % p : -1;
}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
template <typename T>
T rand(T a, T b) {
  return rand() % (b - a + 1) + a;
}
namespace IO {
struct Reader {
  template <typename T>
  Reader &operator>>(T &x) {
    x = 0;
    T f = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar())
      if (c == '-') f = -1;
    for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
    x *= f;
    return *this;
  }
} cin;
struct Writer {
  template <typename T>
  inline void w(T x) {
    if (x > 9) w(x / 10);
    putchar(x % 10 + 48);
  }
  template <typename T>
  Writer &operator<<(T x) {
    if (x < 0) putchar('-'), x = -x;
    w(x);
    return *this;
  }
} cout;
struct ios {
  inline char read() {
    static const int IN_LEN = 1e6 + 10;
    static char buf[IN_LEN], *s, *t;
    return (s == t) && (t = (s = buf) + fread(buf, 1, IN_LEN, stdin)),
           s == t ? -1 : *s++;
  }
  template <typename _Tp>
  inline ios &operator>>(_Tp &x) {
    static char c11, boo;
    for (c11 = read(), boo = 0; !isdigit(c11); c11 = read())
      if (c11 == -1) return *this;
    boo |= c11 == '-';
    for (x = 0; isdigit(c11); c11 = read()) x = x * 10 + (c11 ^ '0');
    boo && (x = -x);
    return *this;
  }
} io;
};  // namespace IO
ll qpow(ll x, ll y) {
  ll ret = 1;
  while (y) {
    if (y & 1ll) ret = ret * x;
    y >>= 1ll;
    x = x * x;
  }
  return ret;
}
const int N = 1e5 + 5, M = 1e6 + 5, MOD = 1e9 + 7, CM = 998244353,
          INF = 0x3f3f3f3f;
const double eps = 1e-6;
std::map<ll, int> mp;
std::map<ll, int> mp2;
ll aa[1000];
int nn;
ll cal(ll x) {
  ll n = x;
  ll a = pow(n, 1.0 / 2) - 1, b = pow(n, 1.0 / 3) - 1, c = pow(n, 1.0 / 4) - 1;
  while (qpow(a, 2) < n) a++;
  while (qpow(b, 3) < n) b++;
  while (qpow(c, 4) < n) c++;
  if (qpow(c, 4) == n) return mp[c] += 4;
  if (qpow(b, 3) == n) return mp[b] += 3;
  if (qpow(a, 2) == n) return mp[a] += 2;
  for (int i = 1; i <= nn; i++) {
    ll g = gcd(n, aa[i]);
    if (g != 1 && aa[i] != n) {
      return mp[n / g]++, mp[g]++;
    }
  }
  return mp2[n]++;
}
void solve(int kase) {
  cin >> nn;
  for (int i = 1; i <= nn; i++) {
    scanf("%lld", &aa[i]);
  }
  for (int i = 1; i <= nn; i++) cal(aa[i]);
  ll ans = 1;
  for (auto xx : mp) {
    ans = ans * (xx.second + 1) % CM;
  }
  for (auto xx : mp2) {
    ans = ans * (xx.second + 1) * (xx.second + 1) % CM;
  }
  printf("%lld\n", ans);
}
const bool DUO = 0;
void TIME() {
  clock_t start, finish;
  double totaltime;
  start = clock();
  if (DUO) {
    int Kase = 0;
    cin >> Kase;
    for (int kase = 1; kase <= Kase; kase++) solve(kase);
  } else
    solve(1);
  finish = clock();
  totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
  printf("\nTime: %lfms\n", totaltime * 1000);
}
int main() {
  srand(time(NULL));
  if (DUO) {
    int Kase = 0;
    cin >> Kase;
    for (int kase = 1; kase <= Kase; kase++) solve(kase);
  } else
    solve(1);
  return 0;
}
