#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a, b;
  map<int, vector<int> > m;
  map<int, int> m2;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    m[a].push_back(b);
    m[b].push_back(a);
    m2[a] = 0;
    m2[b] = 0;
  }
  vector<int> l;
  map<int, vector<int> >::iterator it = m.begin();
  map<int, int>::iterator it2 = m2.begin();
  int ind = 0;
  int indx = it->first;
  for (it = m.begin(); it != m.end(); ++it) {
    if (it->second.size() == 1) {
      l.push_back(it->first);
      m2[it->first] = 1;
      ind = 0;
      indx = it->first;
      break;
    }
  }
  while (1) {
    if (ind >= m[indx].size()) break;
    if (m2[m[indx][ind]] == 0) {
      m2[m[indx][ind]] = 1;
      l.push_back(m[indx][ind]);
      indx = m[indx][ind];
      ind = 0;
    } else {
      ind++;
    }
  }
  if (l.size() == m.size()) {
    for (int i = 0; i < l.size(); i++) {
      if (i != 0) printf(" ");
      printf("%d", l[i]);
    }
  }
}
