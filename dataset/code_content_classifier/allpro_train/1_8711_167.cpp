#include <bits/stdc++.h>
using namespace std;
long long b, m, ans;
long long calc(long long x, long long y) {
  return (x + 1) * y * (y + 1) / 2 + (y + 1) * x * (x + 1) / 2;
}
int main() {
  cin >> m >> b;
  for (long long i = 0; i <= b * m; i++)
    ans = max(ans, calc(i, b - (i + m - 1) / m));
  cout << ans << endl;
  return 0;
}
