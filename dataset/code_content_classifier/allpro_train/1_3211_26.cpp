#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long arr[n + 2];
  for (long long i = 1; i <= n; i++) cin >> arr[i];
  map<long long, long long> mp;
  long long ans = -1;
  for (long long i = 1; i <= n; i++) {
    mp[arr[i]]++;
    if (mp.size() == 1) {
      ans = max(ans, i);
    } else if (mp.size() == i) {
      ans = max(ans, i);
    } else {
      map<long long, long long> revmap;
      map<long long, long long>::reverse_iterator it, it1;
      long long stat = 0;
      for (auto it : mp) {
        revmap[it.second]++;
        if (revmap.size() > 2) {
          stat = 1;
          break;
        }
      }
      if (stat == 0) {
        if (revmap.size() == 2) {
          if (revmap[1] == 1) {
            ans = max(ans, i);
            continue;
          }
          it = revmap.rbegin();
          it1 = revmap.rbegin();
          it1++;
          if (it->second == 1) {
            if (it->first == (it1->first + 1)) ans = max(ans, i);
          } else if (it1->second == 1) {
            if (it1->first == (it->first + 1)) ans = max(ans, i);
          }
        }
      }
    }
  }
  cout << ans;
}
