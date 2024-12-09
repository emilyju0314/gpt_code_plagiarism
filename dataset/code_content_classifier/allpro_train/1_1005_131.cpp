#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int cnt = 1;
  int max = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s.at(i) == 'A' || s.at(i) == 'E' || s.at(i) == 'I' || s.at(i) == 'O' ||
        s.at(i) == 'U' || s.at(i) == 'Y') {
      if (cnt > max) {
        max = cnt;
      }
      cnt = 1;
    } else {
      cnt++;
    }
  }
  if (cnt > max) {
    max = cnt;
  }
  cout << max;
  return 0;
}
