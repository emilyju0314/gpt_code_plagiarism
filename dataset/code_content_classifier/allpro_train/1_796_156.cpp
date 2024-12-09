#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
using namespace std;
long long power(long long x, long long y) {
  x %= 1000000007;
  y %= 1000000007;
  long long var = x, ans = 1;
  while (y) {
    if (y & 1) ans = ((ans % 1000000007) * (var % 1000000007)) % 1000000007;
    var = ((var % 1000000007) * (var % 1000000007)) % 1000000007;
    y = y >> 1;
  }
  return ans;
}
void solve() {
  int n, k;
  cin >> n;
  vector<long long> v1(n);
  for (int i = 0; i < n; i++) cin >> v1[i];
  if (v1[n - 1] == 0) {
    for (int i = 0; i < n; i++) cout << 1 << " ";
    return;
  }
  v1.push_back(n + 5);
  set<int> s;
  for (int i = 0; i < n; i++) s.insert(v1[i]);
  int ans(n);
  for (int i = 0; i < 4 * n; i++) s.insert(i);
  for (int j = n - 1; j >= 0; j--) {
    if (!s.empty() && s.count(v1[j])) {
      s.erase(v1[j]);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << *s.begin() << " ";
    s.erase(s.begin());
    if (v1[i] < v1[i + 1]) {
      s.insert(v1[i]);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  while (t--) solve();
}
