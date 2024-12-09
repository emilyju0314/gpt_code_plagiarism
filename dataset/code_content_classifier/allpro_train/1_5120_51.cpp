#include <bits/stdc++.h>
using namespace std;
const int maxn = 16;
const long long inf = 1e18;
const pair<long long, long long> INF = {inf, inf};
pair<long long, long long> res[maxn];
map<long long, int> id;
vector<pair<long long, long long>> vt1;
vector<int> vt[maxn];
long long t;
int cnt[maxn];
long long sum[maxn];
bool mark[maxn];
bool dfs(int u, long long val, long long has) {
  mark[u] = true;
  if (val == has) {
    return true;
  }
  if (!id.count(val)) {
    return false;
  } else {
    int v = id[val];
    if (!mark[v]) {
      vt1.push_back({v, val});
      return dfs(v, t - (sum[v] - val), has);
    } else
      return false;
  }
}
int f[1 << 16];
void solve(int k, long long total) {
  t = total / k;
  for (int i = 0; i < k; i++) res[i] = INF;
  for (int i = 0; i < k; i++) {
    if (sum[i] == t) {
      res[i] = {vt[i][0], i};
    }
  }
  vector<vector<pair<long long, long long>>> cds;
  for (int i = 0; i < k; i++) {
    if (res[i] == INF) {
      for (int j = 0; j < vt[i].size(); j++) {
        vt1.clear();
        vt1.push_back({i, vt[i][j]});
        memset(mark, false, sizeof(mark));
        bool found = dfs(i, t - (sum[i] - vt[i][j]), vt[i][j]);
        if (found) {
          cds.push_back(vt1);
        }
      }
    } else {
      vt1.clear();
      vt1.push_back({i, vt[i][0]});
      cds.push_back(vt1);
    }
  }
  vector<int> cds1;
  for (int i = 0; i < cds.size(); i++) {
    vector<pair<long long, long long>> p = cds[i];
    int tt = 0;
    for (int j = 0; j < p.size(); j++) {
      tt |= (1 << p[j].first);
    }
    cds1.push_back(tt);
  }
  f[0] = 1;
  for (int i = 0; i < (1 << k); i++) {
    if (f[i]) {
      for (int j = 0; j < cds1.size(); j++) {
        if ((i ^ cds1[j]) == (i | cds1[j])) {
          f[i ^ cds1[j]] = j + 2;
        }
      }
    }
  }
  if (!f[(1 << k) - 1]) {
    return;
  } else {
    int u = (1 << k) - 1;
    while (u) {
      int tt = f[u] - 2;
      if (cds[tt].size() == 1) {
        res[cds[tt][0].first] = {cds[tt][0].second, cds[tt][0].first};
      } else {
        for (int i = 1; i < cds[tt].size(); i++) {
          res[cds[tt][i].first] = {cds[tt][i].second, cds[tt][i - 1].first};
        }
        res[cds[tt][0].first] = {cds[tt][0].second, cds[tt].back().first};
      }
      u ^= cds1[tt];
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k = 0;
  cin >> k;
  long long total = 0;
  for (int i = 0; i < k; i++) {
    cin >> cnt[i];
    for (int j = 0; j < cnt[i]; j++) {
      int x;
      cin >> x;
      vt[i].push_back(x);
      id[x] = i;
      total += x;
      sum[i] += x;
    }
  }
  if (total % k != 0) {
    cout << "No";
    return 0;
  } else {
    solve(k, total);
  }
  for (int i = 0; i < k; i++) {
    if (res[i] == INF) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes" << endl;
  for (int i = 0; i < k; i++)
    cout << res[i].first << " " << res[i].second + 1 << endl;
  return 0;
}
