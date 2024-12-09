#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000000 + 7;
struct point {
  long long x, y;
  point() {}
  point(long long x, long long y) { this->x = x, this->y = y; }
  long long operator^(const point& p) { return x * p.y - p.x * y; }
  point operator-(const point& p) {
    point t;
    t.x = this->x - p.x, t.y = this->y - p.y;
    return t;
  }
};
point p[222];
long long dp[222][222];
int MAIN() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  long long area = 0;
  for (int i = 0; i < n; i++) {
    area += p[i] ^ p[(i + 1) % n];
  }
  if (area < 0) {
    reverse(p, p + n);
  }
  for (int l = 1; l < n; l++) {
    for (int i = 0; i + l < n; i++) {
      if (l == 1) {
        dp[i][i + l] = 1;
        continue;
      }
      int j = i + l;
      for (int k = i + 1; k < j; k++) {
        point a = p[k] - p[i], b = p[k] - p[j];
        if ((a ^ b) < 0) {
          dp[i][j] += (dp[i][k] * dp[k][j]) % MOD;
          dp[i][j] %= MOD;
        }
      }
    }
  }
  cout << dp[0][n - 1] << endl;
  return 0;
}
int main() {
  ios ::sync_with_stdio(false);
  cout << fixed << setprecision(16);
  return MAIN();
}
