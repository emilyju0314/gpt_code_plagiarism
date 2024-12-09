#include <bits/stdc++.h>
using namespace std;
int sum_string(string S) {
  int ans = 0;
  for (int i = 0; i < S.size(); i++) ans += S[i] - 'a';
  return ans;
}
int dp[105][3000];
int solve(int L, int C) {
  if (L == 0) return (C == 0);
  if (dp[L][C] != -1) return dp[L][C];
  dp[L][C] = 0;
  for (int x = 0; x < 26 && x <= C; x++) {
    dp[L][C] += solve(L - 1, C - x);
    dp[L][C] %= 1000000007;
  }
  return dp[L][C];
}
int main() {
  int T;
  scanf("%d", &T);
  char S1[105];
  for (int i = 0; i < 105; i++)
    for (int j = 0; j < 3000; j++) dp[i][j] = -1;
  while (T--) {
    scanf("%s", S1);
    string S(S1);
    int v = solve(S.size(), sum_string(S));
    v = (v - 1 + 1000000007) % 1000000007;
    printf("%d\n", v);
  }
  return 0;
}
