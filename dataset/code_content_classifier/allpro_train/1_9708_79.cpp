#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, h, s, sum = 0;
  cin >> n >> m >> h;
  h--;
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    sum += a;
    if (i == h) s = a;
  }
  long double ans = 1;
  if (sum >= n) {
    int p[2] = {sum - s - n + 2, sum - s + 1};
    while (p[0] <= sum - n || p[1] <= sum - 1) {
      long double q;
      if (p[0] > sum - n) {
        q = (long double)1 / p[1];
        p[1]++;
      } else if (p[1] > sum - 1) {
        q = (long double)p[0];
        p[0]++;
      } else {
        q = (long double)p[0] / p[1];
        p[0]++;
        p[1]++;
      }
      ans *= q;
    }
    ans = 1 - ans;
  } else
    ans = -1;
  if (ans == (long double)-1)
    cout << fixed << setprecision(0) << ans << endl;
  else
    cout << fixed << setprecision(6) << ans << endl;
  return 0;
}
