#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    map<double, long long> mp;
    long long n;
    cin >> n;
    vector<int> a(n);
    long long ans = 0;
    double sum = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (long long i = 0; i < n; i++) {
      sum = sum + a[i];
    }
    double p = sum / (1.0 * n);
    double di = p * 2;
    for (int i = 0; i < n; i++) {
      if (mp.find(di - a[i]) != mp.end()) ans += mp[di - a[i]];
      mp[a[i]]++;
    }
    cout << ans << endl;
  }
  return 0;
}
