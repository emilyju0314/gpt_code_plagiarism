#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    int m = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      m = max(a[i], m);
      sum += a[i];
    }
    if (n == 1 || m > sum - m || sum % 2)
      cout << "T"
           << "\n";
    else
      cout << "HL"
           << "\n";
  }
  return 0;
}
