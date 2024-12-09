#include <bits/stdc++.h>
using namespace std;
const double _ = 1e-10;
int n, a, b, numa[100010], numb[100010];
double p[100010], q[100010], dp[100010];
void Check(double ca, double cb) {
  for (int i = 1; i <= n; i++) {
    dp[i] = 0;
    numa[i] = 0;
    numb[i] = 0;
    dp[i] = dp[i - 1];
    numa[i] = numa[i - 1];
    numb[i] = numb[i - 1];
    if (dp[i] < dp[i - 1] + p[i] - ca - _) {
      dp[i] = dp[i - 1] + p[i] - ca;
      numa[i] = numa[i - 1] + 1;
      numb[i] = numb[i - 1];
    }
    if (dp[i] < dp[i - 1] + q[i] - cb - _) {
      dp[i] = dp[i - 1] + q[i] - cb;
      numa[i] = numa[i - 1];
      numb[i] = numb[i - 1] + 1;
    }
    if (dp[i] < dp[i - 1] + p[i] - ca + q[i] - cb - p[i] * q[i] - _) {
      dp[i] = dp[i - 1] + p[i] - ca + q[i] - cb - p[i] * q[i];
      numa[i] = numa[i - 1] + 1;
      numb[i] = numb[i - 1] + 1;
    }
  }
}
double check(double co) {
  double l = 0, r = 1, mid;
  for (int i = 1; i <= 50; i++) {
    mid = (l + r) / 2;
    Check(co, mid);
    if (numb[n] > b) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}
double l, r, mid, v, ans;
int main() {
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &p[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &q[i]);
  }
  l = 0;
  r = 1;
  for (int i = 1; i <= 50; i++) {
    mid = (l + r) / 2;
    v = check(mid);
    if (numa[n] > a) {
      l = mid;
    } else {
      r = mid;
    }
  }
  Check(l, v);
  printf("%.5lf\n", dp[n] + l * a + v * b);
  return 0;
}
