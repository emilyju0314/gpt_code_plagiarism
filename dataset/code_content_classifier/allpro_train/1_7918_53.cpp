#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  double a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  if (a[n - 1] >= (0.5) || n == 1) {
    cout << setprecision(15) << a[n - 1] << "\n";
    return 0;
  }
  double ans = 0;
  for (int i = 0; i < n; ++i) {
    double temp = 0;
    for (int j = i; j < n; ++j) {
      double temp1 = 1;
      for (int k = i; k < n; ++k) {
        if (k == j)
          temp1 *= a[k];
        else
          temp1 *= (1 - a[k]);
      }
      temp += temp1;
    }
    ans = max(ans, temp);
  }
  cout << setprecision(15) << ans << "\n";
  return 0;
}
