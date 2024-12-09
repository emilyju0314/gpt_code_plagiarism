#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
string s, t;
bool flag[26];
int ls, n, lt;
int main() {
  cin >> s;
  ls = s.size();
  for (int i = 0; i < ls; ++i) flag[s[i] - 'a'] = true;
  cin >> t >> n;
  bool f = false;
  lt = t.size();
  int st = lt;
  for (int i = 0; i < lt; ++i)
    if (t[i] == '*') {
      f = true;
      st = i;
      break;
    }
  for (int i = 0; i < n; ++i) {
    cin >> s;
    ls = s.size();
    if (ls < lt - 1 || st == lt && ls != lt) {
      cout << "NO" << endl;
      continue;
    }
    bool ok = true;
    for (int j = 0; j < st; ++j)
      if (t[j] == '?') {
        if (!flag[s[j] - 'a']) {
          ok = false;
          break;
        }
      } else if (s[j] != t[j]) {
        ok = false;
        break;
      }
    if (!ok) {
      cout << "NO" << endl;
      continue;
    }
    int ll = ls - lt + 1;
    for (int j = st; j < st + ll; ++j)
      if (flag[s[j] - 'a']) {
        ok = false;
        break;
      }
    if (!ok) {
      cout << "NO" << endl;
      continue;
    }
    for (int j = st + ll; j < ls; ++j)
      if (t[j - ll + 1] == '?') {
        if (!flag[s[j] - 'a']) {
          ok = false;
          break;
        }
      } else if (t[j - ll + 1] != s[j]) {
        ok = false;
        break;
      }
    if (ok)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
