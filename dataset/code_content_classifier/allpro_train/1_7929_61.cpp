#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1060;
map<long long, long long> P;
vector<long long> _div;
long long n, tot;
long long k, a[Maxn], b[Maxn];
pair<long long, long long> f[Maxn][Maxn * 10];
long long gcd(long long x, long long y) { return x == 0 ? y : gcd(y % x, x); }
void GetDivisor() {
  long long blo = sqrt(k + 0.5);
  for (long long i = 1; i <= blo; ++i)
    if (k % i == 0) {
      _div.push_back(i);
      if (k / i != i) _div.push_back(k / i);
    }
  sort(_div.begin(), _div.end());
  tot = _div.size() - 1;
  for (long long i = 0; i < _div.size(); ++i) P[_div[i]] = i;
  for (long long i = 1; i <= n; ++i) b[i] = gcd(k, a[i]);
}
void Work() {
  if (k == 1) {
    puts("1");
    printf("%ld\n", min_element(a + 1, a + n + 1) - a);
    return;
  }
  for (long long i = 1; i <= tot; i++) f[0][i] = make_pair(0x3f3f3f3f, 0);
  for (long long i = 1; i <= n; i++)
    for (long long j = 0; j <= tot; j++) {
      f[i][j] = f[i - 1][j];
      long long pre = P[_div[j] / gcd(_div[j], b[i])];
      f[i][j] = min(f[i][j], make_pair(f[i - 1][pre].first + 1,
                                       f[i - 1][pre].second + a[i]));
    }
  if (f[n][P[k]].first >= 0x3f3f3f3f) {
    puts("-1");
    return;
  }
  printf("%lld\n", f[n][P[k]].first);
  for (long long i = n; i; i--)
    if (f[i][P[k]] != f[i - 1][P[k]]) {
      printf("%lld ", i);
      k /= gcd(k, b[i]);
    }
  puts("");
  return;
}
int main() {
  scanf("%lld%I64d", &n, &k);
  for (long long i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  GetDivisor();
  Work();
}
