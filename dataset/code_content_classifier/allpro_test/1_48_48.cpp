#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::greater;
using std::less;
using std::lower_bound;
using std::make_pair;
using std::map;
using std::max;
using std::min;
using std::multiset;
using std::pair;
using std::priority_queue;
using std::queue;
using std::set;
using std::sort;
using std::string;
using std::swap;
using std::unique;
using std::unordered_map;
using std::upper_bound;
using std::vector;
template <typename T>
void in(T &x) {
  x = 0;
  bool f = false;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = true;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  if (f) x = -x;
}
template <typename T>
void out(T x, char ch = '\n') {
  static int tp, sk[30];
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  do {
    sk[++tp] = x % 10;
    x /= 10;
  } while (x);
  while (tp) {
    putchar(sk[tp--] + '0');
  }
  putchar(ch);
}
template <typename T>
void Mx(T &x, T y) {
  x < y && (x = y);
}
template <typename T>
void Mn(T &x, T y) {
  x > y && (x = y);
}
template <typename T>
T sabs(T x) {
  return x < 0 ? -x : x;
}
namespace Mod {
const int md = 998244353;
inline int add(const int &a, const int &b) {
  int p = a + b;
  if (p >= md) p -= md;
  return p;
}
inline int sub(const int &a, const int &b) {
  int p = a - b;
  if (p < 0) p += md;
  return p;
}
inline int mul(const int &a, const int &b) { return 1ll * a * b % md; }
inline int qpow(int a, int b) {
  int ret = 1;
  for (; b; b >>= 1, a = mul(a, a))
    if (b & 1) ret = mul(ret, a);
  return ret;
}
inline int inv(int x) { return qpow(x, md - 2); }
}  // namespace Mod
using Mod::add;
using Mod::inv;
using Mod::md;
using Mod::mul;
using Mod::qpow;
using Mod::sub;
const int N = 500010;
int n;
int a[N], c[N];
void Insert(int x) {
  for (; x <= n; x += x & -x) ++c[x];
}
int query(int x) {
  int ret = 0;
  for (; x; x -= x & -x) ret += c[x];
  return ret;
}
namespace gvihvo {
void main() {
  in(n);
  map<int, int> cnt;
  for (int i = 1; i <= n; ++i) {
    in(a[i]);
    ++cnt[a[i]];
  }
  for (auto i : cnt)
    if (i.second > 1) {
      puts("YES");
      return;
    }
  long long val = 0;
  for (int i = n; i >= 1; --i) {
    val += query(a[i]);
    Insert(a[i]);
  }
  val % 2 ? puts("NO") : puts("YES");
  memset(c, 0, sizeof(int) * (n + 10));
}
}  // namespace gvihvo
int main() {
  int cza;
  scanf("%d", &cza);
  while (cza--) gvihvo::main();
  return 0;
}
