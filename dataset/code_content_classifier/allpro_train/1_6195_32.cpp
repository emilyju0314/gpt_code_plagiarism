#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long a[60];
int main() {
  map<long long, long long> mp;
  a[1] = 1;
  mp[1] = 1;
  for (int i = 2; i <= 53; i++) {
    a[i] = a[i - 1] * 2;
    mp[a[i]] = 1;
  }
  cin >> n >> k;
  while (mp[k] == 0) {
    long long pp = lower_bound(a + 1, a + 53, k) - a - 1;
    k = a[pp + 1] - k;
  }
  long long ans = lower_bound(a + 1, a + 53, k) - a;
  cout << ans << endl;
  return 0;
}
