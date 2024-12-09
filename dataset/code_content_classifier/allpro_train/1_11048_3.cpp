#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
long long dp[10000005];
long long solve(int ele, int n) {
  if (ele < n) return 0;
  if (dp[ele] != -1) return dp[ele];
  long long ans = 1;
  ans = max(ans, solve(ele / 2, n) + solve((ele + 1) / 2, n));
  return dp[ele] = ans;
}
bool check(long long n, long long k) {
  long long ans = 0;
  memset(dp, -1, sizeof dp);
  for (auto ele : a) {
    if (ele < n) break;
    ans += solve((int)ele, (int)n);
    if (ans >= k) return true;
  }
  return false;
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long s = 0;
  for (int i = 0; i < n; i++) {
    int cur;
    scanf("%d", &cur);
    a.push_back(cur);
    s += cur;
  }
  sort(a.rbegin(), a.rend());
  if (s < k) {
    puts("-1");
  } else {
    long long start = 1, end = a[0] + 1;
    while (end - start > 1) {
      long long mid = (start + end) / 2;
      if (check(mid, (long long)k)) {
        start = mid;
      } else {
        end = mid;
      }
    }
    cout << start;
  }
}
