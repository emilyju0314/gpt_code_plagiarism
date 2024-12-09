#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int botlsiz[N], arr[N];
map<int, pair<int, int>> dp[N];
int n;
pair<int, int> solve(int i, int c) {
  if (i == n)
    if (c >= 0)
      return {0, 0};
    else
      return {1e6, 1e6};
  if (dp[i].count(c)) return dp[i][c];
  auto ans = solve(i + 1, c + arr[i]);
  ans.first += 1;
  auto tmp = solve(i + 1, c - botlsiz[i]);
  tmp.second += botlsiz[i];
  ans = min(ans, tmp);
  return dp[i][c] = ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", botlsiz + i);
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
    arr[i] -= botlsiz[i];
  }
  auto ans = solve(0, 0);
  printf("%d %d\n", ans.first, ans.second);
  return 0;
}
