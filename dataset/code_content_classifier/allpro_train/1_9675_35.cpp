#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long r[200005];
long long o[200005];
long long w[200005];
long long n, k;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long cntr = 0;
  long long cntw = 0;
  long long cnto = 0;
  for (long long i = 1; i <= n; i++) {
    char x;
    cin >> x;
    if (x == 'R') {
      r[++cntr] = a[i];
    } else if (x == 'O') {
      o[++cnto] = a[i];
    } else
      w[++cntw] = a[i];
  }
  sort(r + 1, r + 1 + cntr, greater<long long>());
  sort(o + 1, o + 1 + cnto, greater<long long>());
  sort(w + 1, w + 1 + cntw, greater<long long>());
  for (long long i = 1; i <= n; i++) {
    r[i] += r[i - 1];
    if (i > cntr) r[i] = -1e9;
  }
  for (long long i = 1; i <= n; i++) {
    o[i] += o[i - 1];
    if (i > cnto) o[i] = -1e9;
  }
  for (long long i = 1; i <= n; i++) {
    w[i] += w[i - 1];
    if (i > cntw) w[i] = -1e9;
  }
  long long ans = -1;
  for (long long i = 1; i < k; i++) {
    long long cur = o[i] + max(r[k - i], w[k - i]);
    ans = max(ans, cur);
  }
  cout << ans;
  return 0;
}
