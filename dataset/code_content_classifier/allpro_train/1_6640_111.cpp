#include <bits/stdc++.h>
using namespace std;
bitset<2001> rain;
int weights[2001];
pair<int, int> umbrellas[2001];
int dp[2001][2001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int A, N, M;
  cin >> A >> N >> M;
  for (int i = 0; i < N; ++i) {
    int l, r;
    cin >> l >> r;
    for (int j = l; j < r; ++j) rain.set(j);
  }
  weights[0] = 0;
  for (int i = 0; i < 2001; ++i) umbrellas[i] = make_pair(1000000000, -1);
  for (int i = 1; i < M + 1; ++i) {
    int x, p;
    cin >> x >> p;
    weights[i] = p;
    umbrellas[x] = min(umbrellas[x], make_pair(p, i));
  }
  for (int i = 0; i < 2001; ++i)
    for (int j = 0; j < 2001; ++j) dp[i][j] = 1000000000;
  dp[0][0] = 0;
  for (int x = 1; x < A + 1; ++x) {
    for (int i = 0; i < M + 1; ++i) {
      if (i) {
        dp[x][i] = min(dp[x][i], dp[x - 1][i] + weights[i]);
      }
      if (!rain.test(x - 1)) {
        dp[x][0] = min(dp[x][0], dp[x - 1][i]);
      }
      if (umbrellas[x - 1].first != 1000000000) {
        dp[x][umbrellas[x - 1].second] =
            min(dp[x][umbrellas[x - 1].second],
                dp[x - 1][i] + umbrellas[x - 1].first);
      }
    }
  }
  int ans = 1000000000;
  for (int i = 0; i < M + 1; ++i) ans = min(ans, dp[A][i]);
  if (ans == 1000000000) ans = -1;
  cout << ans << "\n";
  return 0;
}
