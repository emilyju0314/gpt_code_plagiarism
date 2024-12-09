#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long A, B;
long long ans = 1e18;
long long dp[1100000][3];
int a[2000000], n;
vector<int> v1;
void gcd(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      v1.push_back(i);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) v1.push_back(x);
}
void javab(int x) {
  int k, j;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i][1] = dp[i][2] = 1e18;
    int s = -1;
    if (a[i - 1] % x == 0)
      s = 0;
    else if ((a[i - 1] + 1) % x == 0 || (a[i - 1] - 1) % x == 0)
      s = 1;
    if (s != -1) {
      dp[i][0] = dp[i - 1][0] + B * (long long)(s);
      dp[i][2] = dp[i - 1][2] + B * (long long)(s);
      dp[i][2] = min(dp[i][2], dp[i - 1][0] + B * (long long)(s));
      dp[i][2] = min(dp[i][2], dp[i - 1][1] + B * (long long)(s));
    }
    dp[i][1] = dp[i - 1][1] + A;
    dp[i][1] = min(dp[i][1], dp[i - 1][0] + A);
  }
  long long q = min(dp[n][0], dp[n][1]);
  q = min(q, dp[n][2]);
  ans = min(ans, q);
}
int main() {
  cin >> n >> A >> B;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  gcd(a[0]);
  gcd(a[0] - 1);
  gcd(a[0] + 1);
  gcd(a[n - 1]);
  gcd(a[n - 1] + 1);
  gcd(a[n - 1] - 1);
  sort(v1.begin(), v1.end());
  vector<int> v2;
  v2.push_back(v1[0]);
  for (int i = 1; i < v1.size(); i++)
    if (v1[i] != v1[i - 1]) v2.push_back(v1[i]);
  v1 = v2;
  for (int i = 0; i < v1.size(); i++) javab(v1[i]);
  cout << ans;
}
