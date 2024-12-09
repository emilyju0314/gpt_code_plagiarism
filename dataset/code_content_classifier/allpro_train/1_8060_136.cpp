#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  long long res = 1LL;
  while (b > 0) {
    if (b & 1) res = (res * a) % 998244353;
    b /= 2;
    a = ((a % 998244353) * (a % 998244353)) % 998244353;
  }
  return res % 998244353;
}
long long n, k;
long long ans;
long long arr[500005];
long long dp[500005][2];
void rec(vector<long long> v) {
  long long prev = 0;
  long long cnt = 0;
  for (auto i : v) {
    if (i == -1) {
      cnt++;
      continue;
    }
    if (prev == i && cnt == 0) {
      ans = 0;
      return;
    }
    if (cnt > 0) {
      if (prev == 0)
        ans = (ans * power(k - 1, cnt)) % 998244353;
      else if (i == prev)
        ans = (ans * (dp[cnt][0])) % 998244353;
      else
        ans = (ans * dp[cnt][1]) % 998244353;
    }
    cnt = 0;
    prev = i;
  }
  if (cnt) {
    if (prev == 0)
      ans = (ans * ((k * power(k - 1, cnt - 1)) % 998244353)) % 998244353;
    else
      ans = (ans * power(k - 1, cnt)) % 998244353;
  }
}
void the_phoenixx() {
  cin >> n >> k;
  dp[1][0] = k - 1;
  dp[1][1] = k - 2;
  for (long long i = 2; i <= n; i++) {
    dp[i][0] = (power(k - 1, i) - dp[i - 1][0] + 998244353) % 998244353;
    dp[i][1] = (power(k - 1, i) - dp[i - 1][1] + 998244353) % 998244353;
  }
  ans = 1LL;
  for (long long i = 1; i <= n; i++) cin >> arr[i];
  vector<long long> v1, v2;
  for (long long i = 1; i <= n; i++) {
    if (i & 1)
      v1.push_back(arr[i]);
    else
      v2.push_back(arr[i]);
  }
  rec(v1);
  rec(v2);
  cout << ans << endl;
}
int main() {
  long long t;
  t = 1;
  while (t--) {
    the_phoenixx();
  }
  return 0;
}
