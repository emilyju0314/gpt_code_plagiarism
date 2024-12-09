#include <bits/stdc++.h>
using namespace std;
static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
long long int power(long long int base, long long int p) {
  long long int ans = 1;
  while (p) {
    if (p & 1) ans = (ans * base);
    base = (base * base);
    p /= 2;
  }
  return ans;
}
long long int modPower(long long int base, long long int p, long long int mod) {
  long long int ans = 1;
  while (p) {
    if (p & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    p /= 2;
  }
  return ans;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int n;
long long int dp[100][3];
long long int a[1000005];
long long int solveForBob(int index, bool player) {
  if (index == n) return 0;
  long long int &res = dp[index][player];
  if (res != -1)
    return res;
  else if (player) {
    res = max(a[index] + solveForBob(index + 1, !player),
              solveForBob(index + 1, player));
  } else {
    res = min(a[index] + solveForBob(index + 1, player),
              solveForBob(index + 1, !player));
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 99; ++i) {
    for (int j = 0; j < 2; ++j) {
      dp[i][j] = -1;
    }
  }
  cin >> n;
  long long int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += 1ll * a[i];
  }
  long long int ans = solveForBob(0, 1);
  cout << sum - ans << " " << ans << endl;
}
