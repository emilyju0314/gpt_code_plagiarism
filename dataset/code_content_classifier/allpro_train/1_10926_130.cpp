#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    long long int f = 0;
    while (2) {
      f = 0;
      for (long long int i = 0; i < n; i++) {
        for (long long int j = i + 1; j < n; j++) {
          if (i - a[i] == j - a[j]) {
            f = 1;
            reverse(a + i, a + j + 1);
            break;
          }
        }
        if (f == 1) break;
      }
      if (f == 0) break;
    }
    for (long long int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
