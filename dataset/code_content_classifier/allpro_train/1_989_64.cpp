#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long n, sum = 0, ans = 1e15;
long long a[N], f[5], curf[5], havef[5];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    f[a[i]]++;
    sum += a[i];
  }
  for (long long fours = 0; fours * 4 <= sum; fours++) {
    if ((sum - (fours * 4)) % 3 != 0) continue;
    curf[4] = fours;
    curf[3] = (sum - (fours * 4)) / 3;
    curf[0] = n - curf[4] - curf[3];
    for (long long j = 0; j <= 4; j++) havef[j] = f[j];
    long long curans = 0, diff = 0;
    long long i = 4, j = 4;
    while (i >= 0 && j >= 0) {
      long long take = min(curf[i], havef[j]);
      curf[i] -= take;
      havef[j] -= take;
      diff += take * abs(i - j);
      if (curf[i] == 0) i--;
      if (havef[j] == 0) j--;
    }
    curans = diff / 2;
    ans = min(ans, curans);
  }
  if (ans == 1e15) ans = -1;
  cout << ans;
  return 0;
}
