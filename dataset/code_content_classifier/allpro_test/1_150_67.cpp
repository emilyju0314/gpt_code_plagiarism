#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long int tc;
  cin >> tc;
  for (long long int i = 1; i <= tc; i++) {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    long long int coins = mod;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto check = [&](long long int one, long long int two,
                     long long int val) -> long long int {
      vector<long long int> combination;
      for (long long int i = 0; i <= one; i++) {
        for (long long int j = 0; j <= two; j++) {
          combination.emplace_back(i + 2 * j);
        }
      }
      long long int cur_coins = mod;
      for (long long int i : combination) {
        if ((val < i) or (val - i) % 3 != 0) continue;
        cur_coins = min(cur_coins, (val - i) / 3);
      }
      return cur_coins + one + two;
    };
    for (long long int one = 0; one < 3; one++) {
      for (long long int two = 0; two < 3; two++) {
        long long int cur = 0;
        for (long long int i : a) {
          cur = max(cur, check(one, two, i));
        }
        coins = min(coins, cur);
      }
    }
    cout << coins;
    cout << "\n";
  }
  return 0;
}
