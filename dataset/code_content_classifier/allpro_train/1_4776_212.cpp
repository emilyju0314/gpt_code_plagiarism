#include <bits/stdc++.h>
using namespace std;
vector<long long> rasl(long long n) {
  vector<long long> v;
  if (n == 1) {
    return v;
  }
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      v = rasl(n / i);
      v.push_back(i);
      return v;
    }
  }
  v.push_back(n);
  return v;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> v = rasl(n);
  set<long long> a;
  for (long long i = 0; i < v.size(); ++i) {
    a.insert(v[i]);
  }
  if (v.size() == 1) {
    cout << n;
    return 0;
  }
  if (a.size() == 1) {
    cout << v[0];
    return 0;
  }
  cout << 1;
  return 0;
}
