#include <bits/stdc++.h>
using namespace std;
int a[2000001], b[2000001];
vector<int> ans;
int main() {
  int n, m, p;
  cin >> n >> m >> p;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  for (int i = 0; i < p && (long long)i + (long long)(m - 1) * p < n; i++) {
    map<int, int> mp;
    for (int j = 0; j < m; j++) mp[b[j]]++;
    for (int j = 0; j < m; j++)
      if (--mp[a[i + j * p]] == 0) mp.erase(a[i + j * p]);
    for (int j = i, k = i + m * p;; j += p, k += p) {
      if (mp.empty()) ans.push_back(j + 1);
      if (k >= n) break;
      if (++mp[a[j]] == 0) mp.erase(a[j]);
      if (--mp[a[k]] == 0) mp.erase(a[k]);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
