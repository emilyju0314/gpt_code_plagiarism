#include <bits/stdc++.h>
using namespace std;
string a[23] = {"142536", "154326", "135246", "214365", "231645", "263415",
                "246135", "365214", "326154", "312564", "351624", "462513",
                "456123", "415263", "421653", "541632", "513462", "536142",
                "564312", "645231", "624351", "632541", "653421"};
int main() {
  vector<int> d;
  for (int i(0); i <= (6 - 1); i++) d.push_back(i);
  set<string> st;
  string s;
  getline(cin, s);
  do {
    string u;
    for (int i(0); i <= (6 - 1); i++) u += s[d[i]];
    string nw;
    for (int i(0); i <= (6 - 1); i++) nw += u[i];
    bool q = true;
    if (st.count(u) != 0) q = false;
    for (int i(0); i <= (23 - 1); i++) {
      for (int j(0); j <= (6 - 1); j++) nw[j] = u[a[i][j] - '1'];
      if (st.count(nw) != 0) q = false;
    }
    if (q) st.insert(u);
  } while (next_permutation((d).begin(), (d).end()));
  printf("%d\n", st.size());
  return 0;
}
