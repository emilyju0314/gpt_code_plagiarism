#include <bits/stdc++.h>
using namespace std;
int fun(string i) {
  int t = i.length();
  if (i[0] == '0') {
    if (i[t - 1] == '0') {
      return 0;
    } else {
      return 1;
    }
  } else {
    if (i[t - 1] == '0') {
      return 2;
    } else {
      return 3;
    }
  }
}
void f(vector<int> v, int t) {
  if (v.size() < t) {
    cout << "-1";
    return;
  }
  cout << t << "\n";
  for (int i = 0; i < t; i++) {
    cout << v[i] << " ";
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> c(4);
    vector<string> v(n);
    for (auto &i : v) {
      cin >> i;
      c[fun(i)]++;
    }
    set<string> se;
    for (const auto &i : v) {
      se.insert(i);
    }
    vector<int> ve[4];
    for (int i = 0; i < v.size(); i++) {
      string s = v[i];
      string t;
      for (int j = (int)s.length() - 1; j >= 0; j--) {
        t.push_back(s[j]);
      }
      if (se.find(t) == se.end()) {
        ve[fun(s)].push_back(i + 1);
      }
    }
    if (c[0] && c[3] && !c[1] && !c[2]) {
      cout << -1;
    } else if (abs(c[1] - c[2]) <= 1) {
      cout << 0;
    } else if (c[1] > c[2]) {
      f(ve[1], (c[1] - c[2]) / 2);
    } else {
      f(ve[2], (c[2] - c[1]) / 2);
    }
    cout << "\n";
  }
}
