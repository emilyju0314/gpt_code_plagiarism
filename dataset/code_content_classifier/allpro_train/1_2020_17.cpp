#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> a(n), left(n), right(n), odd(n), even(n), sumOdd(n);
  for (int i = 0; i < n - 1; ++i) cin >> a[i];
  for (int i = 1; i < n; ++i) {
    odd[i] = (a[i - 1] & 1) ? a[i - 1] : (a[i - 1] - 1);
    even[i] = (a[i - 1] % 2 == 0) ? a[i - 1] : (a[i - 1] - 1);
    if (a[i - 1] > 1) {
      left[i] = left[i - 1] + even[i];
    }
    sumOdd[i] = sumOdd[i - 1] + odd[i];
  }
  for (int j = n - 2; j >= 0; --j) {
    if (a[j] > 1) {
      right[j] = right[j + 1] + even[j + 1];
    }
  }
  long long mx = 0, ans = 0;
  for (int j = 0; j < n; ++j) {
    mx = max(mx, left[j] - sumOdd[j]);
    ans = max(ans, mx + right[j] + sumOdd[j]);
  }
  cout << ans << endl;
  return 0;
}
