#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;

int main() {
  ll n, ans = 1;
  cin >> n;

  unordered_map<ll, ll> mp;
  for (int i = 1; i <= n; ++i) {
    int j = 2, t = i;
    while (t > 1) {
      if (t % j == 0) {
        t /= j;
        mp[j]++;
      } else {
        j++;
      }
    }
  }
  for (auto m : mp) ans *= m.second + 1, ans %= MOD;

  cout << ans << endl;
}
