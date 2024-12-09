#include <bits/stdc++.h>
using namespace std;
int a[210000];
long long dp[210000][2];
const long long INF = 1LL << 60;
int N;
long long solve(int x, bool t) {
  if (x <= 0 || x > N) return 0;
  if (x == 1) return -1;
  if (dp[x][t] == -INF) return dp[x][t] = -1;
  if (dp[x][t] != INF) return dp[x][t];
  dp[x][t] = -INF;
  int i2 = x;
  if (t)
    i2 += a[x];
  else
    i2 -= a[x];
  long long r = solve(i2, !t);
  long long res;
  if (r == -1)
    res = -1;
  else
    res = a[x] + r;
  return dp[x][t] = res;
}
int main() {
  for (int i = 0; i < 210000; i++)
    for (int j = 0; j < 2; j++) dp[i][j] = INF;
  cin >> N;
  for (int i = 0; i < N - 1; i++) cin >> a[i + 2];
  for (int i = 1; i < N; i++) {
    long long r = solve(1 + i, 0);
    if (r != -1) r += i;
    cout << r << endl;
  }
  return 0;
}
