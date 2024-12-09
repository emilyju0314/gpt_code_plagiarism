#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[100], b[100];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i <= n - 1; i++) cin >> a[i];
    for (int i = 0; i <= n - 1; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    cout << a[0];
    for (int i = 1; i <= n - 1; i++) cout << ' ' << a[i];
    cout << '\n';
    cout << b[0];
    for (int i = 1; i <= n - 1; i++) cout << ' ' << b[i];
    cout << '\n';
  }
  return 0;
}
