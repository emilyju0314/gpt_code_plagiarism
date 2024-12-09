#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, s, f, i, x, l, r, t;
  string st;
  map<int, vector<int> > mp;
  cin >> n >> m >> s >> f;
  for (i = 1; i <= m; i++) {
    cin >> x >> l >> r;
    mp[x].push_back(l);
    mp[x].push_back(r);
  }
  int pos;
  if (s < f) {
    for (t = 1, pos = s; pos < f; t++) {
      if (mp.find(t) == mp.end()) {
        st += 'R';
        pos++;
      } else if ((pos < mp[t][0] || pos > mp[t][1]) &&
                 (pos + 1 < mp[t][0] || pos + 1 > mp[t][1])) {
        st += 'R';
        pos++;
      } else
        st += 'X';
    }
  } else {
    for (t = 1, pos = s; pos > f; t++) {
      if (mp.find(t) == mp.end()) {
        st += 'L';
        pos--;
      } else if ((pos < mp[t][0] || pos > mp[t][1]) &&
                 (pos - 1 < mp[t][0] || pos - 1 > mp[t][1])) {
        st += 'L';
        pos--;
      } else
        st += 'X';
    }
  }
  printf("%s\n", st.c_str());
  return 0;
}
