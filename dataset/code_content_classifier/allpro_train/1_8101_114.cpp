#include <bits/stdc++.h>
using namespace std;
void require(bool cond, const string& message = "Runtime error") {
  if (!cond) {
    cerr << message << endl;
    assert(false);
  }
}
void readData() {}
void solve() {
  int k, n, m, q;
  cin >> k >> n >> m >> q;
  vector<string> base(n);
  for (int i = 0; i < int(n); ++i) cin >> base[i];
  map<string, map<string, int> > arts;
  vector<string> names(m);
  for (int i = 0; i < int(m); ++i) {
    string name;
    cin >> name;
    name.erase(name.size() - 1, 1);
    names[i] = name;
    while (true) {
      string bn;
      cin >> bn;
      string c;
      cin >> c;
      bool br = true;
      if (c[c.size() - 1] == ',') {
        c.erase(c.size() - 1, 1);
        br = false;
      }
      istringstream is(c);
      int cnt;
      is >> cnt;
      arts[name][bn] = cnt;
      if (br) {
        break;
      }
    }
  }
  vector<map<string, int> > fa(k);
  vector<map<string, int> > ans(k);
  for (int it = 0; it < int(q); ++it) {
    int f;
    cin >> f;
    --f;
    string bn;
    cin >> bn;
    ++fa[f][bn];
    bool full = false;
    string an;
    for (int i = 0; i < int(m); ++i) {
      bool ok = true;
      const map<string, int>& a = arts[names[i]];
      for (map<string, int>::const_iterator iter = a.begin(); iter != a.end();
           ++iter) {
        if (fa[f][iter->first] < iter->second) {
          ok = false;
          break;
        }
      }
      if (ok) {
        an = names[i];
        full = true;
        break;
      }
    }
    if (full) {
      ++ans[f][an];
      const map<string, int>& a = arts[an];
      for (map<string, int>::const_iterator iter = a.begin(); iter != a.end();
           ++iter) {
        fa[f][iter->first] -= iter->second;
      }
    }
  }
  for (int i = 0; i < int(k); ++i) {
    for (map<string, int>::const_iterator it = fa[i].begin(); it != fa[i].end();
         ++it) {
      ans[i][it->first] += it->second;
    }
  }
  for (int i = 0; i < int(k); ++i) {
    int sz = 0;
    for (map<string, int>::const_iterator it = ans[i].begin();
         it != ans[i].end(); ++it) {
      if (it->second > 0) ++sz;
    }
    cout << sz << endl;
    for (map<string, int>::const_iterator it = ans[i].begin();
         it != ans[i].end(); ++it) {
      if (it->second > 0) cout << it->first << " " << it->second << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  readData();
  solve();
  return 0;
}
