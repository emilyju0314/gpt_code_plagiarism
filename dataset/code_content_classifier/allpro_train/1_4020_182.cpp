#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  long long m;
  cin >> m;
  long long k;
  cin >> k;
  vector<long long> q(m);
  for (long long i = 0; i < m; i++) cin >> q[i];
  vector<long long> w(k);
  for (long long i = 0; i < k; i++) cin >> w[i];
  vector<pair<long long, long long> > e(m);
  for (long long i = 0; i < m; i++) {
    long long c = 0;
    for (long long j = 0; j < k; j++) {
      if (w[j] % q[i] == 0) c++;
    }
    e[i] = make_pair(c, i);
  }
  n = -1;
  sort(e.begin(), e.end());
  for (long long i = 0; i < m; i++)
    if (e[i].first != e[0].first) {
      n = i;
      break;
    }
  if (n == -1) n = e.size();
  cout << n << "\n";
  for (long long i = 0; i < n; i++) cout << e[i].second + 1 << " ";
  return 0;
}
