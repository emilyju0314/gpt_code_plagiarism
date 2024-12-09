#include <bits/stdc++.h>
int kx[8] = {+2, +2, -2, -2, +1, +1, -1, -1};
int ky[8] = {+1, -1, +1, -1, +2, -2, +2, -2};
int d9x[9] = {+1, +1, +1, +0, +0, +0, -1, -1, -1};
int d9y[9] = {+1, +0, -1, +1, +0, -1, +1, +0, -1};
int dx4[4] = {+0, +0, +1, -1};
int dy4[4] = {+1, -1, +0, +0};
long long int gcd(unsigned long long int a, unsigned long long int b) {
  return (a == 0) ? b : gcd(b % a, a);
}
long long int lcm(unsigned long long int a, unsigned long long int b) {
  return a * (b / gcd(a, b));
}
const long long INF = 1e18;
using namespace std;
long long int h[500001];
long long int dp[500001][2];
int L[500001];
int R[500001];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  if (n == 1) {
    cout << h[0] << endl;
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    int pos = i - 1;
    while (true) {
      if (pos == -1) {
        L[i] = -1;
        break;
      } else {
        if (h[pos] <= h[i]) {
          L[i] = pos;
          break;
        } else {
          pos = L[pos];
        }
      }
    }
  }
  for (int i = n - 1; ~i; --i) {
    int pos = i + 1;
    while (true) {
      if (pos == n) {
        R[i] = n;
        break;
      } else {
        if (h[pos] <= h[i]) {
          R[i] = pos;
          break;
        } else {
          pos = R[pos];
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    dp[i][0] = 0ll;
    dp[i][0] += h[i] * (i - L[i]);
    if (L[i] != -1) {
      dp[i][0] += dp[L[i]][0];
    }
  }
  for (int i = n - 1; ~i; --i) {
    dp[i][1] = 0ll;
    dp[i][1] += h[i] * (R[i] - i);
    if (R[i] != n) {
      dp[i][1] += dp[R[i]][1];
    }
  }
  pair<int, long long int> best = make_pair(-1, -1ll);
  for (int i = 0; i < n - 1; ++i) {
    if (dp[i][0] + dp[i + 1][1] > best.second) {
      best.first = i;
      best.second = dp[i][0] + dp[i + 1][1];
    }
  }
  long long int ans[n];
  ans[best.first] = h[best.first];
  for (int i = best.first - 1; ~i; --i) {
    ans[i] = min(h[i], ans[i + 1]);
  }
  for (int i = best.first + 1; i < n; ++i) {
    if (i == best.first + 1) {
      ans[i] = h[i];
    } else {
      ans[i] = min(h[i], ans[i - 1]);
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}
