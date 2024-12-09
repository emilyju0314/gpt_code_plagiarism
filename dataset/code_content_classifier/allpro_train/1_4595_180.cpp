#include <bits/stdc++.h>
using namespace std;
void f(int mx, vector<vector<int> > &divisors, vector<int> &mobius) {
  divisors = vector<vector<int> >(mx + 1);
  mobius = vector<int>(mx + 1);
  for (int i = 1; i <= mx; i++) {
    for (int j = i; j <= mx; j += i) divisors[j].push_back(i);
    if (i == 1)
      mobius[i] = 1;
    else if ((i / divisors[i][1]) % divisors[i][1] == 0)
      mobius[i] = 0;
    else
      mobius[i] = -mobius[i / divisors[i][1]];
  }
}
int cop(int num, int mx, vector<int> &mobius, vector<vector<int> > &divisors) {
  long long ans = 0;
  for (auto it : divisors[num]) ans += (long long)mobius[it] * (mx / it);
  return ans;
}
long long MOD = 1e9 + 7;
long long powe(long long x, long long p) {
  if (p == 0) return 1;
  long long w = powe((x * x) % MOD, p / 2);
  if (p & 1) w = (w * x) % MOD;
  return w;
}
long long modinv(long long i) { return powe(i, MOD - 2); }
const int mx = 1e5;
long long dp[mx + 1];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int m;
  cin >> m;
  vector<int> cnt(m + 1);
  for (int i = 1; i <= m; i++) cnt[i] = 1;
  vector<vector<int> > divisors;
  vector<int> mob;
  f(m, divisors, mob);
  dp[1] = 1;
  for (int i = 2; i <= m; i++) {
    dp[i] = 0;
    for (auto div : divisors[i]) {
      if (div == i) continue;
      dp[i] += (dp[div] * cop(i / div, m / div, mob, divisors)) % MOD;
      dp[i] %= MOD;
    }
    dp[i] *= modinv(m);
    dp[i] %= MOD;
    dp[i] += 1;
    dp[i] *= m;
    dp[i] %= MOD;
    dp[i] *= modinv(m - cop(1, m / i, mob, divisors));
    dp[i] %= MOD;
  }
  long long ans = 0;
  for (int i = 1; i <= m; i++) ans = (ans + dp[i]) % MOD;
  ans = (ans * modinv(m)) % MOD;
  if (ans < 0) ans += MOD;
  cout << ans << "\n";
}
