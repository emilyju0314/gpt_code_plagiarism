#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9;
vector<int> v[2];
int bit(int mask, int b) { return (mask >> b) & 1; }
long long fun(vector<int> &a, int k) {
  long long ans = 0;
  int l = 0, r = ((int)a.size()) - 1;
  while (l < r) {
    while (l < r && a[r] + a[l] < k) l++;
    ans += (r - l);
    r--;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 0;
  for (int b = 0; b < 26; b++) {
    v[0].clear();
    v[1].clear();
    for (int i = 0; i < n; i++)
      v[bit(a[i], b)].push_back(a[i] & ((1 << b) - 1));
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    long long cnt = fun(v[0], 1 << b) + fun(v[1], 1 << b);
    for (int x : v[1])
      cnt += lower_bound(v[0].begin(), v[0].end(), (1 << b) - x) - v[0].begin();
    if (cnt % 2) ans |= 1 << b;
  }
  cout << ans << '\n';
  return 0;
}
