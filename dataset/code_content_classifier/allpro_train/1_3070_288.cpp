#include <bits/stdc++.h>
using namespace std;
bool isp(string s) {
  int l = 0;
  int r = s.length() - 1;
  while (l <= r) {
    if (s[l] != s[r]) return false;
    l++;
    r--;
  }
  return true;
}
string f(string a, string b) {
  string t = "";
  for (int i = 0; i < 26; i++) {
    t = a;
    t += (char)(i + 'a');
    t += b;
    if (isp(t) == true) {
      return t;
    }
  }
  return "";
}
int main() {
  string s;
  cin >> s;
  int n = s.size();
  string g = f("", s);
  if (g.size() > 0) {
    cout << g << "\n";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    string a = s.substr(0, i + 1);
    string b = s.substr(i + 1, n - i - 1);
    string t = f(a, b);
    if (t.size() > 0) {
      cout << t << "\n";
      return 0;
    }
  }
  cout << "NA\n";
  return 0;
}
