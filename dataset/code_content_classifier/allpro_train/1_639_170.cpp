#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    s.push_back('?');
  }
  int out = -1;
  for (int i = s.size() / 2; i >= 0; --i) {
    for (int j = 0; 2 * i + j <= s.size(); ++j) {
      bool mark = 1;
      for (int k = 0; k < i; ++k) {
        if (s[k + j] == s[k + i + j] || s[k + j] == '?' ||
            s[k + i + j] == '?') {
          continue;
        } else {
          mark = 0;
          break;
        }
      }
      if (mark) {
        out = 2 * i;
        break;
      }
    }
    if (out != -1) {
      break;
    }
  }
  cout << out << "\n";
  return 0;
}
