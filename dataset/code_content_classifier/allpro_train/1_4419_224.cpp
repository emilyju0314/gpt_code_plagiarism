#include <bits/stdc++.h>
using namespace std;
int n, m;
double a[1005], b[1005];
int i, j;
double f = 0;
int main(void) {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) cin >> b[(i + n - 1) % n];
  for (i = n - 1; i > -1; i--) {
    if (b[i] <= 1 || a[i] <= 1) {
      cout << -1;
      return 0;
    }
    f += (m + f) / (b[i] - 1);
    f += (m + f) / (a[i] - 1);
  }
  cout.precision(8);
  cout << f;
  return 0;
}
