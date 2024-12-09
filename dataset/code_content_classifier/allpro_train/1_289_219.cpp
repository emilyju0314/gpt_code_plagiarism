#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int a[500000];
long long ans = 0;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[++m];
    while (m > 2 && a[m - 1] <= min(a[m - 2], a[m])) {
      ans += min(a[m - 2], a[m]);
      a[m - 1] = a[m];
      m--;
    }
  }
  for (int i = 1; i < m; i++) {
    ans += min(a[i - 1], a[i + 1]);
  }
  cout << ans;
}
