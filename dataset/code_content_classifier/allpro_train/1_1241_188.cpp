#include <bits/stdc++.h>
using namespace std;
long long int power(long long int num, long long int base) {
  if (base == 0) return 1;
  if (base % 2)
    return (num * power(num, base - 1));
  else {
    long long int x = power(num, base / 2);
    x = x * x;
    return x;
  }
}
vector<long long int> getFactors(long long int n) {
  vector<long long int> v;
  if (n % 2 == 0) v.push_back(2);
  while (n > 0 && n % 2 == 0) {
    n = n / 2;
  }
  for (long long int i = 3; i <= sqrt(n) && n > 0; i = i + 2) {
    if (n % i == 0) v.push_back(i);
    while (n > 0 && n % i == 0) n = n / i;
  }
  if (n > 2) v.push_back(n);
  return v;
}
bool check(vector<long long int> v, long long int x, long long int k,
           bool odd) {
  long long int i, j = 0;
  for (i = 0; i < v.size(); i++) {
    if ((j % 2 == !odd) || (j % 2 == odd && v[i] <= x)) j++;
  }
  return j >= k;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int testcases = 1;
  cin >> testcases;
  while (testcases--) {
    long long int n, i;
    cin >> n;
    vector<long long int> v(n), next(n);
    map<long long int, long long int> prev, first;
    for (auto& x : v) cin >> x;
    for (auto& x : next) x = n;
    for (i = 0; i < n; i++) {
      if (prev[v[i]]) next[prev[v[i]] - 1] = i;
      prev[v[i]] = i + 1;
    }
    map<long long int, long long int> maxi;
    for (i = n - 1; i >= 0; i--) {
      maxi[v[i]] = max(maxi[v[i]], next[i] - i);
    }
    for (i = 0; i < n; i++) {
      if (first[v[i]]) continue;
      maxi[v[i]] = max(maxi[v[i]], i + 1);
      first[v[i]] = i + 1;
    }
    long long int mi = n + 1, k;
    sort(v.begin(), v.end());
    vector<long long int> ans(n + 1);
    for (i = 1; i <= n; i++) {
      ans[i] = -1;
    }
    for (i = 0; i < n; i++) {
      if (i > 0 && v[i - 1] == v[i]) continue;
      for (k = maxi[v[i]]; k < mi; k++) ans[k] = v[i];
      mi = min(mi, maxi[v[i]]);
    }
    for (i = 1; i <= n; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
}
