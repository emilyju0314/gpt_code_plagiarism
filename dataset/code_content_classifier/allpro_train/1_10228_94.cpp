#include <bits/stdc++.h>
using namespace std;
template <typename T>
void maxtt(T& t1, T t2) {
  t1 = max(t1, t2);
}
template <typename T>
void mintt(T& t1, T t2) {
  t1 = min(t1, t2);
}
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "URDL";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int& x, int y, int mod = 998244353) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et(int x = -1) {
  printf("%d\n", x);
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 998244353) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
void fmain(int tid) {
  int c, d, T;
  scanf("%d%d%d", &n, &c, &d);
  vector<int> t(n + 5), w(n + 5, -1);
  char ope[3];
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    scanf("%d", &t[i]);
    scanf("%s", ope);
    w[i] = ope[0] == 'P' ? 0 : 1;
  }
  scanf("%d", &T);
  long long ans = (long long)d * n, s = 0;
  w[n + 1] = -1;
  t[n + 1] = T;
  for (int i = n, lst; i; i--) {
    if (w[i] == w[i + 1]) {
      s += min(d, (lst - t[i + 1]) * c);
    } else
      lst = t[i + 1];
    mintt(ans, (long long)(i - 1) * d + s + (long long)(T - t[i]) * c);
  }
  printf("%lld\n", ans);
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
