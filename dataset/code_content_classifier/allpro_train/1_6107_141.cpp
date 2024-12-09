#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> adj[n];
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  vector<pair<int, int> > stk[n];
  int w;
  cin >> w;
  for (int i = 0; i < w; i++) {
    int c, k, p;
    cin >> c >> k >> p;
    stk[c - 1].push_back({k, p});
  }
  int q;
  cin >> q;
  while (q--) {
    int st;
    long long int rem, tot;
    cin >> st >> rem >> tot;
    queue<int> qu;
    qu.push(st - 1);
    int dep[n];
    memset(dep, -1, sizeof(dep));
    dep[st - 1] = 0;
    vector<int> vt[n];
    int mx = 0;
    while (!qu.empty()) {
      int &cr = qu.front();
      vt[dep[cr]].push_back(cr);
      for (int i = 0; i < adj[cr].size(); i++) {
        if (dep[adj[cr][i]] == -1)
          qu.push(adj[cr][i]), dep[adj[cr][i]] = dep[cr] + 1,
                               mx = max(mx, dep[cr] + 1);
      }
      qu.pop();
    }
    long long int ans = -1;
    int l = 0, h = mx, prev = -1;
    map<int, int> mp;
    while (l <= h) {
      int mid = (l + h) / 2;
      if (prev <= mid) {
        for (int i = prev + 1; i <= mid; i++) {
          for (auto it = vt[i].begin(); it != vt[i].end(); it++) {
            for (auto it2 = stk[*it].begin(); it2 != stk[*it].end(); it2++)
              mp[it2->second] += it2->first;
          }
        }
      } else {
        for (int i = prev; i > mid; i--) {
          for (auto it = vt[i].begin(); it != vt[i].end(); it++) {
            for (auto it2 = stk[*it].begin(); it2 != stk[*it].end(); it2++)
              mp[it2->second] -= it2->first;
          }
        }
      }
      prev = mid;
      long long int rm = rem, an = 0;
      for (auto it = mp.begin(); it != mp.end(); it++) {
        if (rm <= 0) break;
        an += min(rm, (long long int)it->second) * (long long int)it->first;
        rm -= it->second;
      }
      if (rm > 0 or an > tot)
        l = mid + 1;
      else
        ans = mid, h = mid - 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
