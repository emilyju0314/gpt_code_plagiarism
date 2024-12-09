#include <bits/stdc++.h>
using namespace std;
long long dp[40][20][20];
int n;
long long p[30];
string x;
long long calc(int idx, int a, int b) {
  if (idx == n * 2) return 0;
  long long &ret = dp[idx][a][b];
  if (ret != -1) return ret;
  ret = 0;
  if (a) ret = max(ret, calc(idx + 1, a - 1, b) + (x[idx] - '0') * p[a - 1]);
  if (b) ret = max(ret, calc(idx + 1, a, b - 1) + (x[idx] - '0') * p[b - 1]);
  return ret;
}
void build(int idx, int a, int b) {
  if (idx == n * 2) return;
  if (dp[idx + 1][a - 1][b] + (x[idx] - '0') * p[a - 1] == dp[idx][a][b]) {
    cout << "H";
    build(idx + 1, a - 1, b);
  } else {
    cout << "M";
    build(idx + 1, a, b - 1);
  }
}
int main() {
  memset(dp, -1, sizeof dp);
  cin >> n >> x;
  p[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] * 10;
  calc(0, n, n);
  build(0, n, n);
  return 0;
}
