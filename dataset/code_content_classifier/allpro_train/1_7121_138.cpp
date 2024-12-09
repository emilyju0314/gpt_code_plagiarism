#include <bits/stdc++.h>
using namespace std;
long long cnt[100006];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    long long b[n];
    vector<pair<long long, long long> > v;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (long long j = 0; j < n; j++) {
      cin >> b[j];
    }
    for (long long i = 0; i < n; i++) {
      v.push_back(make_pair(a[i], b[i]));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    long long sum = 0;
    long long pum = v[0].first;
    long long ans = pum;
    long long r = 0;
    for (long long i = 0; i < n - 1; i++) {
      sum += v[i].second;
      if (sum <= pum) {
        pum = max(v[i + 1].first, sum);
        ans = pum;
      }
    }
    sum += v[n - 1].second;
    if (sum <= v[n - 1].first) {
      cout << sum << "\n";
    } else
      cout << ans << "\n";
  }
}
