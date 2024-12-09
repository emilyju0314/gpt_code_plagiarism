#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  while (cin >> str) {
    bool check = true;
    int flag = 97;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == flag)
        flag++;
      else if (str[i] > flag) {
        if (str[i] + 1 == flag)
          continue;
        else {
          check = false;
          break;
        }
      }
    }
    if (check)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
