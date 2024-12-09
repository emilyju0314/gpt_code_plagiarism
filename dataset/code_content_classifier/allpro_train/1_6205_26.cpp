#include <bits/stdc++.h>
using namespace std;
long long n, l;
long long freq[400050], a[400050], b[200050];
bool check(long long m) {
  memset(freq, 0, sizeof freq);
  for (int i = 0; i < n; i++) {
    long long lef = b[i] - m;
    long long righ = b[i] + m;
    if (lef < 0) {
      lef += l;
      righ += l;
    }
    int ul = lower_bound(a, a + 2 * n, lef) - a;
    int ur = upper_bound(a, a + 2 * n, righ) - a - 1;
    ur = min((long long)ur, ul + n - 1);
    if (ul > ur) return 0;
    ul -= i;
    ur -= i;
    if (ul < 0) {
      ul += n, ur += n;
    }
    freq[ul]++;
    freq[ur + 1]--;
  }
  for (int i = 1; i < 2 * n; i++) freq[i] += freq[i - 1];
  for (int i = 0; i < n; i++) {
    if (freq[i] + freq[i + n] == n) return 1;
  }
  return 0;
}
int main() {
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++) a[i + n] = a[i] + l;
  sort(b, b + n);
  long long st = 0, nd = l;
  long long ans = 0;
  while (st <= nd) {
    long long mid = (st + nd) / 2;
    if (check(mid)) {
      ans = mid;
      nd = mid - 1;
    } else
      st = mid + 1;
  }
  cout << ans << endl;
  return 0;
}
