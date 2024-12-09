#include <bits/stdc++.h>
using namespace std;
function<void(void)> ____ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
};
const int MAXN = 1e5 + 7;
char s[MAXN];
int n;
void solve() {
  cin >> s + 1;
  n = strlen(s + 1);
  reverse(s + 1, s + 1 + n);
  bool havez = false;
  for (int i = 1; i <= n; i++)
    if (s[i] == '0') havez = true;
  int tot = 0;
  for (int i = 1; i <= n; i++) tot += s[i] - '0';
  while (n and s[n] == '0') n--;
  if (!n) {
    cout << 0 << endl;
    return;
  }
  if (tot % 3 == 0) {
    reverse(s + 1, s + 1 + n);
    cout << s + 1 << endl;
    return;
  } else if (tot % 3 == 2) {
    string ss(s + 1, s + 1 + n);
    string s1(""), s2 = s1;
    int pos = -1;
    for (int i = 0; i < n; i++)
      if ((ss[i] - '0') % 3 == 2) {
        pos = i;
        break;
      }
    if (pos != -1) {
      ss[pos] = 'a';
      string sb("");
      for (int i = 0; i < n; i++)
        if (isdigit(ss[i])) sb += ss[i];
      while (!sb.empty() and sb.back() == '0') sb.pop_back();
      s1 = sb;
    }
    ss = string(s + 1, s + 1 + n);
    int p1 = -1, p2 = -1;
    for (int i = 0; i < n; i++)
      if ((ss[i] - '0') % 3 == 1) {
        if (p1 == -1)
          p1 = i;
        else
          p2 = i;
        if (p2 != -1) break;
      }
    if (p2 != -1) {
      ss[p1] = ss[p2] = 'a';
      string sb("");
      for (int i = 0; i < n; i++)
        if (isdigit(ss[i])) sb += ss[i];
      while (!sb.empty() and sb.back() == '0') sb.pop_back();
      s2 = sb;
    }
    if (s1.empty() and s2.empty()) {
      if (havez)
        cout << "0" << endl;
      else
        cout << -1 << endl;
    } else {
      reverse(s1.begin(), s1.end());
      reverse(s2.begin(), s2.end());
      if (s1.length() > s2.length())
        cout << s1 << endl;
      else
        cout << s2 << endl;
    }
  } else {
    string ss(s + 1, s + 1 + n);
    string s1(""), s2 = s1;
    int pos = -1;
    for (int i = 0; i < n; i++)
      if ((ss[i] - '0') % 3 == 1) {
        pos = i;
        break;
      }
    if (pos != -1) {
      ss[pos] = 'q';
      string sb("");
      for (int i = 0; i < n; i++)
        if (isdigit(ss[i])) sb += ss[i];
      while (!sb.empty() and sb.back() == '0') sb.pop_back();
      s1 = sb;
    }
    ss = string(s + 1, s + 1 + n);
    int p1 = -1, p2 = -1;
    for (int i = 0; i < n; i++)
      if ((ss[i] - '0') % 3 == 2) {
        if (p1 == -1)
          p1 = i;
        else
          p2 = i;
        if (p2 != -1) break;
      }
    if (p2 != -1) {
      ss[p1] = ss[p2] = 'a';
      string sb("");
      for (int i = 0; i < n; i++)
        if (isdigit(ss[i])) sb += ss[i];
      while (!sb.empty() and sb.back() == '0') sb.pop_back();
      s2 = sb;
    }
    if (s1.empty() and s2.empty()) {
      if (havez)
        cout << "0" << endl;
      else
        cout << -1 << endl;
    } else {
      reverse(s1.begin(), s1.end());
      reverse(s2.begin(), s2.end());
      if (s1.length() > s2.length())
        cout << s1 << endl;
      else
        cout << s2 << endl;
    }
  }
}
int main() {
  solve();
  return 0;
}
