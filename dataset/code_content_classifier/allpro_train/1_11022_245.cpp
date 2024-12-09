#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int a[2005];
int r[2005];
int find(int s) {
  if (a[s] == s)
    return s;
  else
    return a[s] = find(a[s]);
}
void merge(int s, int t) {
  int ps = find(s), pt = find(t);
  if (r[ps] > r[pt]) {
    a[pt] = ps;
  } else if (r[ps] < r[pt]) {
    a[ps] = pt;
  } else {
    a[pt] = ps;
    ++r[ps];
  }
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    a[i] = i;
    r[i] = 1;
  }
  for (int i = 0; i < n - k + 1; ++i) {
    for (int j = 0; j < k; ++j) {
      merge(i + j, i + k - 1 - j);
    }
  }
  int count = 0;
  for (int i = 0; i < n; ++i) count += a[i] == i;
  if (count == 0)
    cout << 0 << endl;
  else {
    long long ans = 1;
    for (int i = 0; i < count; ++i) ans = ans * m % mod;
    cout << ans << endl;
  }
  return 0;
}
