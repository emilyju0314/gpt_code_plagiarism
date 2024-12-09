#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 2e6 + 100;
const int mod = 1e9 + 7;
int deg[maxn];
long long ksm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = res * a % mod;
    }
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
long long add(long long a, long long b) { return (a + b) % mod; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    scanf("%d", &u);
    scanf("%d", &v);
    deg[u]++;
    deg[v]++;
  }
  int lef = 0;
  for (int i = 1; i <= n; i++) lef += (deg[i] == 1);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = add(ans, ksm(2, n - lef + (deg[i] == 1)));
  }
  printf("%lld\n", ans);
  return 0;
}
