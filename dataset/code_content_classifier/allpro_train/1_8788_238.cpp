#include <bits/stdc++.h>
using namespace std;
template <typename T>
long long max(long long x, long long y) {
  return x > y ? x : y;
}
template <typename T>
long long min(long long x, long long y) {
  return x < y ? x : y;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  long long m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    long long l, r, k;
    cin >> l >> r >> k;
    l--;
    r--;
    string d = s.substr(l, r - l + 1);
    long long sz = r - l + 1;
    for (int i = 0; i < d.size(); ++i) {
      s[l + ((i + k) % sz)] = d[i];
    }
  }
  cout << s << "\n";
}
