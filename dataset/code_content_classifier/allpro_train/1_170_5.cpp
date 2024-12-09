#include <bits/stdc++.h>
long long MOD = 1e9 + 7;
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  int a[310000];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long sum = 0;
  for (int i = 0; i < n; i++) sum += a[i];
  int mid = (n - 1) / 2;
  if (a[mid] == s) {
    cout << 0;
    return 0;
  }
  if (a[mid] < s) {
    long long ss = 0;
    for (int i = 0; i < mid; i++) {
      ss += a[i];
    }
    for (int i = mid; i <= n - 1; ++i) {
      ss += max(s, a[i]);
    }
    cout << ss - sum;
    return 0;
  } else {
    long long ss = 0;
    for (int i = 0; i < mid + 1; i++) {
      ss += min(a[i], s);
    }
    for (int i = mid + 1; i <= n - 1; ++i) ss += a[i];
    cout << sum - ss;
    return 0;
  }
  return 0;
}
