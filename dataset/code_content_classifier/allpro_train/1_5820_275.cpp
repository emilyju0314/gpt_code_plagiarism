#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const long long mod = 998244353;
int t, n, k, x;
int a[maxn];
map<int, int> mp;
bool v[maxn];
queue<int> q;
long long ans;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    ans = 1;
    memset(v, 0, sizeof v);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      mp[a[i]] = i;
    }
    v[0] = v[n + 1] = 1;
    for (int i = 0; i < k; ++i) {
      cin >> x;
      q.push(x);
      v[mp[x]] = 1;
    }
    while (!q.empty()) {
      x = mp[q.front()];
      q.pop();
      long long tmp = 2 - v[x - 1] - v[x + 1];
      v[x] = 0;
      ans = ans * tmp % mod;
    }
    cout << ans << endl;
  }
  return 0;
}
