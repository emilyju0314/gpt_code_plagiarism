#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t = 1;
  while (t--) {
    long long int n;
    cin >> n;
    long long int b[n];
    for (int i = 0; i < n; i++) cin >> b[i];
    long long int a[n], x[n];
    a[0] = b[0];
    x[0] = 0;
    long long int m = 0;
    for (int i = 0; i < n; i++) {
      a[i] = b[i] + m;
      m = max(m, a[i]);
      cout << a[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
