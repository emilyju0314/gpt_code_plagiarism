#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<vector<long long> > a;
vector<long long> g[100005];
map<long long, bool> mp[100005];
long long col[200005];
stack<long long> S;
long long dummy;
void dfs(long long s) {
  if (col[s] == 2) return;
  assert(col[s] == -1);
  col[s] = 1;
  for (auto i : g[s]) {
    if (col[i] == -1)
      dfs(i);
    else if (col[i] == 1) {
      cout << "-1\n";
      exit(0);
    } else if (col[i] == 2) {
      continue;
    }
  }
  col[s] = 2;
  S.push(s);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  dummy = m + 1;
  a.resize(n + 2);
  for (long long i = 0; i < a.size(); i++) a[i].resize(m + 2);
  for (long long i = 1; i <= n; i++) {
    vector<pair<long long, long long> > v;
    for (long long j = 1; j <= m; j++) {
      cin >> a[i][j];
      v.push_back(make_pair(a[i][j], j));
    }
    sort(v.begin(), v.end());
    for (long long j = 0; j < v.size(); j++) {
      long long k = j;
      if (v[j].first == -1) continue;
      while (k < v.size() && v[k].first == v[j].first) k++;
      for (long long x = j; x < k; x++) {
        g[dummy].push_back(v[x].second);
      }
      if (k == v.size()) {
        dummy++;
        break;
      }
      for (long long x = j; x < k; x++) {
        g[v[x].second].push_back(dummy + 1);
      }
      dummy++;
      j = k - 1;
    }
  }
  memset(col, -1, sizeof col);
  for (long long i = 1; i < dummy; i++) {
    if (col[i] == -1) dfs(i);
  }
  while (S.empty() == false) {
    if (S.top() <= m) cout << S.top() << " ";
    S.pop();
  }
  return 0;
}
