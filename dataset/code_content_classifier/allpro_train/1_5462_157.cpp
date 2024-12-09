#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  ;
  long long i, j, k, arr[100005], l, m, n, x, y, coun, sum, ans, T, check;
  char str[100005];
  vector<long long> v;
  string s;
  cin >> n >> k;
  map<long long, long long> mp;
  for (i = 0; i < n; i++) {
    cin >> x;
    mp[x % k]++;
  }
  ans = mp[0];
  if (ans % 2 == 1) ans--;
  for (i = 1; i < k; i++) {
    x = min(mp[i], mp[k - i]);
    if (i != k - i)
      ans += (2 * x);
    else
      ans += x;
    mp[i] -= x;
    mp[k - i] -= x;
  }
  if (ans % 2 == 1) ans--;
  cout << ans << "\n";
  return 0;
}
