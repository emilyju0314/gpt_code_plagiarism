#include <bits/stdc++.h>
using namespace std;
const int maxn = 5010;
const long long P = 1000000007;
long long ine[maxn], v[maxn], f[maxn];
int n;
long long k, ans;
int main() {
  int i, j;
  scanf("%d%lld", &n, &k);
  for (ans = i = 1; i <= n; i++) scanf("%lld", &v[i]), ans = ans * v[i] % P;
  f[0] = 1;
  for (i = 1; i <= n; i++) {
    for (j = i; j >= 1; j--) {
      f[j] = (f[j] * v[i] - f[j - 1]) % P;
    }
    f[0] = f[0] * v[i] % P;
  }
  ine[0] = ine[1] = 1;
  for (i = 2; i <= n; i++) ine[i] = P - (P / i) * ine[P % i] % P;
  long long t = 1, tmp = 1;
  for (i = 0; i <= n && i <= k; i++) {
    ans = (ans - f[i] * t % P * tmp) % P;
    t = t * ine[n] % P, tmp = tmp * (k - i) % P;
  }
  printf("%lld", (ans + P) % P);
  return 0;
}
