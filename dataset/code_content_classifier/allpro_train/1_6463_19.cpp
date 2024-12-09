#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
const long long MOD = 1000000007;
long long DP[MAXN][MAXN], n, PA, PB, x, y;
struct Node {
  long long x, y;
  inline bool operator<(const Node &a) const { return x < a.x; }
} Index[MAXN];
inline long long Read() {
  long long x = 0, f = 0;
  char c = getchar();
  while (!isdigit(c)) {
    f |= c == '-';
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return f ? -x : x;
}
inline void Write(const long long &x) {
  if (x < 0) {
    putchar('-');
    Write(-x);
    return;
  }
  if (x > 9) {
    Write(x / 10);
  }
  putchar((x % 10) ^ 48);
  return;
}
inline long long Exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1, y = 0;
    return b;
  }
  long long gcd = Exgcd(b, a % b, x, y), Temp = x;
  x = y, y = Temp - a / b * y;
  return gcd;
}
inline long long Inv(const long long &a) {
  Exgcd(a, MOD, x, y);
  return (x % MOD + MOD) % MOD;
}
signed main() {
  register int i, j;
  n = Read(), PA = Read(), PB = Read();
  const long long P[3] = {PA * Inv(PA + PB) % MOD, (1 - P[0] + MOD) % MOD,
                          PA * Inv(PB) % MOD};
  for (i = n; i; --i) {
    for (j = n; j >= 0; --j) {
      DP[i][j] = (i + j >= n)
                     ? (i + j + P[2]) % MOD
                     : (P[0] * DP[i + 1][j] + P[1] * DP[i][i + j]) % MOD;
    }
  }
  Write(DP[1][0]), putchar('\n');
  return 0;
}
