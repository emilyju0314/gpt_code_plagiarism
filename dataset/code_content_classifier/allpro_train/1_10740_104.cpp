#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, k, ans = 0, flag = -1, p = 0, sum = 0;
  cin >> n >> k;
  long long a[n], i, b[n];
  map<long long, long long> m;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(a, a + n);
  reverse(a, a + n);
  for (i = 0; i < k; i++) {
    ans += a[i];
    m[a[i]]++;
  }
  cout << ans << endl;
  sum = n;
  flag = 0;
  for (i = 0; i < n; i++) {
    p++;
    if (k == 1) break;
    if (m[b[i]] > 0) {
      cout << p << " ";
      sum -= p;
      k--;
      p = 0;
      m[b[i]]--;
    }
  }
  if (sum) cout << sum;
  return 0;
}
