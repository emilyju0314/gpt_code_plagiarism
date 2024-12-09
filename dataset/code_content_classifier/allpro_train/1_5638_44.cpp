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
const long long MOD2 = (long long)1000000007 * (long long)1000000007;
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int& x, int y, int mod = 1000000007) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et(int x = -1) {
  printf("%d\n", x);
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 1000000007) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
int d;
int pos[200135];
void pp(long double x) { printf("%.15Lf\n", x); }
void fmain(int tid) {
  scanf("%d%d", &n, &d);
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    scanf("%d", &k);
    pos[i] = k;
  }
  scanf("%d", &m);
  int tar = 1;
  for (int(i) = 1; (i) <= (int)(m); (i)++) {
    int x;
    scanf("%d", &x);
    while (tar <= n && pos[tar] < x) tar++;
    if (tar > 1 && pos[tar - 1] == x - 1) {
      if (pos[tar] == x) {
        pp(acos(-1));
      } else
        pp(acos(-1) / 2);
    } else if (pos[tar] == x) {
      pp(acos(-1) / 2);
    } else {
      if (tar == 1)
        pp(atan(1.0 / (pos[tar] - x)));
      else if (tar == n + 1)
        pp(atan(1.0 / (x - pos[n] - 1)));
      else {
        int D = min(x - pos[tar - 1] - 1, pos[tar] - x);
        long double tmp = atan(1.0 / D);
        for (int p = tar - 1, j = tar;
             p > 0 && x - pos[p] - 1 <= D + D + 5 && j <= n; p--) {
          int q = x + (x - pos[p] - 1);
          while (j <= n && pos[j] < q - 1) j++;
          if (j == n + 1) break;
          if (pos[j] <= q) {
            maxtt(tmp, atanl(1.0 / (x - pos[p] - 1)) * 2);
            break;
          }
          if (pos[j] == q + 1) {
            maxtt(tmp, atanl(1.0 / (x - pos[p])) * 2);
            break;
          }
        }
        pp(tmp);
      }
    }
  }
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
