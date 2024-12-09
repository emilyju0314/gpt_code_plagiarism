#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int> m;
int main() {
  long long int n;
  cin >> n;
  vector<long long int> v;
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    v.emplace_back(x);
    m[x]++;
  }
  sort(v.begin(), v.end());
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    ans = max(ans, m[v[i]]);
  }
  cout << ans;
  return 0;
}
