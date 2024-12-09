#include <bits/stdc++.h>
using namespace std;
int gp[500010];
pair<int, int> pt[250010];
bool open[500010];
int main() {
  stack<int> arr;
  set<int> valid;
  string str;
  int n, m, pos;
  cin >> n >> m >> pos >> str;
  --pos;
  for (int i = 0, j = 0; i < n; i++) {
    open[i] = (str[i] == '(');
    if (open[i]) {
      arr.push(i);
      gp[i] = ++j;
      pt[gp[i]].first = i;
    } else {
      gp[i] = gp[arr.top()];
      arr.pop();
      pt[gp[i]].second = i;
    }
    valid.insert(i);
  }
  cin >> str;
  for (int i = 0; i < m; i++) {
    if (str[i] == 'R')
      pos = *(valid.upper_bound(pos));
    else if (str[i] == 'L')
      pos = *(--valid.lower_bound(pos));
    else if (str[i] == 'D') {
      int u = pt[gp[pos]].first, v = pt[gp[pos]].second;
      valid.erase(valid.lower_bound(u), valid.upper_bound(v));
      if (valid.upper_bound(pos) == valid.end())
        pos = *(valid.rbegin());
      else
        pos = *(valid.upper_bound(pos));
    }
  }
  for (set<int>::iterator it = valid.begin(); it != valid.end(); it++) {
    if (open[*it])
      printf("(");
    else
      printf(")");
  }
  printf("\n");
  return 0;
}
