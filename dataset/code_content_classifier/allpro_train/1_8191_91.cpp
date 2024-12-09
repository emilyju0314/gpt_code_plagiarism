#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  long long n;
  cin >> n;
  vector<long long> a;
  for (long long i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  long long c = 0;
  for (long long i = 0; i < a.size() - 1; ++i) {
    c += a[a.size() - 1] - a[i];
  }
  cout << c << endl;
  return 0;
}
