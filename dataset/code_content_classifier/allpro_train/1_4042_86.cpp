#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  int waste;
  cin >> waste;
  string s, t;
  cin >> s >> t;
  string ss = s;
  string tt = t;
  sort(ss.begin(), ss.end());
  sort(tt.begin(), tt.end());
  if (ss != tt) {
    cout << -1;
    return 0;
  }
  int d = 1;
  int odd = 0;
  if (s.size() % 2 == 0) {
    odd = 1;
    d = 2;
    int i;
    for (i = 0; i < s.size(); i++) {
      if (t[s.size() / 2] == s[i]) {
        break;
      }
    }
    v.push_back(s.size() - i - 1);
    int n = s.size() - i - 1;
    s.insert(0, s, s.size() - n, n);
    reverse(s.begin(), s.begin() + n);
    s.resize(s.size() - n);
    int j;
    for (j = 0; j < s.size(); j++) {
      if (t[s.size() / 2 - 1] == s[j]) {
        break;
      }
    }
    v.push_back(s.size());
    n = s.size();
    s.insert(0, s, s.size() - n, n);
    reverse(s.begin(), s.begin() + n);
    s.resize(s.size() - n);
    v.push_back(j + 1);
    n = 1 + j;
    s.insert(0, s, s.size() - n, n);
    reverse(s.begin(), s.begin() + n);
    s.resize(s.size() - n);
    v.push_back(s.size() - j - 2);
    n = s.size() - j - 2;
    s.insert(0, s, s.size() - n, n);
    reverse(s.begin(), s.begin() + n);
    s.resize(s.size() - n);
  } else {
    d = 1;
    int i;
    for (i = 0; i < s.size(); i++) {
      if (t[s.size() / 2] == s[i]) {
        break;
      }
    }
    v.push_back(s.size() - i - 1);
    int n = s.size() - i - 1;
    s.insert(0, s, s.size() - n, n);
    reverse(s.begin(), s.begin() + n);
    s.resize(s.size() - n);
  }
  int index = 1;
  while (d < s.size()) {
    int i = 0;
    for (; i < s.size(); i++) {
      if (s[i] == t[t.size() / 2 + index]) {
        break;
      }
    }
    v.push_back(s.size() - i - 1);
    int n = s.size() - i - 1;
    s.insert(0, s, s.size() - n, n);
    reverse(s.begin(), s.begin() + n);
    s.resize(s.size() - n);
    v.push_back(s.size() - d);
    n = s.size() - d;
    s.insert(0, s, s.size() - n, n);
    reverse(s.begin(), s.begin() + n);
    s.resize(s.size() - n);
    v.push_back(d);
    n = d;
    s.insert(0, s, s.size() - n, n);
    reverse(s.begin(), s.begin() + n);
    s.resize(s.size() - n);
    int j = d + 1;
    for (; j < s.size(); j++) {
      if (s[j] == t[t.size() / 2 - odd - index]) {
        break;
      }
    }
    v.push_back(s.size() - j);
    n = s.size() - j;
    s.insert(0, s, s.size() - n, n);
    reverse(s.begin(), s.begin() + n);
    s.resize(s.size() - n);
    v.push_back(j - d - 1);
    n = j - d - 1;
    s.insert(0, s, s.size() - n, n);
    reverse(s.begin(), s.begin() + n);
    s.resize(s.size() - n);
    d += 2;
    index++;
  }
  if (s != t) {
    return -1;
  }
  cout << v.size() << '\n';
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
  return 0;
}
