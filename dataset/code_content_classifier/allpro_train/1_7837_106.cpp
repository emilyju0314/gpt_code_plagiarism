#include <bits/stdc++.h>
using namespace std;
int num[100005];
int dp[100005];
int main() {
  int n, a, ans = -1;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a);
    num[a] = i;
    num[a] = num[a - 1] + 1;
    ans = max(ans, num[a]);
  }
  printf("%d\n", n - ans);
}
