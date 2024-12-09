#include <bits/stdc++.h>
using namespace std;
int abs(int a) {
  if (a > 0) return a;
  return -a;
}
int main() {
  string s, t;
  cin >> s >> t;
  vector<pair<int, int> > result;
  vector<int> sc(26, 0);
  vector<int> tc(26, 0);
  for (int i = 0; i < s.size(); i++) {
    sc[s[i] - 'a'] += 1;
  }
  for (int i = 0; i < t.size(); i++) {
    tc[t[i] - 'a'] += 1;
  }
  int rep = 0;
  int maxi = 0;
  for (int i = 0; i < 26; i++) {
    if (tc[i] != 0) {
      if (sc[i] == 0) {
        cout << "-1";
        return 0;
      }
    }
  }
  map<int, vector<int> > m;
  for (int i = 0; i < s.size(); i++) {
    m[s[i] - 'a'].push_back(i);
  }
  int tt = 0;
  while (tt < t.size()) {
    int ll = -1, rl = -1;
    int curr = 0, maxi = -1, res = 0;
    for (int j = 0; j < m[t[tt] - 'a'].size(); j++) {
      curr = m[t[tt] - 'a'][j];
      int lr = 0, rr = 0;
      int ttt1 = tt + 1, ttt2 = tt + 1;
      int k1;
      for (k1 = curr - 1; k1 >= 0; k1--) {
        if (s[k1] == t[ttt1]) {
          ttt1 += 1;
          lr += 1;
        } else {
          break;
        }
      }
      k1 += 1;
      int k2;
      for (k2 = curr + 1; k2 < s.size(); k2++) {
        if (s[k2] == t[ttt2]) {
          ttt2 += 1;
          rr += 1;
        } else {
          break;
        }
      }
      k2 -= 1;
      int lll, lrl;
      if (lr > rr) {
        lll = curr;
        lrl = k1;
      } else {
        lll = curr;
        lrl = k2;
      }
      if (abs(lrl - lll) > maxi) {
        maxi = abs(lrl - lll);
        ll = lll;
        rl = lrl;
      }
    }
    tt += abs(rl - ll) + 1;
    result.push_back(make_pair(ll, rl));
  }
  cout << result.size() << '\n';
  for (int u = 0; u < result.size(); u++) {
    cout << result[u].first + 1 << ' ' << result[u].second + 1 << '\n';
  }
  return 0;
}
