#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const long long MOD = 1e9 + 7;
long long power(long long x, long long k, long long MOD) {
  long long res = 1;
  x = (x % MOD + MOD) % MOD;
  while (k) {
    if (k & 1) res = res * x % MOD;
    x = x * x % MOD;
    k >>= 1;
  }
  return res % MOD;
}
int one[N], idx;
int ver[N], Next[N];
long long edge[N];
inline void AddEdge(int a, int b, long long c) {
  Next[idx] = one[a];
  ver[idx] = b;
  edge[idx] = c;
  one[a] = idx++;
}
int n;
pair<long long, long long> f[N];
void dp(int x, int fa, int cost) {
  long long suma = 0, sumb = cost, deg = 0;
  for (int i = one[x], y; ~i; i = Next[i]) {
    y = ver[i];
    deg++;
    if (y == fa) continue;
    dp(y, x, edge[i]);
    suma += f[y].first;
    sumb += f[y].second + edge[i];
  }
  suma %= MOD, sumb %= MOD;
  if (deg == 1 && fa)
    f[x] = pair<long long, long long>(0, 0);
  else {
    long long inver = power(deg - suma, MOD - 2, MOD);
    f[x] = pair<long long, long long>(inver, inver * sumb % MOD);
  }
}
int main() {
  int i;
  int x, y;
  long long z;
  scanf("%d", &n);
  memset(one, -1, sizeof one);
  for (i = 1; i <= n - 1; i++) {
    scanf("%d%d%lld", &x, &y, &z);
    AddEdge(++x, ++y, z);
    AddEdge(y, x, z);
  }
  dp(1, 0, 0);
  printf("%lld\n", f[1].second);
  return 0;
}
