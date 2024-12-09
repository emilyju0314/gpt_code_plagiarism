#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.size(), start;
  for (int i = 0; i < n; i++) {
    if (s[i] != '/') {
      start = i;
      break;
    }
  }
  if (start == (n - 1) && s[n - 1] == '/') {
    cout << "/" << endl;
    return 0;
  }
  for (int i = 0; i < s.size() - 1;) {
    if (s[i] == s[i + 1] && s[i] == '/') {
      s.erase(i, 1);
    } else
      i++;
  }
  if (s[s.size() - 1] == '/' && s.size() != 1) s.erase(s.size() - 1, 1);
  cout << s << endl;
}
