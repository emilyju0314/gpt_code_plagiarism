#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
long long mod = 1000000007LL;
long long mod2 = 998244353LL;
int n;
int a[100005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  int cr = n + 1;
  vector<pair<int, int>> ans;
  ans.clear();
  vector<int> cs[4];
  for (int i = 0; i <= 3; ++i) {
    cs[i].clear();
  }
  bool ok = true;
  for (int i = n; i >= 1; --i) {
    if (a[i] == 1) {
      cs[1].push_back(i);
    } else if (a[i] == 2) {
      if (cs[1].empty()) {
        ok = false;
        break;
      }
      int cc = cs[1].back();
      cs[1].pop_back();
      cr--;
      ans.push_back(make_pair(cr, i));
      ans.push_back(make_pair(cr, cc));
      cs[2].push_back(i);
    } else if (a[i] == 3) {
      if (!cs[2].empty()) {
        int cc = cs[2].back();
        cs[2].pop_back();
        cr--;
        ans.push_back(make_pair(cr, i));
        ans.push_back(make_pair(cr, cc));
        cs[3].push_back(i);
      } else if (!cs[3].empty()) {
        int cc = cs[3].back();
        cs[3].pop_back();
        cr--;
        ans.push_back(make_pair(cr, i));
        ans.push_back(make_pair(cr, cc));
        cs[3].push_back(i);
      } else if (!cs[1].empty()) {
        int cc = cs[1].back();
        cs[1].pop_back();
        cr--;
        ans.push_back(make_pair(cr, cc));
        cr--;
        ans.push_back(make_pair(cr, i));
        ans.push_back(make_pair(cr, cc));
        cs[3].push_back(i);
      } else {
        ok = false;
        break;
      }
    }
  }
  if (!ok) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < cs[1].size(); ++i) {
      cr--;
      ans.push_back(make_pair(cr, cs[1][i]));
    }
    int sz = (int)ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d %d\n", ans[i].first, ans[i].second);
    }
  }
  return 0;
}
