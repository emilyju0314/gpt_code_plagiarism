#include <bits/stdc++.h>
using namespace std;
void Emsawy() {}
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};
long long suf(long long x) { return max(0LL, (x * (x + 1)) / 2); }
vector<vector<pair<int, int> > > adj;
const long long mod = (long long)1e9 + 7, oo = (long long)1e9;
int n, m;
int main() {
  Emsawy();
  while (cin >> n) {
    vector<int> v(n + 1);
    map<int, int> mp, g;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      cin >> v[i];
      if (g[v[i]] > 0) continue;
      g[v[i]] = ++mx;
    }
    for (int i = 1; i <= n; i++) {
      if (mp.find(v[i]) != mp.end()) continue;
      if (v[i] == i) mp[v[i]] = i;
    }
    if (mp.size() != g.size()) {
      cout << "-1" << endl;
      continue;
    }
    vector<int> H(mx + 1), G;
    for (int i = 0; i < n; i++) {
      G.push_back(g[v[i + 1]]);
      H[G[i]] = v[i + 1];
    }
    cout << mx << endl;
    for (int i = 0; i < n; i++) {
      cout << G[i] << " \n"[i == n - 1];
    }
    for (int i = 1; i < H.size(); i++) {
      cout << H[i] << " \n"[i == int(H.size() - 1)];
    }
    puts("");
  }
  return 0;
}
