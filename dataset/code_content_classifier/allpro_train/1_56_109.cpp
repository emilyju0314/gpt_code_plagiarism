#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, k, cur = 0, ans = 999999999999999;
  cin >> n >> m >> k;
  long long b[m], pre[n], c[k + 1];
  memset(pre, 0, sizeof(pre));
  for (long long i = 0; i < m; i++) {
    cin >> b[i];
    pre[b[i]] = 1;
  }
  for (long long i = 1; i <= k; i++) cin >> c[i];
  for (long long i = 0; i < n; i++) {
    if (pre[i] == 0)
      pre[i] = i;
    else {
      if (i == 0) {
        cout << -1 << endl;
        exit(0);
      } else
        pre[i] = pre[i - 1];
    }
  }
  long long mx = -999999999999999999;
  for (long long i = 0; i < n; i++) mx = max(mx, i - pre[i]);
  mx++;
  if (mx > k) {
    cout << -1 << endl;
    exit(0);
  }
  for (long long i = mx; i <= k; i++) {
    long long ret = 0;
    long long j = 0;
    while (j < n) {
      if (j == pre[j]) {
        ret += c[i];
        j += i;
      } else
        j = pre[j];
    }
    ans = min(ret, ans);
  }
  cout << ans << endl;
  return 0;
}
