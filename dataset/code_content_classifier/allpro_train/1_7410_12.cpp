#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int x[N], v[N], n;
double count_time(double p) {
  double ans = 0.0;
  for (int i = 0; i < n; i++) ans = max(ans, abs(p - x[i]) / v[i]);
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n; i++) cin >> v[i];
  double l = 0, r = 2e9;
  for (int i = 0; i < 1000; i++) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    if (count_time(m1) < count_time(m2))
      r = m2;
    else
      l = m1;
  }
  cout.setf(ios::showpoint | ios::fixed);
  cout.precision(12);
  cout << count_time(l) << endl;
  return 0;
}
