#include <bits/stdc++.h>
using namespace std;
int a[20005], b[20005];
vector<int> c[5005];
int lens[5005];
multiset<int> s;
int ans[5005];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];
    if (b[i] < a[i]) b[i] += n;
    c[a[i]].push_back(b[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (c[i].size() == 0)
      lens[i] = 0;
    else {
      sort(c[i].begin(), c[i].end());
      lens[i] = c[i][0] + (c[i].size() - 1) * n;
    }
    s.insert(lens[i]);
  }
  for (int i = 1; i <= n; i++) {
    ans[i] = *(--s.end()) - i;
    s.erase(s.find(lens[i]));
    s.insert(lens[i] + n);
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}
