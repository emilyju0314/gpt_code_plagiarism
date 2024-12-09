#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long INF = mod * mod;
const long double eps = 1e-8;
int n;
vector<long long> c;
vector<int> G[1 << 18];
vector<int> par[1 << 18][2];
pair<long long, long long> dfs(int id, int fr) {
  if (fr >= 0 && G[id].size() == 1) {
    return {c[id], 0};
  }
  vector<pair<long long, long long> > v;
  vector<int> ids;
  for (int j = 0; j < G[id].size(); j++) {
    int to = G[id][j];
    if (to == fr) continue;
    ids.push_back(to);
    v.push_back(dfs(to, id));
  }
  pair<long long, long long> ret = {INF, INF};
  long long sum = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += v[i].first;
  }
  long long mi = sum;
  long long mi2 = INF;
  for (int i = 0; i < v.size(); i++) {
    long long s = sum - v[i].first + v[i].second;
    mi2 = min(mi2, s);
    mi = min(mi, s + c[id]);
  }
  if (sum == mi) {
    par[id][0].push_back(-1);
  }
  for (int i = 0; i < v.size(); i++) {
    long long s = sum - v[i].first + v[i].second;
    if (mi == s + c[id]) {
      par[id][0].push_back(i);
    }
    if (mi2 == s) {
      par[id][1].push_back(i);
    }
  }
  return {mi, mi2};
}
bool used[1 << 18][2];
vector<int> ansids;
void strans(int id, int id2, int fr) {
  if (used[id][id2]) return;
  used[id][id2] = true;
  if (fr >= 0 && G[id].size() == 1 && id2 == 0) {
    ansids.push_back(id);
    return;
  }
  vector<int> v;
  for (int j = 0; j < G[id].size(); j++) {
    int to = G[id][j];
    if (to == fr) continue;
    v.push_back(to);
  }
  bool f = false;
  if (par[id][id2].size() >= 2) {
    for (int j = 0; j < v.size(); j++) {
      strans(v[j], 0, id);
    }
    for (int j = 0; j < par[id][id2].size(); j++) {
      int t = par[id][id2][j];
      if (t < 0) continue;
      if (id2 == 0) f = true;
      strans(v[t], 1, id);
    }
  } else {
    for (int j = 0; j < v.size(); j++) {
      if (par[id][id2][0] == j) {
        if (id2 == 0) f = true;
        strans(v[j], 1, id);
      } else {
        strans(v[j], 0, id);
      }
    }
  }
  if (f) {
    ansids.push_back(id);
  }
}
void solve() {
  cin >> n;
  c.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  pair<long long, long long> ans = dfs(0, -1);
  int root = 0;
  int root2 = 0;
  strans(root, root2, -1);
  sort(ansids.begin(), ansids.end());
  ansids.erase(unique(ansids.begin(), ansids.end()), ansids.end());
  cout << ans.first << " " << ansids.size() << endl;
  for (int i = 0; i < ansids.size(); i++) {
    if (i > 0) cout << " ";
    cout << ansids[i] + 1;
  }
  cout << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
