#include <bits/stdc++.h>
using namespace std;
int n, p;
int main() {
  string s;
  cin >> n >> p;
  cin >> s;
  char limitChar = 'a' + p;
  int i = s.length() - 1;
  bool flag = true;
  while (flag && i >= 0) {
    s[i]++;
    if (s[i] == limitChar) {
      s[i] = 'a' - 1;
      --i;
      continue;
    }
    if (i > 0 && (s[i - 1] == s[i])) {
      continue;
    }
    if (i > 1 && (s[i - 2] == s[i])) {
      continue;
    }
    if (i < n) {
      ++i;
    }
    if (i == n) {
      flag = false;
    }
  }
  if (flag) {
    cout << "NO\n";
  } else {
    cout << s << endl;
  }
  return 0;
}
