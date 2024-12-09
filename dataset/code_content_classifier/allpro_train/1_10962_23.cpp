#include <bits/stdc++.h>
using namespace std;
const long long mv = 1e14 + 10;
long long power(long long a, long long n) {
  long long ans = 1;
  for (long long i = 1; i <= n; i++) {
    ans *= a;
  }
  return ans;
}
int32_t main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  vector<long long> v;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  if (k == 1) {
    v.push_back(1);
  } else if (k == -1) {
    v.push_back(1);
    v.push_back(-1);
  } else {
    for (long long i = 0; i < 50; i++) {
      if (abs(power(k, i)) > mv) {
        break;
      }
      v.push_back(power(k, i));
    }
  }
  map<long long, long long> mp;
  mp[0] = 1;
  long long s = 0, ans = 0;
  for (long long i = 0; i < n; i++) {
    s += a[i];
    for (auto j : v) {
      if (mp.count(s - j)) ans += mp[s - j];
    }
    mp[s]++;
  }
  cout << ans;
  return 0;
}
