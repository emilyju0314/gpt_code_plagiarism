#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5000 + 9;
int n;
int h[MAX_N];
int pref[MAX_N];
map<int, int> dp[MAX_N];
int main() {
  scanf("%d", &n);
  pref[0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &h[i]);
    pref[i] = pref[i - 1] + h[i];
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i - 1; j >= 0; --j) {
      int hnew = pref[i] - pref[j];
      int steps = i - j - 1;
      auto it = dp[j].lower_bound(hnew + 1);
      if (it != dp[j].begin())
        it--;
      else
        continue;
      int s = steps + it->second;
      auto nit = dp[i].upper_bound(hnew);
      while (nit != dp[i].end() && nit->second >= s) {
        auto tmp = nit++;
        dp[i].erase(nit);
        nit = tmp;
      }
      if (nit == dp[i].begin()) {
        dp[i][hnew] = s;
      } else {
        nit--;
        if (nit->second <= s) {
        } else {
          dp[i][hnew] = s;
        }
      }
    }
  }
  cout << dp[n].rbegin()->second;
  return 0;
}
