#include <bits/stdc++.h>
using namespace std;
vector<set<int> > newadj(212345);
int visit[212345];
vector<vector<int> > adj(212345);
vector<int> vec, vecans;
set<int> seti;
int cnt = 0;
int pos[212345];
int dfs(int cur) {
  cnt++;
  visit[cur] = 1;
  set<int>::iterator it;
  for (it = newadj[cur].begin(); it != newadj[cur].end(); it++) {
    if (!visit[*it]) {
      dfs(*it);
    }
  }
  return 0;
}
int main() {
  std::ios::sync_with_stdio(false);
  int n, m;
  int i, j, u, v;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int mini = (1000 * 1000 * 1000 + 5), vert;
  for (i = 0; i < n; i++) {
    if (mini > adj[i].size()) {
      mini = adj[i].size();
      vert = i;
    }
  }
  int sumi = 0;
  for (i = 0; i < n; i++) {
    sumi++;
    pos[i] = vert;
  }
  vec.push_back(vert);
  for (i = 0; i < adj[vert].size(); i++) {
    sumi--;
    pos[adj[vert][i]] = adj[vert][i];
    vec.push_back(adj[vert][i]);
    seti.insert(adj[vert][i]);
  }
  seti.insert(vert);
  set<int>::iterator it;
  for (i = 1; i < vec.size(); i++) {
    for (it = seti.begin(); it != seti.end(); it++) {
      newadj[vec[i]].insert(*it);
    }
    cnt = 0;
    for (j = 0; j < adj[vec[i]].size(); j++) {
      if (pos[adj[vec[i]][j]] == vert) {
        cnt++;
        continue;
      }
      newadj[vec[i]].erase(pos[adj[vec[i]][j]]);
    }
    if (cnt == sumi) {
      newadj[vec[i]].erase(vert);
    } else {
      newadj[vert].insert(vec[i]);
    }
  }
  for (i = 0; i < vec.size(); i++) {
    if (!visit[vec[i]]) {
      cnt = 0;
      dfs(vec[i]);
      if (i == 0) {
        cnt += sumi - 1;
      }
      vecans.push_back(cnt);
    }
  }
  sort(vecans.begin(), vecans.end());
  cout << vecans.size() << endl;
  for (i = 0; i < vecans.size(); i++) {
    cout << vecans[i] << " ";
  }
  return 0;
  return 0;
}
