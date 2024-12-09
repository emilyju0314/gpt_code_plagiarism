#include <bits/stdc++.h>
using namespace std;
vector<long long int> pri;
vector<pair<int, int> > ans;
int vis[1000001];
int main() {
  int n;
  memset(vis, 0, sizeof vis);
  scanf("%d", &n);
  int pr = 2;
  int flag = 0;
  while (1) {
    flag = 0;
    pri.push_back(pr);
    for (int i = 2 * pr; i <= n; i += pr) {
      vis[i] = 1;
    }
    for (int i = pr + 1; i <= n; i++) {
      if (!vis[i]) {
        pr = i;
        flag = 1;
        break;
      }
    }
    if (flag == 0) break;
  }
  memset(vis, 0, sizeof vis);
  for (int i = pri.size() - 1; i >= 0; i--) {
    int val = pri[i];
    flag = 0;
    for (long long int j = pri[i] * pri[i]; j <= n; j = j * pri[i]) {
      if (flag == 1) {
        val = j;
        flag = 0;
        continue;
      }
      ans.push_back(make_pair(val, j));
      vis[val] = vis[j] = 1;
      flag = 1;
    }
    for (int j = pri[i] * 3; j <= n; j += pri[i]) {
      if (!vis[j]) {
        if (flag == 1) {
          val = j;
          flag = 0;
          continue;
        }
        ans.push_back(make_pair(val, j));
        vis[val] = vis[j] = 1;
        flag = 1;
      }
    }
    if (!vis[pri[i] * 2] && pri[i] * 2 <= n)
      if (flag == 0) {
        ans.push_back(make_pair(val, pri[i] * 2));
        vis[val] = vis[pri[i] * 2] = 1;
      }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].first << " " << ans[i].second << endl;
}
