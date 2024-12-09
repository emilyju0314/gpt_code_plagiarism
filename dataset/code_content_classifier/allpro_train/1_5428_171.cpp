#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, int> mp;
  long long int n, k;
  cin >> n >> k;
  while (n--) {
    long long int a;
    cin >> a;
    mp[a]++;
  }
  if (k == 0) {
    map<int, int>::iterator p;
    p = mp.begin();
    long long int no = p->first;
    if (no - 1 >= 1 && no - 1 <= 1e9)
      cout << no - 1;
    else
      cout << "-1";
  } else {
    int flag = 1, ans = -1;
    for (auto x : mp) {
      ans = x.first;
      k -= x.second;
      if (k < 0) {
        flag = 0;
        break;
      }
      if (k == 0) {
        break;
      }
    }
    if (flag)
      if (ans >= 1 && ans <= 1e9)
        cout << ans;
      else
        cout << "-1";
    else
      cout << "-1";
  }
}
