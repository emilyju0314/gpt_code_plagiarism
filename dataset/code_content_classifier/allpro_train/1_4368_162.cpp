#include <bits/stdc++.h>
using namespace std;
int r[3], ans = 0;
int main() {
  int n;
  cin >> n;
  int a[10000 + 5];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = a[i] % 3;
    r[a[i]]++;
  }
  ans = min(r[1], r[2]) + r[0] / 2;
  cout << ans << endl;
  return 0;
}
