#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long TESTS = 1;
  while (TESTS--) {
    long long n;
    cin >> n;
    vector<float> v(n);
    for (long long i = 0; i < n; i++) cin >> v[i];
    vector<pair<long long, long long> > base(n);
    for (long long i = 0; i < n; i++) {
      float x = v[i];
      base[i].first = (long long)x;
      if (x - (float)base[i].first == 0)
        base[i].second = 0;
      else if (x - (float)base[i].first > 0)
        base[i].second = 1;
      else
        base[i].second = -1;
    }
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      sum += base[i].first;
    }
    if (sum == 0) {
      for (long long i = 0; i < n; i++) {
        cout << base[i].first << '\n';
      }
    } else if (sum > 0) {
      for (long long i = 0; i < n; i++) {
        if (base[i].second < 0) base[i].first--, sum--;
        if (sum == 0) break;
      }
      for (long long i = 0; i < n; i++) {
        cout << base[i].first << '\n';
      }
    } else {
      for (long long i = 0; i < n; i++) {
        if (base[i].second > 0) base[i].first++, sum++;
        if (sum == 0) break;
      }
      for (long long i = 0; i < n; i++) {
        cout << base[i].first << '\n';
      }
    }
  }
  return 0;
}
