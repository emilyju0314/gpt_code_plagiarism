#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int amin = *min_element(a, a + n);
    int bmin = *min_element(b, b + n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int da = a[i] - amin;
      int db = b[i] - bmin;
      ans += max(da, db);
    }
    cout << ans << endl;
  }
}
