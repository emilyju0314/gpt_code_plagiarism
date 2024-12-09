#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int fx[] = {-1, +0, +1, +0, +1, +1, -1, -1, +0};
int fy[] = {+0, -1, +0, +1, +1, -1, +1, -1, +0};
int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
template <typename T>
inline bool isLeap(T y) {
  return (y % 400 == 0) || (y % 100 ? y % 4 == 0 : false);
}
template <typename T>
inline T GCD(T a, T b) {
  a = abs(a);
  b = abs(b);
  if (a < b) swap(a, b);
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
template <typename T>
inline T EGCD(T a, T b, T &x, T &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  T x1, y1;
  T d = EGCD(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
template <typename T>
inline T LCM(T x, T y) {
  T tp = GCD(x, y);
  if ((x / tp) * 1. * y > 9e18) return 9e18;
  return (x / tp) * y;
}
template <typename T>
inline T BigMod(T A, T B, T M = MOD) {
  T ret = 1;
  while (B) {
    if (B & 1) ret = (ret * A) % M;
    A = (A * A) % M;
    B = B >> 1;
  }
  return ret;
}
template <typename T>
inline T InvMod(T A, T M = MOD) {
  return BigMod(A, M - 2, M);
}
template <typename T>
void Compress(T *in, int n) {
  vector<T> vv;
  for (int i = 0; i < n; i++) vv.push_back(in[i]);
  sort(vv.begin(), vv.end()), vv.erase(unique(vv.begin(), vv.end()), vv.end());
  for (int i = 0; i < n; i++)
    in[i] = lower_bound(vv.begin(), vv.end(), in[i]) - vv.begin();
}
template <typename T>
T scani(T &n) {
  n = 0;
  bool negative = false;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') negative = true;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    n = n * 10 + c - 48;
    c = getchar();
  }
  if (negative) n = ~(n - 1);
  return n;
}
template <typename T>
void write(T n, int type = true) {
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if (!n) {
    putchar('0');
    if (type == 32)
      putchar(' ');
    else if (type)
      putchar('\n');
    return;
  }
  char buff[22];
  int len = 0;
  while (n) buff[len++] = n % 10 + 48, n /= 10;
  for (int i = len - 1; i >= 0; i--) putchar(buff[i]);
  if (type == 32)
    putchar(' ');
  else if (type)
    putchar('\n');
}
int scans(char *a) {
  int i = 0;
  char c = 0;
  while (c < 33) c = getchar();
  while (c > 33) {
    a[i++] = c;
    c = getchar();
  }
  a[i] = 0;
  return i;
}
const int pSz = 2000006;
bool np[pSz + 10];
vector<int> prime;
int prime_size;
void sieve() {
  np[0] = np[1] = 1;
  prime.push_back(2);
  for (long long i = 4; i <= pSz; i += 2) np[i] = 1;
  for (long long i = 3; i <= pSz; i += 2) {
    if (!np[i]) {
      prime.push_back(i);
      for (long long j = i * i; j <= pSz; j += (i << 1)) np[j] = 1;
    }
  }
  prime_size = prime.size();
}
template <typename T>
inline T SqrDis(T x1, T y1, T x2, T y2) {
  return ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
}
template <typename T>
inline T Area2(T Ax, T Ay, T Bx, T By, T Cx, T Cy) {
  T ret = Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By);
  if (ret < 0) return ret = -ret;
  return ret;
}
const int N = 2000006;
const int M = 44444;
const unsigned long long hs = 3797;
int vs[N], a[N], b[N], n;
int main() {
  int t;
  scani(t);
  while (t--) {
    memset(vs, 0, sizeof vs);
    scani(n);
    for (int i = (0); i < (n); ++i) scani(a[i]);
    sort(a, a + n);
    vector<int> d, res;
    for (int i = (0); i < (n); ++i)
      for (int j = (i); j < (n); ++j) d.push_back(a[j] - a[i]);
    for (int i = (1); i < (N); ++i) {
      if (vs[i]) continue;
      if (res.size() == n) break;
      res.push_back(i);
      for (int id : d) vs[id + i] = 1;
    }
    puts("YES");
    for (int i = 0; i < res.size(); i++) {
      if (i) putchar(' ');
      write(res[i], false);
    }
    putchar('\n');
  }
  return 0;
}
