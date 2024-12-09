#include <bits/stdc++.h>
using namespace std;
int n;
pair<pair<double, double>, double> fl[(20) + 1];
double p, q, mx, dp[1 << (20)];
double f(int i, double p) {
  double alpha = atan2(fl[i].first.second, fl[i].first.first - p);
  double alpha2 = (acos(-1)) / 2 - alpha - fl[i].second;
  double goback = tan(alpha2) * (fl[i].first.second);
  double go = fl[i].first.first - goback;
  return go;
}
double f2(int i, double p) {
  if ((abs(fl[i].second - (acos(-1)) / 2) <= 1e-6)) return q;
  double alpha = atan2(p - fl[i].first.first, fl[i].first.second);
  double alpha2 = (acos(-1)) / 2 - alpha - fl[i].second;
  if (alpha2 <= 1e-6) return q;
  double go = 1 / tan(alpha2) * fl[i].first.second + fl[i].first.first;
  return go;
}
double calc(int i, double p) {
  if (fl[i].first.first < p) return f2(i, p);
  return f(i, p);
}
int main() {
  cin >> n >> p >> q;
  for (int i = 1; i <= n; i++) {
    cin >> fl[i].first.first >> fl[i].first.second >> fl[i].second;
    fl[i].second = fl[i].second * (acos(-1)) / 180;
  }
  for (int i = 1; i <= (1 << n) - 1; i++) dp[i] = -((int)(1e9 + 5));
  dp[0] = p;
  for (int i = 0; i <= (1 << n) - 1; i++)
    for (int j = 1; j <= n; j++)
      if (!(i & (1 << j - 1)))
        dp[i | 1 << j - 1] = max(dp[i | 1 << j - 1], calc(j, dp[i]));
  printf("%.9lf\n", min(dp[(1 << n) - 1], q) - p);
  return 0;
}
