#include <bits/stdc++.h>
using namespace std;
bool isvow(char ch) {
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    return true;
  else
    return false;
}
int main() {
  int i;
  string s1, s2;
  cin >> s1 >> s2;
  if (s1.length() != s2.length())
    cout << "No";
  else {
    int l = s1.length();
    for (i = 0; i < l; i++) {
      if (isvow(s1[i]) == isvow(s2[i]))
        continue;
      else
        break;
    }
    if (i == l)
      cout << "Yes";
    else
      cout << "No";
  }
}
