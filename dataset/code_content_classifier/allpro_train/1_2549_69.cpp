#include <bits/stdc++.h>
using namespace std;
long long pwr(long long base, long long p, long long mod = (1000000007LL)) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    p /= 2;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int n, m, arr[102], DP[1 << 21];
pair<int, int> moves[25];
int dp(int mask) {
  int done = __builtin_popcount(mask);
  if (done == m) return 0;
  int &ans = DP[mask];
  if (ans != -1) return ans;
  int player = moves[done].second, next_move = moves[done].first;
  if (player == 1) {
    ans = -(1000000007LL);
    for (int i = 0; i < m; i++) {
      if ((mask >> i) & 1) continue;
      if (next_move == 1)
        ans = max(ans, arr[i] + dp(mask | (1 << i)));
      else
        ans = max(ans, dp(mask | (1 << i)));
    }
  } else {
    ans = (1000000007LL);
    for (int i = 0; i < m; i++) {
      if ((mask >> i) & 1) continue;
      if (next_move == 1)
        ans = min(ans, -arr[i] + dp(mask | (1 << i)));
      else
        ans = min(ans, dp(mask | (1 << i)));
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n, greater<int>());
  cin >> m;
  char str[2];
  for (int i = 0; i < m; i++) {
    int player;
    cin >> str >> player;
    if (str[0] == 'p')
      moves[i] = {1, player};
    else
      moves[i] = {-1, player};
  }
  memset(DP, -1, sizeof(DP));
  cout << dp(0);
  return 0;
}
