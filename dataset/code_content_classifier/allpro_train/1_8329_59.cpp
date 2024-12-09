#include <bits/stdc++.h>
using namespace std;
long long solve() {
  long long ans = 0;
  long long n;
  cin >> n;
  long long m;
  cin >> m;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
  }
  long long b[m];
  for (long long i = 0; i < m; i++) {
    cin >> b[i];
    --b[i];
  }
  vector<long long> location(n + 1, 0), order(n + 1, INT_MAX);
  for (long long i = 0; i < n; i++) location[a[i]] = i;
  for (long long i = 0; i < m; i++) order[b[i]] = i;
  long long max_pos = -1;
  for (long long i = 0; i < m; i++) {
    long long l = b[i];
    long long pos = location[l];
    if (pos <= max_pos) {
      ans++;
      continue;
    }
    max_pos = pos;
    ans += 2 * (pos - i) + 1;
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }
  return 0;
}
