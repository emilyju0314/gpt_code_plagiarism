#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt = 0, t;
  cin >> t;
  while (t--) {
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
      if (a[i] != a[i + 1]) cnt++;
    }
    cout << cnt << endl;
    cnt = 0;
  }
  return 0;
}
