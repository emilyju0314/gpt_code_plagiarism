#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000000000000000;
const long long sminf = 1000000000;
const long long nowinf = 998244353;
const double ebs = 0.00000001;
vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int kol_vo;
  cin >> kol_vo;
  vector<string> v(kol_vo);
  for (int c = 0; c < kol_vo; c++) cin >> v[c];
  vector<string> need(kol_vo);
  for (int c = 0; c < kol_vo; c++) cin >> need[c];
  string last = "";
  string last1 = "";
  vector<int> rr(3);
  vector<vector<int> > dop;
  map<int, pair<int, int> > m;
  for (int c = 0; c < kol_vo; c++) {
    int l = 0, r = v[c].size() - 1;
    while (l < v[c].size() && v[c][l] == need[c][l]) l++;
    while (r >= 0 && v[c][r] == need[c][r]) r--;
    if (l == v[c].size()) continue;
    if (last.size() >= 1) {
      int pos = 0;
      for (int i = l; i <= r; i++) {
        if (v[c][i] != last[pos]) {
          cout << "NO";
          return 0;
        }
        if (need[c][i] != last1[pos]) {
          cout << "NO";
          return 0;
        }
        pos++;
      }
      if (r - l + 1 != last.size()) {
        cout << "NO";
        return 0;
      }
    } else {
      for (int i = l; i <= r; i++) {
        last += v[c][i];
        last1 += need[c][i];
      }
    }
    rr[0] = c;
    rr[1] = l;
    rr[2] = r;
    m[c] = {l, r};
    dop.push_back(rr);
  }
  char f = '1', r = '1';
  for (int c = 0; c < dop.size(); c++) {
    dop[c][1]--;
    if (dop[c][1] < 0) break;
    if (f == '1') {
      f = v[dop[c][0]][dop[c][1]];
      r = need[dop[c][0]][dop[c][1]];
    } else {
      if (v[dop[c][0]][dop[c][1]] != f) break;
      if (r != need[dop[c][0]][dop[c][1]]) break;
    }
    if (c == dop.size() - 1) {
      last = f + last;
      last1 = r + last1;
      f = '1';
      r = '1';
      for (int i = 0; i < dop.size(); i++) m[dop[i][0]].first--;
      c = -1;
    }
  }
  f = '1', r = '1';
  for (int c = 0; c < dop.size(); c++) {
    dop[c][2]++;
    if (dop[c][2] == v[dop[c][0]].size()) break;
    if (f == '1') {
      f = v[dop[c][0]][dop[c][2]];
      r = need[dop[c][0]][dop[c][2]];
    } else {
      if (v[dop[c][0]][dop[c][2]] != f) break;
      if (r != need[dop[c][0]][dop[c][2]]) break;
    }
    if (c == dop.size() - 1) {
      last += f;
      last1 += r;
      f = '1';
      r = '1';
      m[dop[c][0]].second++;
      c = -1;
    }
  }
  for (int c = 0; c < kol_vo; c++) {
    if (v[c] == need[c]) {
      string now = last + "$" + v[c];
      vector<int> now2 = z_function(now);
      for (int i = 1; i < now2.size(); i++) {
        if (now2[i] >= last.size()) {
          cout << "NO";
          return 0;
        }
      }
    } else {
      string now = last + "$" + v[c];
      vector<int> now2 = z_function(now);
      for (int i = 1; i < now2.size(); i++) {
        if (now2[i] >= last.size()) {
          if (i - last.size() - 1 < m[c].first) {
            cout << "NO";
            return 0;
          }
        }
      }
    }
  }
  cout << "YES" << endl;
  cout << last << endl;
  cout << last1;
  return 0;
}
