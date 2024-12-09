#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int sd = 0, sr = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (s[i] == 'D') {
      sd++;
      sr--;
      if (sr < 0) {
        s += "D";
      }
    } else {
      sr++;
      sd--;
      if (sd < 0) {
        s += "R";
      }
    }
  }
  cout << s[s.size() - 1];
}
