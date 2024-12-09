#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
string f(string a) {
  int cnt = 0;
  string res = "";
  int pos = -1;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == '0') continue;
    pos = i;
    break;
  }
  if (pos == -1) {
    return "0";
  }
  if (a[pos] == '.') {
    res = "0";
  }
  int g = -1;
  for (int i = pos; i < a.size(); i++) {
    if (a[i] == '.') {
      g = i;
      break;
    }
    res += a[i];
  }
  if (g == -1) return res;
  string s = "";
  int h = -1;
  for (int i = a.size() - 1; i >= g + 1; i--) {
    if (a[i] == '0') continue;
    h = i;
    break;
  }
  if (h == -1) {
    return res;
  }
  for (int i = g + 1; i <= h; i++) {
    s += a[i];
  }
  return res + "." + s;
}
int main() {
  string s;
  cin >> s;
  string a = "", d = "";
  string ans = "";
  int pos = -1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '.') {
      pos = i;
      break;
    }
    a += s[i];
  }
  for (int i = pos + 1; i < s.size(); i++) {
    if (s[i] == 'e') {
      pos = i;
      break;
    }
    d += s[i];
  }
  int b = 0;
  for (int i = pos + 1; i < s.size(); i++) {
    b = b * 10 + s[i] - '0';
  }
  ans += a;
  int cnt = 0;
  for (int i = 0; i < b; i++) {
    if (cnt < d.size()) {
      ans += d[cnt++];
    } else {
      ans += "0";
    }
  }
  if (cnt < d.size()) {
    ans += ".";
    for (int i = cnt; i < d.size(); i++) {
      ans += d[i];
    }
  }
  ans = f(ans);
  cout << ans << endl;
}
