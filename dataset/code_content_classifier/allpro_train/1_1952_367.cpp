#include <bits/stdc++.h>
using namespace std;
vector<int> sc[300010];
vector<string> team[300010];
int main() {
  int n, m;
  cin >> n >> m;
  string s;
  int u, v;
  for (int i = 1; i <= n; i++) {
    cin >> s >> u >> v;
    sc[u].push_back(v);
    team[u].push_back(s);
  }
  for (int i = 1; i <= m; i++) {
    int b1 = 0, b2, b3, cur = 0;
    for (int j = 0; j < sc[i].size(); j++) {
      if (sc[i][j] > sc[i][b1]) b1 = j;
    }
    for (int j = 0; j < sc[i].size(); j++) {
      if (j == b1) continue;
      if (sc[i][j] >= cur) {
        cur = sc[i][j];
        b2 = j;
      }
    }
    cur = -1;
    b3 = -1;
    for (int j = 0; j < sc[i].size(); j++) {
      if (j == b2 or j == b1) continue;
      if (sc[i][j] > cur) {
        cur = sc[i][j];
        b3 = j;
      }
    }
    if (b3 != -1 and sc[i][b3] == sc[i][b2])
      cout << "?" << endl;
    else
      cout << team[i][b1] << " " << team[i][b2] << endl;
  }
  return 0;
}
