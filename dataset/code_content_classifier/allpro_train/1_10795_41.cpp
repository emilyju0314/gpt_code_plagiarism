#include <bits/stdc++.h>
using namespace std;
long long n, t;
int main() {
  long long i, a, sum = 0, ans = 0;
  cin >> n >> t;
  for (i = 0; i < n; i++) {
    cin >> a;
    if (t > 0) ans++;
    t -= (86400 - a);
  }
  cout << ans << endl;
  return 0;
}
