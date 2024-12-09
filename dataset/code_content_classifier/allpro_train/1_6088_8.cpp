#include <bits/stdc++.h>
using namespace std;
const int N = 100001, MOD = 1000000007;
int p[N];
vector<int> factors(int n) {
  vector<int> res;
  res.push_back(1);
  while (n > 1) {
    if (!p[n]) {
      for (int i = res.size() - 1; i >= 0; i--) res.push_back(res[i] * n);
      break;
    }
    int m = p[n], k = res.size();
    while (n % m == 0) {
      for (int i = 0, j = res.size() - k; i < k; i++)
        res.push_back(res[j + i] * m);
      n /= m;
    }
  }
  sort(res.begin(), res.end());
  return res;
}
long long powmod(long long a, int n, int mod) {
  long long r = 1;
  for (; n; n >>= 1) {
    if (n & 1) r = (r * a) % mod;
    a = (a * a) % mod;
  }
  return r;
}
int a[N];
int main() {
  p[1] = 1;
  for (int i = 2; i < N; i++)
    if (!p[i])
      for (int j = i + i; j < N; j += i) p[j] = i;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int mx = a[n - 1];
  int res = 0;
  for (int i = 1; i <= mx; i++) {
    vector<int> f = factors(i);
    long long tmp = 1;
    int l = 0;
    for (int j = 0; j < (int)f.size() - 1; j++) {
      int r = lower_bound(a, a + n, f[j + 1]) - a;
      tmp = (tmp * powmod(j + 1, r - l, MOD)) % MOD;
      l = r;
    }
    int j = f.size() - 1;
    tmp = (tmp *
           ((powmod(j + 1, n - l, MOD) - powmod(j, n - l, MOD) + MOD) % MOD)) %
          MOD;
    res = (res + tmp) % MOD;
  }
  cout << res << endl;
  return 0;
}
