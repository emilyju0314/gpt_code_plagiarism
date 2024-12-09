#include <bits/stdc++.h>
using namespace std;
vector<int> gr[50];
int cl[66], col = 1;
map<int, vector<int> > mp;
void f(int v) {
  cl[v] = col;
  for (int i = 0; i < gr[v].size(); i++) {
    if (cl[gr[v][i]] == -1) {
      f(gr[v][i]);
    }
  }
}
int main() {
  memset(cl, -1, sizeof(cl));
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (cl[i] == -1) {
      f(i);
      col++;
    }
  }
  vector<int> ch1;
  vector<pair<int, int> > ch2;
  vector<pair<int, pair<int, int> > > ch3;
  for (int i = 1; i <= n; i++) {
    mp[cl[i]].push_back(i);
    if (mp[cl[i]].size() > 3) {
      cout << -1;
      return 0;
    }
  }
  for (map<int, vector<int> >::iterator it = mp.begin(); it != mp.end(); ++it) {
    if ((*it).second.size() == 1) {
      ch1.push_back((*it).second[0]);
    }
    if ((*it).second.size() == 2) {
      ch2.push_back(make_pair((*it).second[0], (*it).second[1]));
    }
    if ((*it).second.size() == 3) {
      ch3.push_back(make_pair((*it).second[0],
                              make_pair((*it).second[1], (*it).second[2])));
    }
  }
  if (ch2.size() > ch1.size()) {
    cout << -1;
    return 0;
  }
  int uk = 0;
  for (; uk < ch2.size(); uk++) {
    cout << ch1[uk] << " " << ch2[uk].first << " " << ch2[uk].second << endl;
  }
  for (; uk + 2 < ch1.size(); uk += 3) {
    cout << ch1[uk] << " " << ch1[uk + 1] << " " << ch1[uk + 2] << endl;
  }
  for (int i = 0; i < ch3.size(); i++) {
    cout << ch3[i].first << " " << ch3[i].second.first << " "
         << ch3[i].second.second << endl;
  }
  return 0;
}
