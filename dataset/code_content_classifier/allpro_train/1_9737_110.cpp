#include <bits/stdc++.h>
using namespace std;
const long long INF = 922337203685477110;
const long long N = 1000005;
const long long mod = 1e9 + 7;
const long long M = 22;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long a[n + 3];
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    long long in = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    if (in >= v.size())
      v.push_back(a[i]);
    else
      v[in] = a[i];
  }
  cout << v.size() << "\n";
}
