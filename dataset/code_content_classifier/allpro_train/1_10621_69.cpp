#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 100 * 1000 + 20;
int n, a[N], p[N];
bool vis[N];
vector<int> ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i], p[i] = a[i];
  sort(p, p + n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (!vis[j] && p[j] == a[i]) vis[j] = true, ans.push_back(p[(j + 1) % n]);
  for (auto x : ans) cout << x << " ";
  cout << endl;
  return 0;
}
