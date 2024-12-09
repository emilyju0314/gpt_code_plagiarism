#include <bits/stdc++.h>
using namespace std;
int n, d, cnt[30010], dp[30010][511];
int cntt = 0;
int func(int curr, int jump) {
  if (jump <= 0) {
    return 0;
  }
  if (curr > 30000) return 0;
  int idx = (jump - (d - 250));
  if (dp[curr][idx] != -1) return dp[curr][idx];
  if (jump == 1) {
    dp[curr][idx] = cnt[curr] + max(func(curr + jump, jump),
                                    func(curr + jump + 1, jump + 1));
  } else {
    dp[curr][idx] = cnt[curr] + max(func(curr + jump - 1, jump - 1),
                                    max(func(curr + jump, jump),
                                        func(curr + jump + 1, jump + 1)));
  }
  return dp[curr][idx];
}
int main() {
  int i, j, k;
  scanf("%d", &n);
  scanf("%d", &d);
  memset(cnt, 0, sizeof(cnt));
  memset(dp, -1, sizeof(dp));
  for (i = 0; i < n; i++) {
    int temp;
    scanf("%d", &temp);
    cnt[temp]++;
  }
  int ans = func(d, d);
  cout << ans << endl;
  return 0;
}
