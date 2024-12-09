#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000000 + 7;
long long powe(long long x, long long y) {
  x = x % mod, y = y % (mod - 1);
  long long ans = 1;
  while (y > 0) {
    if (y & 1) {
      ans = (1ll * x * ans) % mod;
    }
    y >>= 1;
    x = (1ll * x * x) % mod;
  }
  return ans;
}
void fun() {}
signed main() {
  fun();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, k, num;
  long long sum = 1;
  cin >> n >> k;
  long long a[100001] = {};
  for (long long i = 0; i < n; i++) {
    cin >> num;
    sum = 1;
    for (long long j = 2; j * j <= num; j++) {
      long long cnt = 0;
      while (num % j == 0) {
        num /= j;
        cnt++;
      }
      cnt %= k;
      sum *= pow(j, cnt);
    }
    if (num != 1) {
      sum *= pow(num, 1);
    }
    a[sum]++;
  }
  long long ans = 0;
  map<pair<long long, long long>, long long> mp;
  for (long long i = 1; i <= 100000; i++) {
    if (a[i] == 0) continue;
    num = i;
    sum = 1;
    for (long long j = 2; j * j <= num; j++) {
      long long cnt = 0;
      while (num % j == 0) {
        num /= j;
        cnt++;
      }
      if (cnt != k) cnt %= k;
      sum *= pow(j, (k - cnt) % k);
    }
    if (num != 1) {
      sum *= pow(num, k - 1);
    }
    if (sum == i)
      ans += (a[i] * (a[i] - 1) / 2);
    else if (sum < 100001) {
      if (mp[{i, sum}] == 0 && mp[{sum, i}] == 0) ans += (a[i] * a[sum]);
      mp[{i, sum}] = 1;
    }
  }
  cout << ans << "\n";
}
