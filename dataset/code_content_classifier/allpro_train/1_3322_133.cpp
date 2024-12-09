#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
void yash() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      for (long long k = 0; k < n && j != k; k++) {
        if (arr[i] == arr[j] + arr[k]) {
          cout << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
          return;
        }
      }
    }
  }
  cout << "-1\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  yash();
  return 0;
}
