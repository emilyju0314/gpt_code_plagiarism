#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int b[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    long long a[n + 1];
    long long maxi = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      maxi = max(a[i], maxi);
    }
    if (a[n] == maxi)
      cout << "0"
           << "\n";
    else {
      long long maxi = a[n];
      long long cnt = 0;
      for (int i = n; i >= 1; i--) {
        if (a[i] > maxi) {
          maxi = a[i];
          cnt++;
        }
      }
      cout << cnt << "\n";
    }
  }
  return 0;
}
