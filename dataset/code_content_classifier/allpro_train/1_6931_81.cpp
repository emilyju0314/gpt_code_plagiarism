#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1e9 + 7;
const double pi = 2 * acos(0.0);
const int N = 3e5 + 5;
const int LOG_N = 25;
long long arr[N], xr[N][2];
map<pair<long long, int>, long long> mp;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, ans = 0, m = 0;
  cin >> n;
  mp[{0, 1}] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    m ^= arr[i];
    if (i % 2)
      mp[{m, 0}]++;
    else
      mp[{m, 1}]++;
  }
  for (map<pair<long long, int>, long long>::iterator it = mp.begin();
       it != mp.end(); it++) {
    ans += (it->second * (it->second - 1)) / 2;
  }
  cout << ans << endl;
  return 0;
}
