#include <bits/stdc++.h>
using namespace std;
char s[10];
int n, h;
int main() {
  ios::sync_with_stdio(false);
  cin >> s >> n >> h;
  if (s[0] == 'B') {
    cout << n << endl;
    return 0;
  }
  double ans = n, pw = 1;
  for (int i = 1; i <= h; i++) {
    pw *= 2;
    double cur = 1;
    for (int j = 1; j <= n; j++)
      ans += (n - j) * cur / pw / pw * (pw - pw / 2 * (1 + (j - 1) / (pw - 1))),
          cur *= 1 - 1 / pw;
  }
  printf("%.12lf\n", ans);
  return 0;
}
