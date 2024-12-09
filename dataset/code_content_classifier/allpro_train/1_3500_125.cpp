#include <bits/stdc++.h>
const int fx[] = {+1, -1, +0, +0};
const int fy[] = {+0, +0, +1, -1};
using namespace std;
long long dp[2020][2020];
int n, k;
vector<int> divs[2020];
long long call(int num, int taken) {
  if (taken == k) return 1;
  if (dp[num][taken] != -1) return dp[num][taken];
  long long &val = dp[num][taken];
  val = 0;
  for (int i : divs[num]) {
    val = (val + call(i, taken + 1)) % 1000000007;
  }
  return val;
}
int main() {
  cin >> n >> k;
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      divs[i].push_back(j);
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + call(i, 1)) % 1000000007;
  }
  cout << ans << endl;
}
