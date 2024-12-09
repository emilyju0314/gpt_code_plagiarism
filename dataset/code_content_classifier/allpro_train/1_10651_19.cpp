#include <bits/stdc++.h>
using namespace std;

vector<int> kmp(const string &s, const string &t) {
  vector<int> ta(t.size() + 1);
  {
    ta[0] = -1;
    int j = -1;
    for (int i = 0; i < t.size(); i++) {
      while (j >= 0 && t[i] != t[j]) j = ta[j];
      ta[i + 1] = ++j;
    }
  }
  vector<int> ret;
  int m = 0, i = 0, n = s.size();
  while (m + i < n) {
    if (t[i] == s[m + i]) {
      if (++i == (int) t.size()) {
        ret.push_back(m);
        m = m + i - ta[i];
        i = ta[i];
      }
    } else {
      m = m + i - ta[i];
      if (i > 0) i = ta[i];
    }
  }
  return ret;
}

int main() {
  string t, p;
  cin >> t >> p;
  auto r = kmp(t, p);
  for (int i = 0; i < r.size(); i++) {
    cout << r[i] << endl;
  }
  return 0;
}

