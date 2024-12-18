#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100000], b[100000];
  cin >> n;
  if (n < 3) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b, b + n);
  for (int i = 0; i < n; i++) {
    if (i + 1 < n && a[i] == a[i + 1]) continue;
    for (int j = i + 1; j < n; j++) {
      if (a[i] == a[j]) continue;
      swap(a[i], a[j]);
      bool bf = true, cf = true;
      for (int k = 0; k < n; k++) {
        if (a[k] != b[k]) bf = false;
        if (a[k] != b[n - 1 - k]) cf = false;
      }
      if (!bf && !cf) {
        cout << (i + 1) << " " << (j + 1) << endl;
        return 0;
      }
      swap(a[i], a[j]);
    }
  }
  cout << -1 << endl;
}
