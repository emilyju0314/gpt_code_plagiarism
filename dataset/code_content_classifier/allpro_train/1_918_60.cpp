#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;
const int MOD = 1000000007;
vector<vector<int> > v;
vector<set<int> > lens;
vector<int> deg, used;
int n;
int solve() {
  int res = -1;
  queue<int> q;
  lens.resize(n);
  deg.resize(n);
  used.resize(n);
  for (int i = 0; i < n; i++) deg[i] = v[i].size();
  for (int i = 0; i < n; i++)
    if (deg[i] == 1) {
      lens[i].insert(0);
      q.push(i);
    }
  int cnt = 0;
  int cur;
  while (!q.empty()) {
    cur = q.front();
    q.pop();
    used[cur] = true;
    cnt++;
    if (deg[cur] != 1) continue;
    if (lens[cur].size() != 1) break;
    int value = *lens[cur].begin();
    for (int i = 0; i < v[cur].size(); i++) {
      int to = v[cur][i];
      if (used[to]) continue;
      deg[to]--;
      lens[to].insert(value + 1);
      if (deg[to] == 1) q.push(to);
    }
  }
  if (cnt != n) return -1;
  if (lens[cur].size() > 2) return -1;
  res = accumulate(lens[cur].begin(), lens[cur].end(), 0);
  while (res % 2 == 0) res /= 2;
  return res;
}
int main() {
  scanf("%d", &n);
  v.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  printf("%d\n", solve());
}
