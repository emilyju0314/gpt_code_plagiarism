#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
const long long MOD = 998244353;
long long arr[1001][1001];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  std::vector<std::vector<long long>> vr, vc;
  for (long long i = 0; i < n; ++i) {
    set<long long> t;
    std::vector<long long> temp;
    for (long long j = 0; j < m; ++j) {
      long long x;
      cin >> x;
      arr[i][j] = x;
      if (t.count(x) == 0) {
        t.insert(x);
        temp.push_back(x);
      }
    }
    vr.push_back(temp);
  }
  for (long long i = 0; i < m; ++i) {
    set<long long> t;
    std::vector<long long> temp;
    for (long long j = 0; j < n; ++j) {
      long long x = arr[j][i];
      if (t.count(x) == 0) {
        t.insert(x);
        temp.push_back(x);
      }
    }
    vc.push_back(temp);
  }
  for (long long i = 0; i < n; ++i) {
    sort(vr[i].begin(), vr[i].end());
  }
  for (long long i = 0; i < m; ++i) {
    sort(vc[i].begin(), vc[i].end());
  }
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < m; ++j) {
      long long a = distance(
          vr[i].begin(), lower_bound(vr[i].begin(), vr[i].end(), arr[i][j]));
      long long b = vr[i].size() - a - 1;
      long long c = distance(
          vc[j].begin(), lower_bound(vc[j].begin(), vc[j].end(), arr[i][j]));
      long long d = vc[j].size() - c - 1;
      arr[i][j] = max(a, c) + 1 + max(b, d);
    }
  }
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < m; ++j) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
}
