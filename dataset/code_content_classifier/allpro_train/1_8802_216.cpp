#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  long double m, a, b;
  long double ans = 1e9;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    ans = min(ans, m * a / b);
  }
  cout << fixed << setprecision(10);
  cout << ans << endl;
}
