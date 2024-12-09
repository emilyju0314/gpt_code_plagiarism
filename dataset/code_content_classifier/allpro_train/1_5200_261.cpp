#include <bits/stdc++.h>
using namespace std;
const int M4 = 1e4 + 10, M5 = 1e5 + 10, M6 = 1e6 + 10;
int a[M5 * 4];
int ted[2][(1 << 21) + 10];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int X = 0;
  long long ans = 0;
  ted[1][0]++;
  for (int i = 0; i < n; i++) {
    X = X ^ a[i];
    ans += ted[i % 2][X];
    ted[i % 2][X]++;
  }
  cout << ans;
  return 0;
}
