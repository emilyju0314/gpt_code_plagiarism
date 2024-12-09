#include <bits/stdc++.h>
using namespace std;
const long long N = 100009;
vector<pair<int, int> > tmp;
set<pair<int, int> > myset;
int n, m;
long long ok[409][409], run;
string s, t;
void IO() {
  int test;
  cin >> test;
  while (test--) {
    cin >> s;
    n = s.size();
    s = '#' + s;
    cin >> t;
    m = t.size();
    t = '#' + t;
    run = 0;
    memset(ok, 0, sizeof(ok));
    int done = 0;
    for (int ss = 1; ss <= m; ++ss) {
      for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= m; ++j) ok[i][j] = 0;
      myset.clear();
      myset.insert(make_pair(0, 1));
      myset.insert(make_pair(1, 0));
      int nn = m - ss;
      ++run;
      ok[0][0] = run;
      for (int i = 1; i <= n; ++i) {
        tmp.clear();
        for (auto x : myset) {
          int j = x.first, k = x.second;
          if (j > 0 && ok[j - 1][k] == run && s[i] == t[j] ||
              k > 0 && ok[j][k - 1] == run && s[i] == t[ss + k])
            ok[j][k] = run, tmp.push_back(make_pair(j, k));
        }
        for (auto x : tmp) {
          myset.erase(x);
          if (x.first + 1 <= ss) myset.insert(make_pair(x.first + 1, x.second));
          if (x.second + 1 <= nn)
            myset.insert(make_pair(x.first, x.second + 1));
        }
      }
      if (ok[ss][nn] == run) {
        done = 1;
        break;
      }
    }
    if (done)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
int main() {
  IO();
  return 0;
}
