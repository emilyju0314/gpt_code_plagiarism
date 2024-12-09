#include <bits/stdc++.h>
using namespace std;
namespace Work {
vector<int> r[128];
vector<int>::iterator it1, it2, it3;
int n, m;
void Work() {
  cin >> n >> m;
  char ch;
  char st[131072];
  register int i, j;
  for (i = 0; i < n; ++i) {
    r[i].push_back(-999999);
    r[i].push_back(999999);
    for (j = 0; j < m; ++j) {
      cin >> ch;
      if (ch - '0') {
        r[i].push_back(j);
        r[i].push_back(j - m);
        r[i].push_back(j + m);
      }
    }
    if (r[i].size() < 3) {
      cout << "-1" << endl;
      return;
    }
    sort(r[i].begin(), r[i].end());
    gets(st);
  }
  int ans;
  int mans = 999999999;
  for (i = 0; i < m; ++i) {
    ans = 0;
    for (j = 0; j < n; ++j) {
      it1 = lower_bound(r[j].begin(), r[j].end(), i);
      it2 = it1++;
      it3 = it2--;
      int t1 = (*it1 - i > 0 ? *it1 - i : -(*it1 - i)),
          t2 = (*it2 - i > 0 ? *it2 - i : -(*it2 - i)),
          t3 = (*it3 - i > 0 ? *it3 - i : -(*it3 - i));
      ans += min(t1, min(t2, t3));
    }
    mans = min(mans, ans);
  }
  cout << mans << endl;
}
}  // namespace Work
int main() {
  Work::Work();
  return 0;
}
