#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, i, val = 1;
  cin >> t;
  vector<long long int> v;
  for (i = 0; i < 30; i++) {
    if (i == 0)
      v.push_back(val);
    else {
      val = val * 2;
      v.push_back(2 * v.back() + val * val);
    }
  }
  for (i = 0; i < v.size() - 1; i++) v[i + 1] += v[i];
  for (int y = 0; y < t; y++) {
    long long int n;
    int ans;
    cin >> n;
    ans = lower_bound(v.begin(), v.end(), n) - v.begin() + 1;
    if (*lower_bound(v.begin(), v.end(), n) != n) ans--;
    cout << ans << "\n";
  }
  return 0;
}
