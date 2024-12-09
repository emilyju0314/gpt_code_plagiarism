#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1, i, j;
  while (t--) {
    long long n, x, y;
    cin >> n;
    long long a[n + 1];
    for (long long i = 0; i < n + 1; i++) a[i] = 0;
    vector<long long> ans;
    long long num = (((n * (n - 1))) / 2) - 1;
    unordered_map<long long, long long> mp;
    for (i = 0; i < num; i++) {
      cin >> x >> y;
      mp[x]++;
      mp[y]++;
      a[x]++;
      a[y]--;
    }
    for (auto i : mp) {
      if (i.second != (n - 1)) {
        ans.push_back(i.first);
      }
    }
    if (a[ans[0]] > a[ans[1]])
      cout << ans[0] << " " << ans[1];
    else {
      cout << ans[1] << " " << ans[0];
    }
  }
}
