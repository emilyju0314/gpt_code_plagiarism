#include <bits/stdc++.h>
using namespace std;
const int intmax = 0x3f3f3f3f;
const long long lldmax = 0x3f3f3f3f3f3f3f3fll;
double eps = 1e-8;
template <class T>
inline void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline T lowbit(T n) {
  return (n ^ (n - 1)) & n;
}
template <class T>
inline int countbit(T n) {
  return (n == 0) ? 0 : (1 + countbit(n & (n - 1)));
}
template <class T>
inline T checkmod(T n, T m) {
  return (n % m + m) % m;
}
template <class T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <class T>
inline T euclid(T a, T b, T &x, T &y) {
  if (a < 0) {
    T d = euclid(-a, b, x, y);
    x = -x;
    return d;
  }
  if (b < 0) {
    T d = euclid(a, -b, x, y);
    y = -y;
    return d;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    T d = euclid(b, a % b, x, y);
    T t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
  }
}
template <class T>
inline int dblcmp(T a, const T b) {
  a -= b;
  return a > eps ? 1 : (a < -eps ? -1 : 0);
}
template <class T>
inline int sgn(T a) {
  return a > eps ? 1 : (a < -eps ? -1 : 0);
}
const int N = 410000;
int a[N], b[N];
pair<int, int> s[N];
int main() {
  int n;
  int tmp;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    s[i] = make_pair(tmp, i);
  }
  sort(s, s + n);
  for (int i = 0; i < n; ++i) {
    int id = s[i].second;
    int v = s[i].first;
    if (i < (n + 1) / 3) {
      a[id] = i;
      b[id] = v - a[id];
    } else if (n - i - 1 < (n + 1) / 3) {
      b[id] = n - i - 1;
      a[id] = v - b[id];
    } else {
      b[id] = i;
      a[id] = v - b[id];
    }
  }
  puts("YES");
  for (int i = 0; i < n; ++i) printf("%d ", a[i]);
  puts("");
  for (int i = 0; i < n; ++i) printf("%d ", b[i]);
  puts("");
  return 0;
}
