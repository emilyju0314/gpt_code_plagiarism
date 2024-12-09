#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long ans = 0;
  unordered_map<int, int> m;
  for (int r = 0, l = 0; r < n; r++) {
    m[v[r]]++;
    while (m[v[r]] >= k) {
      m[v[l++]]--;
    }
    ans += l;
  }
  cout << ans;
}
