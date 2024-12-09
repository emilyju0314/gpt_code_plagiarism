#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  cin >> c;
  string s;
  cin >> s;
  vector<string> v;
  int index, v_index, flag = 0;
  v.push_back("qwertyuiop");
  v.push_back("asdfghjkl;");
  v.push_back("zxcvbnm,./");
  for (int i = 0; i < s.length(); i++) {
    flag = 0;
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < v[j].length(); k++) {
        if (s[i] == v[j][k]) {
          v_index = j;
          index = k;
          flag = 1;
          break;
        }
      }
      if (flag == 1) break;
    }
    if (c == 'R')
      cout << v[v_index][index - 1];
    else
      cout << v[v_index][index + 1];
  }
  return 0;
}
