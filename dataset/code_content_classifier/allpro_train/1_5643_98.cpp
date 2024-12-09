#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long ranka[1000005];
long long rankb[1000005];
int main() {
  long long n;
  scanf("%lld", &n);
  ranka[1] = ranka[0] = 1;
  for (long long i = 2; i <= n; i++) ranka[i] = (ranka[i - 1] * i) % mod;
  rankb[0] = 1;
  for (long long i = 1; i <= n; i++)
    rankb[i] = (rankb[i - 1] * (n + 1 - i)) % mod;
  long long ans = ranka[n];
  for (long long i = 1; i < n; i++)
    ans = (ans + rankb[i] * (ranka[n - i] - 1)) % mod;
  printf("%lld", ans);
}
