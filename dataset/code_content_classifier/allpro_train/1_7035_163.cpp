#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  getchar();
  string s;
  vector<string> graph;
  int mindex = INT_MAX, maxdex = INT_MIN;
  int sp = -1;
  int point1, point2, j = 0;
  while (getline(cin, s) && s.size() > 0) {
    int sz = s.size();
    bool start = false;
    int locs = INT_MAX, loce = INT_MIN;
    for (int i = 0; i < sz; i++) {
      if (!start && s[i] == '*') {
        locs = i;
        start = true;
        if (sp == -1) sp = 1;
      }
      if (s[i] == '*') loce = i;
    }
    graph.push_back(s);
    maxdex = max(maxdex, loce);
    mindex = min(mindex, locs);
    if (sp == 1) {
      point1 = j;
      sp = 0;
    }
    if (start) point2 = j;
    j++;
  }
  for (int i = point1; i <= point2; i++) {
    string t = graph[i];
    for (int j = mindex; j <= maxdex; j++) {
      cout << graph[i][j];
    }
    cout << endl;
  }
  return 0;
}
