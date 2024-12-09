#include <bits/stdc++.h>
using namespace std;
long long n;
pair<long long, long long> p[500007];
set<pair<long long, long> > s;
vector<long long> a[500007];
int used[500007], o;
void dfs(int v) {
  if (used[v]) return;
  o++;
  used[v] = 1;
  for (auto to : a[v]) dfs(to);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> p[i].first >> p[i].second;
  sort(p + 1, p + 1 + n);
  long long curr = 0;
  for (int i = 1; i <= n; ++i) {
    auto it = s.lower_bound({p[i].first, 0});
    while (it != s.end()) {
      if (it->first > p[i].second) break;
      curr++;
      a[i].push_back(it->second);
      a[it->second].push_back(i);
      it++;
      if (it->first > p[i].second) break;
    }
    if (curr >= n) break;
    s.insert({p[i].second, i});
  }
  if (curr != n - 1) return cout << "NO" << endl, 0;
  dfs(1);
  if (o == n)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
