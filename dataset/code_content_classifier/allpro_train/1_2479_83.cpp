#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n - 2; i++) {
    if (s[i] == 'o' && s[i + 1] == 'g' && s[i + 2] == 'o') {
      int j = i + 3;
      s[i] = '*';
      s[i + 1] = '*';
      s[i + 2] = '*';
      while (j < n - 1 && s[j] == 'g' && s[j + 1] == 'o') {
        s[j] = '*';
        s[j + 1] = '*';
        j += 2;
      }
      if (s[j - 1] == '*')
        s[j - 1] = '#';
      else
        s[i + 2] = '#';
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {
      while (i < n && s[i] != '#') i++;
      cout << "***";
    } else
      cout << s[i];
  }
}
