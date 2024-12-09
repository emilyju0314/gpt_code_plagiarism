#include <bits/stdc++.h>
long long mod = 1000000007;
long long mod2 = 998244353;
long long OO = 1e18;
long long david_villa_pow(long long x, long long n) {
  if (n == 0) return 1;
  long long u = david_villa_pow(x, n / 2);
  u = ((u) * (u));
  if (n % 2 == 1) u = ((u) * (x));
  return u;
}
long long up(long long x, long long y) {
  if (x % y == 0) return x / y;
  return x / y + 1;
}
using namespace std;
long long n;
long long a[200200];
long long pre[200200];
pair<long long, long long> p[500200];
map<long long, long long> mp;
int main() {
  long long i, j;
  ;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  pre[1] = a[1];
  for (i = 2; i <= n; i++) pre[i] = pre[i - 1] + a[i];
  j = 0;
  for (i = 0; i <= n; i++) {
    if (mp.find(pre[i]) != mp.end()) {
      p[j++] = {mp[pre[i]] + 1, i};
    }
    mp[pre[i]] = i;
  }
  sort(p, p + j);
  long long res = 0;
  for (i = 0; i < j;) {
    long long en = p[i].second;
    long long k = i + 1;
    while (k < j && p[k].first + 1 <= en) {
      en = min(en, p[k].second);
      k++;
    }
    res++;
    i = k;
  }
  cout << res << endl;
  return 0;
}
