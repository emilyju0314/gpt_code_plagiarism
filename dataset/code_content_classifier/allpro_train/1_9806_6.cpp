#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, cnt[N];
map<int, int> mp;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    cnt[a]++;
    if (mp.find(a) == mp.end()) {
      mp[a] = 1;
    } else {
      mp[a]++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n;) {
    if (cnt[i] != 0) {
      ans++;
      i += 3;
    } else {
      i++;
    }
  }
  set<int> res;
  for (auto x : mp) {
    if (x.second == 1) {
      int g = 1;
      if (!res.count(x.first - 1)) {
        res.insert(x.first - 1);
        g--;
      }
      if (g > 0 && !res.count(x.first)) {
        res.insert(x.first);
        g--;
      }
      if (g > 0 && !res.count(x.first + 1)) {
        res.insert(x.first + 1);
        g--;
      }
    } else {
      int g = x.second;
      int j = x.first - 1;
      if (g > 0 && !res.count(j)) {
        res.insert(j);
        g--;
      }
      if (g > 0 && !res.count(x.first)) {
        res.insert(x.first);
        g--;
      }
      if (g > 0 && !res.count(x.first + 1)) {
        res.insert(x.first + 1);
        g--;
      }
    }
  }
  cout << ans << " " << res.size() << '\n';
  return 0;
}
