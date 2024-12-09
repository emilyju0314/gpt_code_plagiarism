#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int mx = a[n - 3] + a[n - 2];
  if (mx > a[n - 1]) {
    cout << "YES" << endl;
    for (int i = 0; i < n - 3; i++) {
      cout << a[i] << " ";
    }
    cout << a[n - 2] << " " << a[n - 1] << " " << a[n - 3] << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
