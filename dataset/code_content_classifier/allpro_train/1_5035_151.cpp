#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    long long int a[n];
    long long int s = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      s += a[i];
    }
    if (s > m) {
      cout << m << "\n";
    } else {
      cout << s << "\n";
    }
  }
}
